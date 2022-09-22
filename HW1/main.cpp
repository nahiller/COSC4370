#include <iostream>
#include "BMP.h"
#include <cmath>
using namespace std;
int main() {

    BMP bmpNew(1000,1000,false);
    bmpNew.fill_region(0, 0, 1000, 1000, 0, 0, 0, 0);
    for(float x=0.001;x<769.0;x++) //bmpNew.bmp_info_header.width
    {
        float yLevel=0.00;
        yLevel=4096.0-(((x)/12.0)*((x)/12.0));
        yLevel=sqrt(yLevel);
        yLevel*=6.0;
        yLevel+=384.0;
        cout<<yLevel<<endl;
        float distance=yLevel-384.0;
        distance*=2.00;
        bmpNew.set_pixel(x, yLevel, 255, 255, 255, 0);
        bmpNew.set_pixel(x, yLevel-distance, 255, 255, 255, 0);
    }
    for(float y=0.001; y<770; y++){
        float xLevel=0.00;
        xLevel=4096-(((y-385)/6.0)*((y-385)/6));
        xLevel=sqrt(xLevel);
        xLevel*=12;
        bmpNew.set_pixel(xLevel,y,255,255,255,0);
    }
    bmpNew.write("output.bmp");


}
