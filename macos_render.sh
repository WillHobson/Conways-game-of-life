#!/bin/bash

ffmpeg -framerate 10 -i image_%d.ppm -vcodec mpeg4 -r 30 -b:v 8000k output100.mp4

rm *.ppm

open -a "quicktime player" output100.mp4

