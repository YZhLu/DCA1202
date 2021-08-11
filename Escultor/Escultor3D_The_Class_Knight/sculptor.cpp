#include "sculptor.h"
#include <iostream>
//#include <cmath>
#include <fstream>
#include <iomanip>
#include <math.h>

//#include <string>
//#include <sstream>


//#include <vector>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz) {

    cout << "The builder started!" << endl;
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];

    for(int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];
        for(int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
        }
    }
}
/*

    r=1.00;
    g=1.00;
    b=1.00;
    a=1.00;

    v = new Voxel**[nx];
    for(int i=0; i<nx;i++){
        v[i] = new Voxel*[ny];
        for(int j=0;j<ny;j++){
            v[i][j] = new Voxel[nz];
            for(int k =0; k<nz;k++){
                v[i][j][k].isOn = false;
            }
        }
    }*/

Sculptor::~Sculptor() {

    for(int i=0; i<nx;i++){
        for(int j=0;j<ny;j++){
           delete[] v[i][j];
        }
        delete[] v[i];
    }

    delete[] v;

    cout << "The builder finished!" << endl;

}

void Sculptor::setColor(float _r, float _g, float _b, float alpha) {

    r = _r;
    g = _g;
    b = _b;
    a = alpha;

}

void Sculptor::putVoxel(int x, int y, int z) {

    if (x >= nx || y >= ny || z >= nz || x < 0 || y < 0 || z < 0) {
        dimensionError();

    } else {
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
        v[x][y][z].isOn = true;

    }

}

void Sculptor::cutVoxel(int x, int y, int z) {

    if (x >= nx || y >= ny || z >= nz || x < 0 || y < 0 || z < 0) {
        dimensionError();

    } else {
        v[x][y][z].isOn = false;
    }

}


void Sculptor::writeOFF(const char *filename) {

    int _f = 0;
    int _v = 0;
    int total = 0;

    ofstream file;
    file.open(filename);

    if(file.is_open() == true){
        cout << "The file is open!" << endl;
    }

    file << "OFF" << endl;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn == true){
                     _v++;
                }
            }
        }
    }

    file << 8*_v << " " << 6*_v << " " << 0 << endl;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++) {
                if(v[i][j][k].isOn == true){
                    file << -0.5+i << " " << 0.5+j << " " << -0.5+k << endl;
                    file << -0.5+i << " " << -0.5+j << " " << -0.5+k << endl;
                    file << 0.5+i << " " << -0.5+j << " " << -0.5+k << endl;
                    file << 0.5+i << " " << 0.5+j << " " << -0.5+k << endl;
                    file << -0.5+i << " " << 0.5+j << " " << 0.5+k << endl;
                    file << -0.5+i << " " << -0.5+j << " " << 0.5+k << endl;
                    file << 0.5+i << " " << -0.5+j << " " << 0.5+k << endl;
                    file << 0.5+i << " " << 0.5+j << " " << 0.5+k << endl;
                }
            }
        }
    }

    file << fixed << setprecision(2);
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for (int k = 0; k< nz; k++) {
                if(v[i][j][k].isOn == true){

                    _f = total*8;

                    file << "4 " << 0+_f << " " << 3+_f << " " << 2+_f << " " << 1+_f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl
                         << "4 " << 4+_f << " " << 5+_f << " " << 6+_f << " " << 7+_f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl
                         << "4 " << 0+_f << " " << 1+_f << " " << 5+_f << " " << 4+_f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl
                         << "4 " << 0+_f << " " << 4+_f << " " << 7+_f << " " << 3+_f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl
                         << "4 " << 3+_f << " " << 7+_f << " " << 6+_f << " " << 2+_f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl
                         << "4 " << 1+_f << " " << 2+_f << " " << 6+_f << " " << 5+_f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;

                    total = total + 1;
                }
            }
        }
    }

    file.close();
    cout<< "The file was saved!" << endl;
}

void Sculptor::dimensionError() {

    cout << "/o\\\nInvente não abençoado! \nA 3D Matrix tem " << nx << ", " << ny << ", " << nz <<
            " de dimensão e você ainda quer mais? \n" <<
            "Tu não estás vendo que (x, y, z) está fora da matriz?\n\n";

    exit(0);
}

int Sculptor::getMatX() {
    return nx;
}

int Sculptor::getMatY() {
    return ny;
}

int Sculptor::getMatZ() {
    return nz;
}
