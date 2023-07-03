FROM alpine

# Install dependencies
RUN apk update
RUN apk add \
   nodejs   \
   npm      

RUN npm install -g serve

# Copy application
COPY . /src

# Build application
WORKDIR /src
RUN npm install
RUN npm run build

# Launch application
ENTRYPOINT ["serve", "-l", "80", "-s", "build"]
