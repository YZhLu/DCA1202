#include "newfigdialog.h"
#include "ui_newfigdialog.h"

NewFigDialog::NewFigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewFigDialog)
{
    ui->setupUi(this);

}

NewFigDialog::~NewFigDialog()
{
    delete ui;
}

int NewFigDialog::getSizeX() {
  return ui->horizontalSliderDimX->value();
}

int NewFigDialog::getSizeY() {
  return ui->horizontalSliderDimY->value();
}

int NewFigDialog::getSizeZ() {
  return ui->horizontalSliderDimZ->value();
}
