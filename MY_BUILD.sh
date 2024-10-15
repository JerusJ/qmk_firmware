#!/usr/bin/env bash

set -eoux

qmk compile -kb keychron/q8/ansi_encoder -km jerus

rsync -av --delete ./.build/ /mnt/hgfs/Shared_VM_Folder/QMK_BUILD
