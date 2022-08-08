#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>

using namespace std;


    void pic(string path, int height, int width, int** arr) {
        //string path = "C:\\Users\\willh\\CLionProjects\\game\\image.ppm";
        ofstream image;
        image.open(path);
        if (image.is_open()){
            //place header info
            image << "P3" << endl;
            image << "250 250"<< endl;
            image << "255" <<endl;

            for(int y=0; y<250; y++){
                for (int x = 0; x<250; x++){
                    if(arr[y][x] == 1){image<<255<<" " << 0<< " "<<0<<endl;}
                    else {image<<0<<" " << 0<< " "<<0<<endl;}
                }
            }
        }
        image.close();
    }

   /* int main(){
        srand(time(0));

        int** pc = new int*[250*250];   //allocated memory

        for (int i=0; i<250; i++){
            pc[i] = new int[250];
        }
        for (int i=0; i<250; i++) {
            for (int j = 0; j < 250; j++) {
                int rans = rand() % 255;
                std::cout<<rans<<endl;
                if (rans % 2 == 0){
                    pc[i][j] = 1;}//j+(i*10);}
                else {pc[i][j] = 0;}
            }
        }

        string path = "C:\\Users\\willh\\CLionProjects\\game\\image6.ppm";
        string image2 = "image4";
        pic(path, 255, 255,  image2, pc );
    }

*/
