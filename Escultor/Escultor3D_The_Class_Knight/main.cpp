#include <iostream>
#include "figurageometrica.h"
#include "interpretador.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "sculptor.h"

using namespace std;

int main() {
    Sculptor *s1;

    vector < FiguraGeometrica* > escultura;

    Interpretador parser;

    escultura = parser.parse("classKnight.txt");

    s1 = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for(size_t i = 0; i < escultura.size(); i++) {

        escultura[i] -> draw(*s1);
    }

    s1 -> writeOFF((char*)"classKnight.off");

    for(size_t i=0; i<escultura.size(); i++) {
        delete escultura[i];
    }

    delete s1;

    //Testes
    cout << "\nIniciando testes de fronteira\n";

    escultura = parser.parse("joker.txt");

    s1 = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for(size_t i = 0; i < escultura.size(); i++) {

        escultura[i] -> draw(*s1);
    }

    s1 -> writeOFF((char*)"joker.off");

    for(size_t i=0; i<escultura.size(); i++) {
        delete escultura[i];
    }

    delete s1;

    cout << "Program Finished!" << endl;
    return 0;
}
