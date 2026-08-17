#!/bin/bash

# go to the script directory
aPackedRoot=${BASH_SOURCE%/*}; if [ -d "${aPackedRoot}" ]; then cd "$aPackedRoot"; fi; aPackedRoot="$PWD";

anUnpacked=$aPackedRoot/build
rm   -rf $anUnpacked/*
mkdir -p $anUnpacked

# define name of the archives
SVIEW_NDK=android-ndk-r12b
SVIEW_FFMPEG=ffmpeg-4.1.4-android-lgpl
SVIEW_FREETYPE=freetype-2.6.3-android
SVIEW_OPENAL=openal-soft-1.17.2-arm7
SVIEW_LIBCONFIG=libconfig-1.4.9-arm7
SVIEW_PLATFORM=android-26.jar
SVIEW_BUILD_TOOLS=android-build-tools-26.0.3

# unpack archives as .tar.bz2
echo Unpacking 3rdparty...
#echo === unpacking Android NDK ===
tar xf $aPackedRoot/$SVIEW_NDK.tar.bz2       -C $anUnpacked
#echo === unpacking FFmpeg ===
tar xf $aPackedRoot/$SVIEW_FFMPEG.tar.bz2    -C $anUnpacked
#echo === unpacking FreeType ===
tar xf $aPackedRoot/$SVIEW_FREETYPE.tar.bz2  -C $anUnpacked
#echo === unpacking OpenAL ===
tar xf $aPackedRoot/$SVIEW_OPENAL.tar.bz2    -C $anUnpacked
#echo === unpacking libconfig ===
tar xf $aPackedRoot/$SVIEW_LIBCONFIG.tar.bz2 -C $anUnpacked
#echo === unpacking Android SDK platform JAR ===
tar xf $aPackedRoot/$SVIEW_PLATFORM.tar.bz2  -C $anUnpacked
#echo === unpacking Android SDK build tools ===
tar xf $aPackedRoot/$SVIEW_BUILD_TOOLS.tar.bz2 -C $anUnpacked
echo Unpacking finished

export SVIEW_NDK=$anUnpacked/$SVIEW_NDK
export SVIEW_FFMPEG=$anUnpacked/$SVIEW_FFMPEG
export SVIEW_FREETYPE=$anUnpacked/$SVIEW_FREETYPE
export SVIEW_OPENAL=$anUnpacked/$SVIEW_OPENAL
export SVIEW_LIBCONFIG=$anUnpacked/$SVIEW_LIBCONFIG
export SVIEW_PLATFORM=$anUnpacked/$SVIEW_PLATFORM
export SVIEW_BUILD_TOOLS=$anUnpacked/$SVIEW_BUILD_TOOLS
