#!/bin/bash
# This script automatically updates the Appboy SDK.

# Remove the existing AppboyRelease folder and download the new one 
rm -rf AppboyRelease
wget https://s3.amazonaws.com/appboy-sdk/ios/AppboyRelease.tar.gz
tar -xzvf AppboyRelease.tar.gz

# Clean and build the project
xcodebuild -configuration Debug -sdk iphonesimulator clean
xcodebuild -configuration Debug -sdk iphonesimulator build
rm -f AppboyRelease.tar.gz
