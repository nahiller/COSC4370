#include <iostream>
#include "BMP.h"
#include <cmath>
using namespace std;
int main() {

    BMP bmpNew(1000,1000,false);
    bmpNew.fill_region(0, 0, 1000, 1000, 0, 0, 0, 0);
    for(int x=0;x<769;x++) //bmpNew.bmp_info_header.width
    {
        int yLevel=0;
        yLevel=4096-(((x)/12)*((x)/12));
        yLevel=sqrt(yLevel);
        yLevel*=6;
        yLevel+=384;
        cout<<yLevel<<endl;
        int distance=yLevel-384;
        distance*=2;
        bmpNew.set_pixel(x, yLevel, 255, 255, 255, 0);
        bmpNew.set_pixel(x, yLevel-distance, 255, 255, 255, 0);
    }
    bmpNew.write("output.bmp");


}
