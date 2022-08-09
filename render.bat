cd images2

ffmpeg -framerate 10 -i image_%%d.ppm -vcodec mpeg4 -r 30 -b:v 8000k output100.mp4

del *.ppm

.\output100.mp4

cd ..