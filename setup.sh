#!/bin/bash

set -e

echo "Updating package lists..."
sudo apt update

echo "Installing Qt6 development packages and tools..."
sudo apt install -y \
  qt6-base-dev \
  qt6-tools-dev \
  qt6-tools-dev-tools \
  qt6-l10n-tools \
  qt6-base-dev-tools \
  qt6-declarative-dev \
  qt6-multimedia-dev \
  qt6-svg-dev \
  qt6-tools-tools \
  qmake6 \
  bison \
  flex \
  build-essential \
  cmake \
  git

echo "Ensuring qmake6 is available via 'qmake' (optional)..."
if ! command -v qmake >/dev/null && command -v qmake6 >/dev/null; then
    echo "Creating symbolic link: /usr/local/bin/qmake -> qmake6"
    sudo ln -s $(command -v qmake6) /usr/local/bin/qmake
fi

echo "Environment setup complete."
