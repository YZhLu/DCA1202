#include "interpretador.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"



Interpretador::Interpretador() {

}

std::vector<FiguraGeometrica *> Interpretador::parse(std::string filename) {
    std::vector<FiguraGeometrica *> figs;
    std::ifstream fin;
    std::string s;
    std::stringstream ss;

    fin.open(filename.c_str());

    if(!fin.is_open()) {
        std:: cout<<"Try Again!"<< filename << std::endl;
        exit(0);
    }

    while(fin.good()) {

        std::getline(fin, s);
        if(fin.good()){
            ss.clear();
            ss.str(s);
            ss >> s;

            if(ss.good()) { //check if the stream is good enough to work.
                if(s.compare("dim")==0) {

                    ss >>  dimx >> dimy >> dimz;
                } else if (s.compare("putvoxel")==0) {

                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
                } else if (s.compare("cutvoxel") == 0) {

                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0;
                    figs.push_back(new CutVoxel(x0, y0, z0));
                } else if (s.compare("putbox") == 0) {

                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                } else if (s.compare("cutbox") == 0) {

                    int x0,y0,z0,x1,y1,z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                } else if (s.compare("putsphere") == 0) {

                    int xcenter,ycenter,zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
                } else if (s.compare("cutsphere") == 0) {

                    int xcenter,ycenter,zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
                } else if (s.compare("putellipsoid") == 0) {

                    int xcenter,ycenter,zcenter, rx,ry,rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
                } else if (s.compare("cutellipsoid") == 0) {

                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
                }
            }

        }
    }

    return figs;
}

int Interpretador::getDimx() {
    return dimx;
}

int Interpretador::getDimy() {
    return dimy;
}

int Interpretador::getDimz() {
    return dimz;
}
