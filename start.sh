#!/bin/bash

# Currently the script supports only the macOS and Windows
# i.e. if OS type is not darwin (macOS), then we directly assume windows otherwise
if [[ $OSTYPE == "darwin"* ]]; then
        open build/Takar.xcodeproj
else
        start build/Takar.sln
fi