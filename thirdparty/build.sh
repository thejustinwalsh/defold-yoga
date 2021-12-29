#!/bin/bash

# macOS x86_64
rm -rf build/macos
mkdir -p build/macos
pushd build/macos
cmake ../.. -G Xcode -DCMAKE_TOOLCHAIN_FILE=./ios.toolchain.cmake -DPLATFORM=MAC 
cmake --build . --config Release
mkdir -p ../../../yoga/lib/x86_64-osx
cp Release/libyogacore.a ../../../yoga/lib/x86_64-osx/libyogacore.a
popd

# iOS arm64
rm -rf build/ios
mkdir -p build/ios
pushd build/ios
cmake ../.. -G Xcode -DCMAKE_TOOLCHAIN_FILE=./ios.toolchain.cmake -DPLATFORM=OS64 -DENABLE_BITCODE=0
cmake --build . --config Release
mkdir -p ../../../yoga/lib/arm64-ios
cp Release-iphoneos/libyogacore.a ../../../yoga/lib/arm64-ios/libyogacore.a
popd

# web
rm -rf build/web
mkdir -p build/web
pushd build/web
emcmake cmake ../..
make
mkdir -p ../../../yoga/lib/web
cp libyogacore.a ../../../yoga/lib/web/libyogacore.a
popd

rm -rf ../yoga/include
mkdir -p ../yoga/include
cp yoga/yoga/*.h ../yoga/include
