#!/bin/bash
set -e

# Get the directory of the current script
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# Check if the script is being run with sudo
if [ "$EUID" -ne 0 ]; then
  echo "Please run this script with sudo."
  exit
fi

# Check if igmpproxy is installed
command -v igmpproxy >/dev/null 2>&1 || { echo >&2 "igmpproxy is required but it's not installed. Aborting."; exit 1; }

# Check if docker is installed
command -v docker >/dev/null 2>&1 || { echo >&2 "docker is required but it's not installed. Aborting."; exit 1; }

# Check if docker-compose is installed
command -v docker-compose >/dev/null 2>&1 || { echo >&2 "docker-compose is required but it's not installed. Aborting."; exit 1; }

echo "Running application..."

# Get a list of available network interfaces
INTERFACES=()
while IFS= read -r line; do
  INTERFACES+=("$line")
done < <(ip link show up | awk -F': ' '/^[0-9]+: /{print $2}' | sed 's/@.*$//')

# Prompt user to select a network interface
echo "Select a network interface for igmpproxy:"
for idx in "${!INTERFACES[@]}"; do
  echo "$((idx+1)). ${INTERFACES[$idx]}"
done
read -rp "Enter the number: " INTERFACE_INDEX

# Validate the user input
if ! [[ "$INTERFACE_INDEX" =~ ^[0-9]+$ ]] || ((INTERFACE_INDEX < 1)) || ((INTERFACE_INDEX > ${#INTERFACES[@]})); then
  echo "Invalid selection. Aborting."
  exit 1
fi

# Get the selected network interface
SELECTED_INTERFACE="${INTERFACES[$((INTERFACE_INDEX-1))]}"

echo "Launching igmpproxy multicast bridge for interface: $SELECTED_INTERFACE"
echo "Configuration:"
igmpproxy_config=$(cat << EOF
quickleave
phyint $SELECTED_INTERFACE upstream ratelimit 0 threshold 1
altnet 0.0.0.0/0
phyint docker0 downstream ratelimit 0 threshold 1
EOF
)
echo "$igmpproxy_config"  # Output the configuration to confirm

# Save the igmpproxy configuration to a file
echo "$igmpproxy_config" > "$SCRIPT_DIR/igmpproxy.conf"

# Start igmpproxy with configuration in the background
nohup igmpproxy "$SCRIPT_DIR/igmpproxy.conf" > /dev/null 2>&1 &

echo "Launching docker containers..."
# Run docker-compose up, using the relative path
docker-compose -f "$SCRIPT_DIR/docker-compose.yaml" up -d
