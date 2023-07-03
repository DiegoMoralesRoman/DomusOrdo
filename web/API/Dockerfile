FROM alpine

# Install dependencies
RUN apk update

RUN apk add       \
   python3        \
   py3-flask      \
   py3-sqlalchemy \
   py3-waitress   

RUN apk add py3-pip
RUN pip install      \
   flask_sqlalchemy

# Copy neccessary files
COPY . /src
# Run
WORKDIR /src
ENTRYPOINT ["waitress-serve", "--port", "8080", "--call", "app:create_app"]
