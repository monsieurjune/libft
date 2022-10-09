#!/bin/bash

rm -f ~/Send/gnl/*.c ~/Send/gnl/*.h
cp -R ~/Cadet/get_next_line/ ~/Send/gnl/srcs
mv ~/Send/gnl/srcs/* ~/Send/gnl/
rm -rf ~/Send/gnl/srcs ~/Send/gnl/move.sh
rm -rf ~/Send/gnl/gnl1 ~/Send/gnl/gnl2
