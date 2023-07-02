FROM alpine

# Copy application
COPY . /src

# Install dependencies
RUN apk update
RUN apk add \
   nodejs   \
   npm      

RUN npm install -g serve

# Build application
WORKDIR /src
RUN npm install
RUN npm run build

# Launch application
ENTRYPOINT ["serve", "-l", "80", "-s", "build"]
