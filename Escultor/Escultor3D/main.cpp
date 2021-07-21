#include <iostream>
#include "sculptor.h"

using namespace std;

int main() {
    Sculptor sculptor(10, 10, 10);
    //Axis
    sculptor.setColor(0, 0, 0, 1); //black
    sculptor.putVoxel(0, 0, 0); //0,0,0
    sculptor.setColor(1, 0, 0, 1); //red
    sculptor.putBox(1, 9, 0, 0, 0, 0); //x-axis
    sculptor.setColor(0, 1, 0, 1); //green
    sculptor.putBox(0, 0, 1, 9, 0, 0); //y-axis
    sculptor.setColor(0, 0, 1, 1); //blue
    sculptor.putBox(0, 0, 0, 0, 1, 9); //z-axis
    sculptor.setColor(0, 1, 1, 1); //cyan
    sculptor.putVoxel(0, 9, 9); //yz
    sculptor.setColor(1, 1, 0, 1); //yellow
    sculptor.putVoxel(9, 9, 0); //xy
    sculptor.setColor(1, 0, 1, 1); //magenta
    sculptor.putVoxel(9, 0, 9); //xz
    sculptor.setColor(1, 1, 1, 1); //white
    sculptor.putVoxel(9, 9, 9); //xyz
    //Spheres
    sculptor.setColor(0.98, 0.41, 0.05, 0.3); //Ecstasy
    sculptor.putSphere(5, 5, 5, 3); //
    sculptor.cutSphere(6, 6, 6, 2); //
    sculptor.setColor(0.98, 0.41, 0.05, 0.7); //Ecstasy
    sculptor.putSphere(5, 5, 6, 2); //
    sculptor.setColor(0.86, 0.07, 0.36, 0.9); //Razzmatazz
    sculptor.cutEllipsoid(3, 3, 3, 3, 2, 1); //
    sculptor.setColor(0.0, 0.71, 0.8, 0.95); //Iris Blue
    sculptor.putEllipsoid(1, 2, 6, 1, 1, 2); //
    //Testes
    sculptor.putVoxel(0, 9, 9); //
    //sculptor.putVoxel(0, 90, 9); //
    //sculptor.putVoxel(0, 0, 90); //
    //sculptor.putVoxel(-90, 9, 9); //
    //sculptor.putVoxel(0, -90, 9); //
    //sculptor.putVoxel(0, 0, -90); //



    sculptor.writeOFF((char *)"helloSculptor.off");

    return 0;
}
