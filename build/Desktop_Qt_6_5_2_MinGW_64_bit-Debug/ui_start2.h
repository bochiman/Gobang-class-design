/********************************************************************************
** Form generated from reading UI file 'start2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START2_H
#define UI_START2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start2
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Start2)
    {
        if (Start2->objectName().isEmpty())
            Start2->setObjectName("Start2");
        Start2->resize(1066, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/paimeng1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Start2->setWindowIcon(icon);
        pushButton = new QPushButton(Start2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 390, 101, 51));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(Start2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(640, 390, 101, 51));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(Start2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 520, 61, 61));
        pushButton_3->setFlat(true);

        retranslateUi(Start2);

        QMetaObject::connectSlotsByName(Start2);
    } // setupUi

    void retranslateUi(QWidget *Start2)
    {
        Start2->setWindowTitle(QCoreApplication::translate("Start2", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Start2", "\347\216\251\345\256\266\345\257\271\346\210\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Start2", "\344\272\272\346\234\272\345\257\271\346\210\230", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Start2", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start2: public Ui_Start2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START2_H
