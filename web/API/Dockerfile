FROM alpine

# Copy neccessary files
COPY . /src

# Install dependencies
RUN apk update

RUN apk add    \
   python3     \
   py3-flask   \
   py3-waitress

# Run
WORKDIR /src
ENTRYPOINT ["waitress-serve", "--call", "'flaskr:create_app'"]
