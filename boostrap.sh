#!/bin/bash
echo "Bootstraping dev environment..."
CUR=$(pwd)
TMP=$(mktemp -d 2>/dev/null || mktemp -d -t 'mytmpdir')
pushd $TMP > /dev/null
curl -s https://d.defold.com/archive/stable/d31d6397a72178541a5ef6e7ef2bed090d828f58/engine/defoldsdk.zip --output defoldsdk.zip
unzip -q defoldsdk.zip
mkdir -p $CUR/yoga/include/dmsdk
yes | \cp -rf defoldsdk/sdk/include/dmsdk $CUR/yoga/include/
popd > /dev/null
rm -rf $TMP