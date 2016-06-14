#!/bin/bash
#
#Script pour lancer l'audio
echo "stream audio"

arecord -D plughw:1,0 -d 0 |cvlc -vvv stream:///dev/stdin --sout '#transcode{vcodec=none,acodec=mp3,ab=128,channels=2,sampelrate=44100}:http{mux=mp3,dst=:8090/}'
