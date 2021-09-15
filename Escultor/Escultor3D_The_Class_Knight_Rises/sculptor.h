#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <string>
#include <vector>

typedef struct {
  float r,g,b; // Colors
  float a;
// Transparency
  bool isOn; // Included or not
}  Voxel;

using namespace std;

enum {XY, XZ, ZY};

class Sculptor {
protected:
  Voxel ***v;// 3D matrix
  float lado; // Metade da largura de um cubo
  float delta; // Distancia entre os cubos
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
  int i, x, y, z; // Variaveis auxiliares
public:
  Sculptor(int _nx=1, int _ny=1, int _nz=1);
  ~Sculptor();
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int rx, int ycenter, int ry, int zcenter, int rz);
  void cutEllipsoid(int xcenter, int rx, int ycenter, int ry, int zcenter, int rz);
  void writeOFF(string filename);
  void limpaVoxels(void);
  void setEspacoEntreCubos(float _delta);
  int sizeX();
  int sizeY();
  int sizeZ();

  vector< vector<Voxel> > getPlano(int dim, int plano= XY);
};

#endif // SCULPTOR_H
