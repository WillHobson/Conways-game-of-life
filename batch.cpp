//
// Created by willh on 08/08/2022.
//
#include <cstdlib>
void render()
{
    std::system("render.bat");
}
//ffmpeg -framerate 10 -i image_%d.ppm -vcodec mpeg4 -r 30 -b:v 8000k output100.mp4
