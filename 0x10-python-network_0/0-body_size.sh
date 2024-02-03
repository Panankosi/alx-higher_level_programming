#!/bin/bash

# Check if the URL is provided as an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <URL>"
  exit 1
fi

# Get the size of the response body in bytes
response_size=$(curl -sI "$1" | grep -i content-length | awk '{print $2}' | tr -d '\r')

# Check if the response size is available
if [ -z "$response_size" ]; then
  echo "Unable to retrieve the response size."
  exit 1
fi

echo "Size of the response body: ${response_size} bytes"
