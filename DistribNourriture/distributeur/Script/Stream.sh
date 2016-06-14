#!/bin/sh
#
#Script stream video
echo "Stream actif"
raspivid -o - -t 0   -w 1280 -h 720 -fps 25 -b 5000000 | cvlc -vvv stream:///dev/stdin --sout '#http{mux=ts,dst=:8090}' :demux=h264
