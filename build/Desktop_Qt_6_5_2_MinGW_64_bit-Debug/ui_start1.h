/********************************************************************************
** Form generated from reading UI file 'start1.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START1_H
#define UI_START1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start1
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *Start1)
    {
        if (Start1->objectName().isEmpty())
            Start1->setObjectName("Start1");
        Start1->resize(1066, 600);
        pushButton = new QPushButton(Start1);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 90, 871, 491));

        retranslateUi(Start1);

        QMetaObject::connectSlotsByName(Start1);
    } // setupUi

    void retranslateUi(QWidget *Start1)
    {
        Start1->setWindowTitle(QCoreApplication::translate("Start1", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Start1", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start1: public Ui_Start1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START1_H
