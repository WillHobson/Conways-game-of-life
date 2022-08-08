//
// Created by willh on 18/05/2022.
//
#include "iostream"
#include "picture.cpp"
#include <ctime>
#include <cstdio>

using namespace std;

const int W = 250;
const int H = 250;


void print_array(int** array, int h, int w);
int status(int x, int y, int **arr);
int decsion(int res, int current);

int main(){
    int count = 0; //variable to keep count of generations.
    srand(time(0));
    int** a2d = new int*[W*H];//allocated memory


    for (int i=0; i<W; i++){         //setting up a2d array
        a2d[i] = new int[H];
    }



    for (int i=0; i<H; i++) {
        for (int j = 0; j < W; j++) {
            int ran = rand() % 500;
            if (ran % 171 == 0){a2d[i][j] = 1;}
            else {a2d[i][j] = 0;}
        }
    }
    while(count<10) {
        int** b2d = new int*[W*H];
        for (int i=0; i<W; i++){            //setting up b2d array
            b2d[i] = new int[H];
        }
        string path = "C:\\Users\\willh\\CLionProjects\\game\\image_" + to_string(count) + ".ppm";

        pic(path, H, W, a2d);

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int res = status(i, j, a2d);
                int des = decsion(res, a2d[i][j]);
                b2d[i][j] = des;
            }
        }
        //if (a2d == b2d) { count = 5;  pic(path, H, W, a2d);}
        //else {
            a2d = b2d;
            count++;
        //}

        //delete b2d
        for (int i = 0; i < 250; i++) {
            delete[] b2d[i];
        }
        delete[] b2d;
    }

    }


void print_array(int** array, int h, int w){
    for(int i = 0; i<h; i++) {
        std::cout<<"\n";
        for (int j = 0; j < w; j++) {
            std::cout << array[i][j] << ", ";
        }}
}

int status(int x, int y, int **arr){
    int alive = 0;
    //check left
    if (x>0 && (arr[y][x-1] == 1)){ alive += 1;}

    //check right
    if (x < W &&(arr[y][x+1] == 1)){alive+=1;}

    //check top
    if (y>0 && arr[y-1][x]==1){alive+=1;}

    //check bottom
    if (y<H-1 && arr[y+1][x]==1){alive+=1;}

    //check top right
    if(x<W && y>0 && arr[y-1][x+1] ==1){alive+=1;}

    //check bottom right
    if (x<W && y<H-1 && arr[y+1][x+1]==1){alive+=1;}

    //check bottom left
    if(x>0 && y<H-1 && arr[y+1][x-1]==1){alive+=1;}

    //check top left
    if(x>0 && y>0 && arr[y-1][x-1]==1){alive+=1;}

    return alive;
}

int decsion(int res, int current){
    int newv;
    if (current == 1){
        if (res <2){newv = 0;}
        if (res==2 || res==3){newv = 1;}
        if (res >3){newv = 0;}
    }
    if (current ==0 && (res == 3)){newv=1;}

    return newv;
}