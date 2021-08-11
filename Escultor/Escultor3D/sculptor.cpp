#include "sculptor.h"
#include <iostream>
#include <cmath>
#include <fstream>

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

Sculptor::~Sculptor() {

    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {

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
        cout << "/o\\\nInvente não abençoado! \nA 3D Matrix tem " << nx << ", " << ny << ", " << nz <<
                " de dimensão e você ainda quer mais? \n" <<
                "Tu não estás vendo que (" << x << ", " << y << ", " << z << ") está fora da matriz?\n\n";

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
        cout << "/o\\\nInvente não abençoado! \nA 3D Matrix tem " << nx << ", " << ny << ", " << nz <<
                " de dimensão e você ainda quer mais? \n" <<
                "Tu não estás vendo que (" << x << ", " << y << ", " << z << ") está fora da matriz?\n\n";
    } else {
        v[x][y][z].isOn = false;
    }

}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {

    for(int i = x0; i <= x1; i++) {
        for(int j = y0; j <= y1; j++) {
            for(int k = z0; k <= z1; k++) {

                this->putVoxel(i, j, k);

            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {

    for(int i = x0; i <= x1; i++) {
        for(int j = y0; j <= y1; j++) {
            for(int k = z0; k <= z1; k++) {

                this->cutVoxel(i, j, k);

            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {

    int r = pow(radius, 2);

    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {

                int sphere = pow((i - xcenter), 2) + pow((j - ycenter), 2) + pow((k - zcenter), 2);

                if(sphere <= r){

                    this->putVoxel(i, j, k);

                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {

    int r = pow(radius, 2);

    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {

                int sphere = pow((i - xcenter), 2) + pow((j - ycenter), 2) + pow((k - zcenter), 2);

                if(sphere <= r) {

                    this->cutVoxel(i, j, k);

                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {

                int ellipsoid = pow((i - xcenter), 2)/pow(rx, 2) + pow((j - ycenter), 2)/pow(ry, 2) + pow((k - zcenter), 2)/pow(rz, 2);

                if(ellipsoid <= 1) {

                    this->putVoxel(i, j, k);

                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {

                int ellipsoid = pow((i - xcenter), 2)/pow(rx, 2) + pow((j - ycenter), 2)/pow(ry, 2) + pow((k - zcenter), 2)/pow(rz, 2);

                if(ellipsoid <= 1) {

                    this->cutVoxel(i, j, k);

                }
            }
        }
    }
}

void Sculptor::writeOFF(const char *filename) {

    int _f = 0;
    int _v = 0;
    int total = 0;

    ofstream fout;
    fout.open(filename);

    if(!fout.is_open()) {
        exit(1);
    }


    fout << "OFF" << endl;//Format

    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {

                if(v[i][j][k].isOn) {

                    _v = _v + 1;

                }
            }
        }
    }

    fout << _v*8 << " " << _v*6 << " " << 0 <<endl;//Specs

    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {

                if(v[i][j][k].isOn) {//Vertices

                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;

                }
            }
        }
    }

    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {

                if(v[i][j][k].isOn) {//Faces

                    _f = total*8;

                    fout << 4 << " " << _f+0 << " " << _f+3 << " " << _f+2 << " " << _f+1 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    fout << 4 << " " << _f+4 << " " << _f+7 << " " << _f+3 << " " << _f+0 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    fout << 4 << " " << _f+5 << " " << _f+6 << " " << _f+7 << " " << _f+4 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    fout << 4 << " " << _f+6 << " " << _f+2 << " " << _f+3 << " " << _f+7 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    fout << 4 << " " << _f+5 << " " << _f+1 << " " << _f+2 << " " << _f+6 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    fout << 4 << " " << _f+5 << " " << _f+4 << " " << _f+0 << " " << _f+1 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;

                    total = total + 1;
                }
            }
        }
    }

    fout.close();
    cout<< "The file was saved!" << endl;
}
