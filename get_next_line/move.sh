#!/bin/bash

rm -f ~/Send/gnl/*.c ~/Send/gnl/*.h
cp -R ~/Cadet/gnl/ ~/Send/gnl/srcs
mv ~/Send/gnl/* ~/Send/gnl/
rm -rf ~/Send/gnl/srcs ~/Send/gnl/move.sh
