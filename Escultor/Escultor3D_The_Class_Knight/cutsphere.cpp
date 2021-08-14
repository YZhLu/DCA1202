#include "cutsphere.h"
#include <math.h>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius){

    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> radius = radius;
}

void CutSphere::draw(Sculptor &s){
    int positionX, positionY, positionZ;
    int sphere;
    int r = pow(radius, 2);

    if((xcenter < s.getMatX()) &&(ycenter < s.getMatY()) && (zcenter < s.getMatZ())){

        for(int i = 0; i<s.getMatX(); i++){
            for(int j = 0; j<s.getMatY(); j++){
                for(int k = 0; k<s.getMatZ(); k++){

                    positionX = xcenter - i;
                    positionY = ycenter - j;
                    positionZ = zcenter - k;

                    sphere = pow(positionX, 2) + pow(positionY, 2) + pow(positionZ, 2);

                    if(sphere <= r){
                        s.cutVoxel(i, j, k);
                    }
                }
            }
        }

    } else {
        s.dimensionError();
    }
}
