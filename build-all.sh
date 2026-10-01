#!/usr/bin/env bash
set -euo pipefail

export PICO_SDK_PATH="${PICO_SDK_PATH:-$HOME/.pico-sdk}"

build_pico() {
    local board_name="$1"
    local build_dir="build-$board_name"

    echo -e "\n=== Building for $board_name ==="

    mkdir -p "$build_dir"

    pushd "$build_dir" > /dev/null

    export PICO_BOARD="$board_name"

    cmake -G Ninja ..
    ninja

    popd > /dev/null
}

build_pico "pico"
build_pico "pico2"
