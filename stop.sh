#!/bin/bash
# set -e

# Get the directory of the current script
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# Check if the script is being run with sudo
if [ "$EUID" -ne 0 ]
  then echo "Please run this script with sudo."
  exit
fi

# Check if docker is installed
command -v docker >/dev/null 2>&1 || { echo >&2 "docker is required but it's not installed. Aborting."; exit 1; }

# Check if docker-compose is installed
command -v docker-compose >/dev/null 2>&1 || { echo >&2 "docker-compose is required but it's not installed. Aborting."; exit 1; }

# Check if the application is running
if ! docker-compose -f "$SCRIPT_DIR/docker-compose.yaml" ps; then
  echo "The application is not running. Nothing to stop."
  exit 1
fi

# Find the igmpproxy process and stop it
IGMPPROXY_PID=$(pgrep igmpproxy)
if [ -z "$IGMPPROXY_PID" ]; then
  echo "igmpproxy is not running. Nothing to stop."
else
   echo "Stopping igmpproxy"
   kill -TERM "$IGMPPROXY_PID"
fi

# Stop the Docker containers
echo "Stopping containers..."
docker-compose -f "$SCRIPT_DIR/docker-compose.yaml" down
