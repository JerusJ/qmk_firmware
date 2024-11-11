#!/usr/bin/env bash

set -eoux

qmk compile -kb keychron/q0/plus -km jerus
# qmk compile -kb ducky/one2sf/1967st -km jerus
# qmk compile -kb keychron/q8/ansi_encoder -km jerus

rsync -av --delete ./.build/ /mnt/hgfs/Shared_VM_Folder/QMK_BUILD
