#ifndef NEWFIGDIALOG_H
#define NEWFIGDIALOG_H

#include <QDialog>

namespace Ui {
class NewFigDialog;
}

class NewFigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewFigDialog(QWidget *parent = nullptr);
    ~NewFigDialog();

    int getSizeX();

    int getSizeY();

    int getSizeZ();

private:
    Ui::NewFigDialog *ui;
};

#endif // NEWFIGDIALOG_H
