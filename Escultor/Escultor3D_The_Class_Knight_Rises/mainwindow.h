#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>

#include <QColorDialog>

#include "sculptor.h"
#include "newfigdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum {PUTVOXEL, CUTVOXEL, PUTBOX, CUTBOX, PUTSPHEARE, CUTSPHEARE, PUTELLIPSOID, CUTELLIPSOID};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int r, g, b;
    void updateColor();
    Sculptor *e;
    int dimX, dimY, dimZ;
    int currentObject;
    int currentPlane;
    QActionGroup *actionGroup;

public slots:
    void setR(int);
    void setG(int);
    void setB(int);
    void pickColor();
    void drawShape(int, int);
    void updateCoords(int, int);


private slots:
    void clickedXY();
    void clickedXZ();
    void clickedZY();
    void on_actionPutVoxel();
    void on_actionCutVoxel();
    void on_actionPutBox();
    void on_actionCutBox();
    void on_actionPutSpheare();
    void on_actionCutSpheare();
    void on_actionPutEllipsoid();
    void on_actionCutEllipsoid();
    void on_layerSliderXChange();
    void on_layerSliderYChange();
    void on_layerSliderZChange();
    void on_newSculptor();
    void on_actionExportOFF();
};
#endif // MAINWINDOW_H
