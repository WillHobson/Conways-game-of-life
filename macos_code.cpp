//
// Created by Will Hobson on 16/08/2022.
//
#include "iostream"
#include "functions.cpp"
#include "getpath.cpp"


using namespace std;


int main(){
    int count = 0; //variable to keep count of generations.
    //srand(time(0));
    int** a2d = new int*[W*H];//allocated memory


    for (int i=0; i<W; i++){         //setting up a2d array
        a2d[i] = new int[H];
    }



    for (int i=0; i<H; i++) {
        for (int j = 0; j < W; j++) {
            int ran = rand() % 500;
            if (ran % 7 == 0){a2d[i][j] = 1;}
            else{
                a2d[i][j] = 0;}}}



    while(count<1000) {
        int** b2d = new int*[W*H];
        for (int i=0; i<W; i++){            //setting up b2d array
            b2d[i] = new int[H];
        }
        for (int i=0; i<H; i++) {
            for (int j = 0; j < W; j++) {
                b2d[i][j] = 0;}}
        //string path = getpath()  + "image_" + to_string(count) + ".ppm";
        //std::cout<<"path = "<< path;
        string path = "/Users/willhob/ClionProjects/untitled/image_"+ std::to_string(count) + ".ppm";

        pic(path, H, W, a2d);

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int res = status(i, j, a2d);
                int des = decsion(res, a2d[j][i]);
                b2d[j][i] = des;
            }
        }
        if (a2d == b2d) { count = 40;  pic(path, H, W, a2d);}


        for (int i=0; i<H; i++){
            std::swap(a2d[i], b2d[i]);
        }
        count++;


        //delete b2d
        for (int i = 0; i < W; i++) {
            delete[] b2d[i];
        }
        delete[] b2d;
    }
    render();
}
