#!/bin/bash
# This script automatically updates the Appboy SDK. This script assumes that you are
# in the parent folder of AppboyRelease and that the folder is named AppboyRelease.

# Remove the existing AppboyRelease folder and download the new one 
rm -rf AppboyRelease
wget https://s3.amazonaws.com/appboy-sdk/ios/AppboyRelease.tar.gz
tar -xzvf AppboyRelease.tar.gz

# Clean and build the project
xcodebuild -configuration Debug -sdk iphonesimulator clean
xcodebuild -configuration Debug -sdk iphonesimulator build

# Remove the archive file
rm -f AppboyRelease.tar.gz
