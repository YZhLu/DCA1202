#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QBasicTimer>
#include <QVector>
#include "sculptor.h"
#include <vector>

using namespace std;

class DrawWidget : public QWidget
{
    Q_OBJECT

private:
    QColor background;
    float fase;
    float freq;
    QBasicTimer timer;
    int nlinhas, ncolunas;
    vector< vector<Voxel> > v;
    int borderv;
    int borderh;
    int dimCelula;
    int larguraTela, alturaTela;
    int larguraCelula, alturaCelula;
    bool pressed; // SE DER ERRADO EH AKI


public:
    explicit DrawWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setTamanho(int _nlinhas, int _ncolunas);
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void loadMatrix(vector< vector<Voxel> > m);

signals:
    void updatePos(int, int);
public slots:
    void setfreq(int);

};

#endif // DRAWWIDGET_H
