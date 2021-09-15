#include "drawwidget.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QSize>
#include <QPoint>
#include <cmath>
#include <QTimerEvent>
#include <QMouseEvent>
#include <iostream>
#include <QMessageBox>
#include <QGradient>

#include <QDebug>

#define PI 3.14159265358979323846

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent) {
    background = QColor(250, 250, 250);
    fase = 0.0;
    freq = 1;
    nlinhas = 10;
    ncolunas = 10;
    pressed = false;
    larguraTela = rect().width();
    alturaTela = rect().height();
    larguraCelula = larguraTela/ncolunas;
    alturaCelula = alturaTela/nlinhas;

    if(alturaCelula > larguraCelula) {
        dimCelula = larguraCelula;
    } else {
        dimCelula = alturaCelula;
    }

    setTamanho(nlinhas, ncolunas);
}

void DrawWidget::paintEvent(QPaintEvent *event) {
    /*QPainter painter(this);
    QBrush brush;
    QPen pen;
    int x1, x2, y1, y2;

    // brush amarela e solida
    brush.setColor(background);
    brush.setStyle(Qt::SolidPattern);

    // caneta cor vermelha
    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(2);

    // informa ao pintor qual o brush atual
    painter.setBrush((brush));
    // informa ao pintor qual a caneta (pen) atual
    painter.setPen(pen);
    // desenha um componente abrangendo toda a extensao
    // componente
    painter.drawRect(0, 0, width(), height());

    /*
    // desenha o seno na tela
    pen.setColor(QColor(255, 180, 0));
    painter.setPen(pen);

    painter.drawLine(0, height()/2, width(), height()/2);

    //y = sin(2*3.1415*frequencia*t+angulo)
    x1 = 0;
    y1 = height()/2;

    // desenha o seno na tela
    pen.setColor(QColor(0, 0, 255));
    painter.setPen(pen);

    for(int i=0; i<width();i++) {
        x2 = i;
        y2 = height()/2*(1 - amplitude*sin(2*PI*frequencia*x2/width() + angulo));
        painter.drawLine(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
    }
*/
    QPen pen;
    QPointF p1, p2;
    QPainter p(this);
    QColor color;
    QRadialGradient gradient(QPointF(1,1), 20);
    gradient.setColorAt(0, Qt::black);
    gradient.setColorAt(0, Qt::white);

    QBrush brush;
    p.setRenderHint(QPainter::Antialiasing, true);
    pen.setWidth(1);
    larguraTela = rect().width();
    alturaTela = rect().height();
    larguraCelula = larguraTela/ncolunas;
    alturaCelula = alturaTela/nlinhas;

    if(alturaCelula > larguraCelula) {
        dimCelula = larguraCelula;
    } else {
        dimCelula = alturaCelula;
    }

    borderh = (larguraTela - ncolunas*dimCelula)/2;
    borderv = (alturaTela - nlinhas*dimCelula)/2;
    gradient.setRadius(dimCelula);
    gradient.setFocalPoint(-0.15*dimCelula, -0.15*dimCelula);
    gradient.setCenter(-0.15*dimCelula, -0.15*dimCelula);
    p.setPen(pen);
    p.drawRect(rect());

    for(uint i = 0; i < v.size(); i++) {
        for(uint j = 0; j < v[i].size(); j++) {
            if(v[i][j].isOn == true) {
                p.save();
                p.translate(j*dimCelula+borderh+dimCelula/2,
                            i*dimCelula+borderv+dimCelula/2);
                p.setPen(Qt::NoPen);
                color.setRgba(qRgba(v[i][j].r*255, v[i][j].g*255, v[i][j].b*255, v[i][j].a*255));
                gradient.setColorAt(0, Qt::white);
                gradient.setColorAt(.3, color);
                gradient.setColorAt(1, color.darker());
                p.setBrush(gradient);
                p.drawEllipse(-dimCelula/2+1, -dimCelula/2+1, dimCelula-1, dimCelula-1);
                p.restore();
            } else {

                brush.setColor(QColor(225,255,255));
                p.setBrush(brush);
                p.drawRect(j*dimCelula+borderh, i*dimCelula+borderv,
                           dimCelula, dimCelula);
            }

        }
    }


}

void DrawWidget::setTamanho(int _nlinhas, int _ncolunas){

}

void DrawWidget::loadMatrix(vector<vector<Voxel>> m) {
    nlinhas = m.size();
    ncolunas = m[0].size();
    v = m;
    repaint();
}

void DrawWidget::setfreq(int _freq) {
    freq = _freq;
    fase = 0;
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event) {
    pressed = false;
}

void DrawWidget::mousePressEvent(QMouseEvent *event) {
    int posh, posv;
    QRect ret;
    ret = rect();
    pressed = true;
    ret.adjust(borderh, borderv, -borderh, -borderv);

    if(ret.contains(event->pos())){
        posh = (event->pos().x()-borderh)*ncolunas/ret.width();
        posv = (event->pos().y()-borderv)*nlinhas/ret.height();
        emit updatePos(posh, posv);
        //qDebug() << "x,y" << posh << posv;
    }
}

void DrawWidget::timerEvent(QTimerEvent *event) {
    if (event->timerId() == timer.timerId()) {
        fase = fase + 0.01;
        if(fase == 2*PI)
            fase = 0;
        update();
    } else {
        QWidget::timerEvent(event);
    }
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event) {
    int posh, posv;
    QRect ret;
    ret = rect();
    ret.adjust(borderh, borderv, -borderh, -borderv);
    if(ret.contains(event->pos())){
        posh = (event->pos().x()-borderh)*ncolunas/ret.width();
        posv = (event->pos().y()-borderv)*nlinhas/ret.height();
        emit updatePos(posh, posv);
    }


}
