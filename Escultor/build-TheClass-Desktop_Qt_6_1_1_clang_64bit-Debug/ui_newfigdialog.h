/********************************************************************************
** Form generated from reading UI file 'newfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFIGDIALOG_H
#define UI_NEWFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewFigDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelNewFigPic;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelDimensionX;
    QSlider *horizontalSliderDimX;
    QSpinBox *spinBoxDimX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelDimensionY;
    QSlider *horizontalSliderDimY;
    QSpinBox *spinBoxDimY;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelDimensionZ;
    QSlider *horizontalSliderDimZ;
    QSpinBox *spinBoxDimZ;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *NewFigDialog)
    {
        if (NewFigDialog->objectName().isEmpty())
            NewFigDialog->setObjectName(QString::fromUtf8("NewFigDialog"));
        NewFigDialog->resize(372, 430);
        NewFigDialog->setStyleSheet(QString::fromUtf8("background: rgba(82, 15, 185, 0.25); color: white; font-size: 18px;"));
        verticalLayout_3 = new QVBoxLayout(NewFigDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelNewFigPic = new QLabel(NewFigDialog);
        labelNewFigPic->setObjectName(QString::fromUtf8("labelNewFigPic"));
        labelNewFigPic->setMinimumSize(QSize(250, 250));
        labelNewFigPic->setMaximumSize(QSize(250, 250));
        labelNewFigPic->setStyleSheet(QString::fromUtf8("background: blue;"));
        labelNewFigPic->setPixmap(QPixmap(QString::fromUtf8(":/resource/assets/setAxis.png")));
        labelNewFigPic->setScaledContents(true);

        horizontalLayout_4->addWidget(labelNewFigPic);

        buttonBox = new QDialogButtonBox(NewFigDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelDimensionX = new QLabel(NewFigDialog);
        labelDimensionX->setObjectName(QString::fromUtf8("labelDimensionX"));

        horizontalLayout->addWidget(labelDimensionX);

        horizontalSliderDimX = new QSlider(NewFigDialog);
        horizontalSliderDimX->setObjectName(QString::fromUtf8("horizontalSliderDimX"));
        horizontalSliderDimX->setMinimum(1);
        horizontalSliderDimX->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSliderDimX);

        spinBoxDimX = new QSpinBox(NewFigDialog);
        spinBoxDimX->setObjectName(QString::fromUtf8("spinBoxDimX"));
        spinBoxDimX->setMinimum(1);

        horizontalLayout->addWidget(spinBoxDimX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelDimensionY = new QLabel(NewFigDialog);
        labelDimensionY->setObjectName(QString::fromUtf8("labelDimensionY"));

        horizontalLayout_2->addWidget(labelDimensionY);

        horizontalSliderDimY = new QSlider(NewFigDialog);
        horizontalSliderDimY->setObjectName(QString::fromUtf8("horizontalSliderDimY"));
        horizontalSliderDimY->setMinimum(1);
        horizontalSliderDimY->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderDimY);

        spinBoxDimY = new QSpinBox(NewFigDialog);
        spinBoxDimY->setObjectName(QString::fromUtf8("spinBoxDimY"));
        spinBoxDimY->setMinimum(1);

        horizontalLayout_2->addWidget(spinBoxDimY);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelDimensionZ = new QLabel(NewFigDialog);
        labelDimensionZ->setObjectName(QString::fromUtf8("labelDimensionZ"));

        horizontalLayout_3->addWidget(labelDimensionZ);

        horizontalSliderDimZ = new QSlider(NewFigDialog);
        horizontalSliderDimZ->setObjectName(QString::fromUtf8("horizontalSliderDimZ"));
        horizontalSliderDimZ->setMinimum(1);
        horizontalSliderDimZ->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSliderDimZ);

        spinBoxDimZ = new QSpinBox(NewFigDialog);
        spinBoxDimZ->setObjectName(QString::fromUtf8("spinBoxDimZ"));
        spinBoxDimZ->setMinimum(1);

        horizontalLayout_3->addWidget(spinBoxDimZ);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        retranslateUi(NewFigDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NewFigDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NewFigDialog, qOverload<>(&QDialog::reject));
        QObject::connect(horizontalSliderDimZ, &QSlider::valueChanged, spinBoxDimZ, &QSpinBox::setValue);
        QObject::connect(spinBoxDimZ, &QSpinBox::valueChanged, horizontalSliderDimZ, &QSlider::setValue);
        QObject::connect(horizontalSliderDimY, &QSlider::valueChanged, spinBoxDimY, &QSpinBox::setValue);
        QObject::connect(spinBoxDimY, &QSpinBox::valueChanged, horizontalSliderDimY, &QSlider::setValue);
        QObject::connect(horizontalSliderDimX, &QSlider::sliderMoved, spinBoxDimX, &QSpinBox::setValue);
        QObject::connect(spinBoxDimX, &QSpinBox::valueChanged, horizontalSliderDimX, &QSlider::setValue);

        QMetaObject::connectSlotsByName(NewFigDialog);
    } // setupUi

    void retranslateUi(QDialog *NewFigDialog)
    {
        NewFigDialog->setWindowTitle(QCoreApplication::translate("NewFigDialog", "Dialog", nullptr));
        labelNewFigPic->setText(QString());
        labelDimensionX->setText(QCoreApplication::translate("NewFigDialog", "X Dimension", nullptr));
        labelDimensionY->setText(QCoreApplication::translate("NewFigDialog", "Y Dimension", nullptr));
        labelDimensionZ->setText(QCoreApplication::translate("NewFigDialog", "Z Dimension", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewFigDialog: public Ui_NewFigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFIGDIALOG_H
