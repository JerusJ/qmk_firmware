#!/usr/bin/env bash

set -eoux

# qmk compile -kb keychron/q0_max/encoder -km default
# qmk compile -kb keychron/q0_max/encoder -km via
qmk compile -kb keychron/q0_max/encoder -km jerus

rsync -av --delete ./.build/ /mnt/hgfs/Shared_VM_Folder/QMK_BUILD
