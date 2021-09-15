#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    r = g = b = 255;
    dimX = dimY = dimZ = 10;
    ui->layerSliderX->setMaximum(dimX-1);
    ui->spinBoxLayerX->setMaximum(dimX-1);
    ui->layerSliderY->setMaximum(dimY-1);
    ui->spinBoxLayerY->setMaximum(dimY-1);
    ui->layerSliderZ->setMaximum(dimZ-1);
    ui->spinBoxLayerZ->setMaximum(dimZ-1);

    e = new Sculptor(dimX, dimY, dimZ);

    currentObject = PUTVOXEL;
    updateColor();

    /////// TEST
     e->putVoxel(0,0,0);
     e->setColor(1,1,1,1);
     e->putVoxel(9,9,9);
     e->setColor(0,0,1,1);
     e->putVoxel(9,9,9);

     e->setColor(0, 0, 0, 1); //black
         e->putVoxel(0, 0, 0); //0,0,0
         e->setColor(1, 0, 0, 1); //red
         e->putVoxel(9, 0, 0); //x-axis
         e->setColor(0, 1, 0, 1); //green
         e->putVoxel(0, 9, 0); //y-axis
         e->setColor(0, 0, 1, 1); //blue
         e->putVoxel(0, 0, 9); //z-axis
         e->setColor(0, 1, 1, 1); //cyan
         e->putVoxel(0, 9, 9); //yz
         e->setColor(1, 1, 0, 1); //yellow
         e->putVoxel(9, 9, 0); //xy
         e->setColor(1, 0, 1, 1); //magenta
         e->putVoxel(9, 0, 9); //xz
         e->setColor(1, 1, 1, 1); //white
         e->putVoxel(9, 9, 9); //xyz
    ///

    ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), XY));
    currentPlane = XY;

    /// Plane Selector
    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionXY);
    actionGroup->addAction(ui->actionXZ);
    actionGroup->addAction(ui->actionZY);
    ui->actionXY->setChecked(true);

    // Sculptor Actions
    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionPutVoxel);
    actionGroup->addAction(ui->actionCutVoxel);
    actionGroup->addAction(ui->actionPutBox);
    actionGroup->addAction(ui->actionCutBox);
    actionGroup->addAction(ui->actionPutSpheare);
    actionGroup->addAction(ui->actionCutSpheare);
    actionGroup->addAction(ui->actionPutEllipsoid);
    actionGroup->addAction(ui->actionCutEllipsoid);
    ui->actionPutVoxel->setChecked(true);
    //ui->pushButtonXY->setStyleSheet("QPushButton { background-color: gray;}");
    showMaximized();

    /// Menu Actions

    connect(ui->actionNew_Sculptor,
            SIGNAL(triggered(bool)),
            this,
            SLOT(on_newSculptor()));
    connect(ui->actionExportOFF,
            SIGNAL(triggered(bool)),
            this,
            SLOT(on_actionExportOFF()));

    /// Plane Selector Actions
    connect(ui->actionXZ,
            SIGNAL(triggered(bool)),
            this,
            SLOT(clickedXZ()));
    connect(ui->actionXY,
            SIGNAL(triggered(bool)),
            this,
            SLOT(clickedXY()));
    connect(ui->actionZY,
            SIGNAL(triggered(bool)),
            this,
            SLOT(clickedZY()));
/*
    connect(ui->pushButtonXY,
            SIGNAL(clicked()),
            this,
            SLOT(clickedXY()));
    connect(ui->pushButtonXZ,
            SIGNAL(clicked()),
            this,
            SLOT(clickedXZ()));
    connect(ui->pushButtonZY,
            SIGNAL(clicked()),
            this,
            SLOT(clickedZY()));
*/
    ///
    /// Sculptor Methods
    ///

    connect(ui->actionPutVoxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(on_actionPutVoxel()));
    connect(ui->actionCutVoxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(on_actionCutVoxel()));
    connect(ui->actionPutBox,
            SIGNAL(triggered(bool)),
            this,
            SLOT(on_actionPutBox()));
    connect(ui->actionCutBox,
            SIGNAL(triggered(bool)),
            this,
            SLOT(on_actionCutBox()));
    connect(ui->actionPutSpheare,
            SIGNAL(triggered(bool)),
            this,
            SLOT(on_actionPutSpheare()));
    connect(ui->actionCutSpheare,
            SIGNAL(triggered(bool)),
            this,
            SLOT(on_actionCutSpheare()));
    connect(ui->actionPutEllipsoid,
            SIGNAL(triggered(bool)),
            this,
            SLOT(on_actionPutEllipsoid()));
    connect(ui->actionCutEllipsoid,
            SIGNAL(triggered(bool)),
            this,
            SLOT(on_actionCutEllipsoid()));

/// Sliders connect

    connect(ui->layerSliderX,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(on_layerSliderXChange()));
    connect(ui->layerSliderY,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(on_layerSliderYChange()));
    connect(ui->layerSliderZ,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(on_layerSliderZChange()));



    connect(ui->widgetCanvas,
            SIGNAL(updatePos(int,int)),
            this,
            SLOT(updateCoords(int,int)));
    connect(ui->widgetCanvas,
            SIGNAL(updatePos(int,int)),
            this,
            SLOT(drawShape(int,int)));
    connect(ui->pushButtonColor,
            SIGNAL(clicked()),
            this,
            SLOT(pickColor()));
    connect(ui->horizontalSliderR,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setR(int)));
    connect(ui->horizontalSliderG,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setG(int)));
    connect(ui->horizontalSliderB,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setB(int)));
    connect(ui->spinBoxR,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setR(int)));
    connect(ui->spinBoxG,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setG(int)));
    connect(ui->spinBoxB,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setB(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateColor() {

    QString color, textColor;
    textColor = "QPushButton { background-color: rgb(" +
            QString().setNum(255-r) + "," +
            QString().setNum(255-g) + "," +
            QString().setNum(255-b) + ");}";
    color = "QPushButton { background-color: rgb(" +
            QString().setNum(r) + "," +
            QString().setNum(g) + "," +
            QString().setNum(b) + ");}";

    //qDebug() << r << g<< b << color;
    ui->pushButtonColor->setStyleSheet(color);
    e->setColor(r/255,g/255,b/255,1);
}

void MainWindow::setR(int _r) {
    r = _r;
    updateColor();
}

void MainWindow::setG(int _g) {
    g = _g;
    updateColor();
}

void MainWindow::setB(int _b) {
    b = _b;
    updateColor();
}

void MainWindow::pickColor() {
    QColorDialog d;
    d.exec();
    r = d.selectedColor().red();
    g = d.selectedColor().green();
    b = d.selectedColor().blue();
    ui->horizontalSliderR->setValue(r);
    ui->horizontalSliderG->setValue(g);
    ui->horizontalSliderB->setValue(b);
    //ui->horizontalSliderA->setValue(a);
    updateColor();

}

void MainWindow::drawShape(int horizClick, int vertClick) {
    //qDebug() << "e";

  switch(currentObject) {
    case(PUTVOXEL):
        switch (currentPlane) {
            case XY:
                e->putVoxel(horizClick, vertClick, ui->layerSliderZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), XY));
                break;

            case XZ:
                e->putVoxel(horizClick, ui->layerSliderY->value(), vertClick);
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), XZ));
                break;

            case ZY:
                e->putVoxel(ui->layerSliderX->value(), vertClick, horizClick);
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderX->value(), ZY));
                break;
      }
      break;

    case(CUTVOXEL):
        switch (currentPlane) {
            case XY:
                e->cutVoxel(horizClick, vertClick, ui->layerSliderZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), XY));
                break;

            case XZ:
                e->cutVoxel(horizClick, ui->layerSliderY->value(), vertClick);
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), XZ));
                break;

            case ZY:
                e->cutVoxel(ui->layerSliderX->value(), vertClick, horizClick);
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderX->value(), ZY));
                break;

        }
        break;

    case(PUTBOX):
        switch (currentPlane) {
            case XY:
                e->putBox(horizClick, horizClick + ui->spinPutBoxX->value(),
                          vertClick, vertClick + ui->spinPutBoxY->value(),
                          ui->layerSliderZ->value(), ui->layerSliderZ->value() + ui->spinPutBoxZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), XY));
                break;

            case XZ:
                e->putBox(horizClick, horizClick + ui->spinPutBoxX->value(),
                          ui->layerSliderY->value(), ui->layerSliderY->value() + ui->spinPutBoxY->value(),
                          vertClick, vertClick + ui->spinPutBoxZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), XZ));
                break;

            case ZY:
                e->putBox(ui->layerSliderX->value(), ui->layerSliderX->value() + ui->spinPutBoxX->value(),
                            vertClick, vertClick + ui->spinPutBoxY->value(),
                            horizClick, horizClick + ui->spinPutBoxZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderX->value(), ZY));
                break;
        }
        break;

    case(CUTBOX):
        switch (currentPlane) {
            case XY:
               e->cutBox(horizClick, horizClick + ui->spinCutBoxX->value(),
                          vertClick, vertClick + ui->spinCutBoxY->value(),
                          ui->layerSliderZ->value(), ui->layerSliderZ->value() + ui->spinCutBoxZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), XY));
                break;

            case XZ:
                e->cutBox(horizClick, horizClick + ui->spinCutBoxX->value(),
                        ui->layerSliderY->value(), ui->layerSliderY->value() + ui->spinCutBoxY->value(),
                        vertClick, vertClick + ui->spinCutBoxZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), ZY));
                break;

            case ZY:
                e->cutBox(ui->layerSliderX->value(), ui->layerSliderX->value() + ui->spinCutBoxX->value(),
                          vertClick, vertClick + ui->spinCutBoxY->value(),
                          horizClick, horizClick + ui->spinCutBoxZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderX->value(), ZY));
                break;
        }
        break;

    case(PUTSPHEARE):
        switch (currentPlane) {
            case XY:
                e->putSphere(horizClick,
                        vertClick,
                        ui->layerSliderZ->value(),
                          ui->spinBoxPutSphere->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), XY));
                break;

            case XZ:
                e->putSphere(horizClick,
                      ui->layerSliderY->value(),
                      vertClick,
                        ui->spinBoxPutSphere->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), ZY));
                break;

            case ZY:
                e->putSphere(ui->layerSliderX->value(),
                        vertClick,
                        horizClick,
                           ui->spinBoxPutSphere->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderX->value(), ZY));
                break;
      }
      break;

  case(CUTSPHEARE):
      switch (currentPlane) {
          case XY:
             e->cutSphere(horizClick,
                        vertClick,
                        ui->layerSliderZ->value(),
                          ui->spinBoxCutSphere->value());
              ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), XY));
              break;

          case XZ:
              e->cutSphere(horizClick,
                      ui->layerSliderY->value(),
                      vertClick,
                        ui->spinBoxCutSphere->value());
              ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), ZY));
              break;

          case ZY:
              e->cutSphere(ui->layerSliderX->value(),
                        vertClick,
                        horizClick,
                           ui->spinBoxCutSphere->value());
              ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderX->value(), ZY));
              break;
      }
      break;

    case(PUTELLIPSOID):
        switch (currentPlane) {
            case XY:
                qDebug() << horizClick << horizClick + ui->spinPutEllipsoidX->value() <<
                        vertClick << vertClick + ui->spinPutEllipsoidY->value() <<
                        ui->layerSliderZ->value() << ui->layerSliderZ->value() + ui->spinPutEllipsoidZ->value() << "fou";
              e->putEllipsoid(horizClick, ui->spinPutEllipsoidX->value(),
                        vertClick, ui->spinPutEllipsoidY->value(),
                        ui->layerSliderZ->value(), ui->spinPutEllipsoidZ->value());
              ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), XY));
              break;

            case XZ:
              e->putEllipsoid(horizClick, ui->spinPutEllipsoidX->value(),
                        ui->layerSliderY->value(), ui->spinPutEllipsoidY->value(),
                        vertClick, ui->spinPutEllipsoidZ->value());
              ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), XZ));
              break;

            case ZY:
              e->putEllipsoid(ui->layerSliderX->value(), ui->spinPutEllipsoidX->value(),
                          vertClick, ui->spinPutEllipsoidY->value(),
                          horizClick, ui->spinPutEllipsoidZ->value());
              ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderX->value(), ZY));
              break;
        }
        break;

    case(CUTELLIPSOID):
        switch (currentPlane) {
            case XY:

                e->cutEllipsoid(horizClick, ui->spinCutEllipsoidX->value(),
                      vertClick, ui->spinCutEllipsoidY->value(),
                      ui->layerSliderZ->value(), ui->spinCutEllipsoidZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), XY));
                break;

            case XZ:
                e->cutEllipsoid(horizClick, ui->spinCutEllipsoidX->value(),
                      ui->layerSliderY->value(), ui->spinCutEllipsoidY->value(),
                      vertClick, ui->spinCutEllipsoidZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), XZ));
                break;

            case ZY:
                e->cutEllipsoid(ui->layerSliderX->value(), ui->spinCutEllipsoidX->value(),
                        vertClick, ui->spinCutEllipsoidY->value(),
                        horizClick, ui->spinCutEllipsoidZ->value());
                ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderX->value(), ZY));
                break;
        }
        break;


    }

}

void MainWindow::updateCoords(int horizClick, int vertClick) {
   // qDebug() << horizClick;
    switch (currentPlane) {
        case XY:
            ui->lcdNumberCol->display(horizClick);
            ui->lcdNumberLine->display(vertClick);
            ui->labelPlane->setText("XY");
        break;

        case XZ:
            ui->lcdNumberCol->display(horizClick);
            ui->lcdNumberLine->display(vertClick);
            ui->labelPlane->setText("XZ");
        break;

        case ZY:
            ui->lcdNumberCol->display(horizClick);
            ui->lcdNumberLine->display(vertClick);
            ui->labelPlane->setText("ZY");
            break;
    }
}

void MainWindow::clickedXY() {
    currentPlane = XY;
    ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), currentPlane));
}

void MainWindow::clickedXZ() {
    currentPlane = XZ;
    ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), currentPlane));
}

void MainWindow::clickedZY() {
    currentPlane = ZY;
    ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderX->value(), currentPlane));
}

void MainWindow::on_actionPutVoxel() {
    currentObject = PUTVOXEL;
    ui->labelSculptorMethod->setText("PutVoxel");
    qDebug() << "chegou putvoxel";
}

void MainWindow::on_actionCutVoxel() {
    currentObject = CUTVOXEL;
    ui->labelSculptorMethod->setText("CutVoxel");
    qDebug() << "chegou cutVoxel";
}

void MainWindow::on_actionPutBox() {
    currentObject = PUTBOX;
    ui->labelSculptorMethod->setText("PutBox");
    qDebug() << "chegou putBox";
}

void MainWindow::on_actionCutBox() {
    currentObject = CUTBOX;
    ui->labelSculptorMethod->setText("CutBox");
    qDebug() << "chegou cutBox";
}

void MainWindow::on_actionPutSpheare() {
    currentObject = PUTSPHEARE;
    ui->labelSculptorMethod->setText("PutSphere");
    qDebug() << "chegou sphere";
}

void MainWindow::on_actionCutSpheare() {
    currentObject = CUTSPHEARE;
    ui->labelSculptorMethod->setText("CutSphere");
    qDebug() << "chegou sphere";
}

void MainWindow::on_actionPutEllipsoid() {
    currentObject = PUTELLIPSOID;
    ui->labelSculptorMethod->setText("PutEllipsoid");
    qDebug() << "chegou ellipsoid";
}

void MainWindow::on_actionCutEllipsoid() {
    currentObject = CUTELLIPSOID;
    ui->labelSculptorMethod->setText("CutEllipsoid");
    qDebug() << "chegou ellipsoid";

}

void MainWindow::on_layerSliderXChange() {
    //qDebug() << "slider" << ui->verticalSliderLayer->value() << "plane" << currentPlane;
    if (currentPlane == ZY) {
        ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderX->value(), currentPlane));
    }
}
void MainWindow::on_layerSliderYChange() {
    //qDebug() << "slider" << ui->verticalSliderLayer->value() << "plane" << currentPlane;
    if (currentPlane == XZ) {
        ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderY->value(), currentPlane));

    }
}
void MainWindow::on_layerSliderZChange() {
    //qDebug() << "slider" << ui->verticalSliderLayer->value() << "plane" << currentPlane;
    if (currentPlane == XY) {
        ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), currentPlane));

    }
}

void MainWindow::on_newSculptor() {
    NewFigDialog *dialog;
    dialog = new NewFigDialog();
    dialog->exec();
    if(dialog->result() == QDialog::Accepted) {
        dimX = dialog->getSizeX();
        dimY = dialog->getSizeY();
        dimZ = dialog->getSizeZ();
        if(e != NULL)
            delete e;
        e = new Sculptor(dimX, dimY, dimZ);
        ui->actionXY->trigger();
        ui->layerSliderX->setMaximum(dimX-1);
        ui->spinBoxLayerX->setMaximum(dimX-1);
        ui->layerSliderY->setMaximum(dimY-1);
        ui->spinBoxLayerY->setMaximum(dimY-1);
        ui->layerSliderZ->setMaximum(dimY-1);
        ui->spinBoxLayerZ->setMaximum(dimY-1);
        r = g = b = 255;
        updateColor();

        //Here
        ui->widgetCanvas->loadMatrix(e->getPlano(ui->layerSliderZ->value(), XY));
        currentPlane = XY;
    }

}

void MainWindow::on_actionExportOFF() {
    QFileDialog dialog;

    QString filename = dialog.getSaveFileName(this, tr("Salvar"),
                                              QDir::currentPath(),
                                              tr("Arquivo OFF(*.off)"));
    if(filename.isNull()) {
        return;
    }
    //e->limpaVoxels();
    e->writeOFF(filename.toStdString());
}

