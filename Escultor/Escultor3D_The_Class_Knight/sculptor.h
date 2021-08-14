#ifndef SCULPTOR_H
#define SCULPTOR_H
#include<string>
#include<vector>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Voxel {
  float r,g,b; // Colors
  float a;
  // Transparency
  bool isOn; // Included or not
};


class Sculptor {
protected:
  Voxel ***v;
  // 3D matrix
  int nx, ny, nz; // Dimensions
  float r, g, b, a; // Current drawing color

public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void writeOFF(const char* filename);

  void dimensionError();
  int getMatX();
  int getMatY();
  int getMatZ();
};

#endif // SCULPTOR_H
