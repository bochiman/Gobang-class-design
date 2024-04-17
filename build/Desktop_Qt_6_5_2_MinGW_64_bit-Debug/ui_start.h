/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QPushButton *btn_start_hu;
    QPushButton *btn_start_ai;
    QPushButton *Exit;

    void setupUi(QWidget *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName("Start");
        Start->setEnabled(true);
        Start->resize(743, 642);
        Start->setAcceptDrops(false);
        btn_start_hu = new QPushButton(Start);
        btn_start_hu->setObjectName("btn_start_hu");
        btn_start_hu->setGeometry(QRect(180, 360, 161, 101));
        QFont font;
        font.setPointSize(14);
        btn_start_hu->setFont(font);
        btn_start_ai = new QPushButton(Start);
        btn_start_ai->setObjectName("btn_start_ai");
        btn_start_ai->setGeometry(QRect(370, 360, 161, 101));
        btn_start_ai->setFont(font);
        Exit = new QPushButton(Start);
        Exit->setObjectName("Exit");
        Exit->setGeometry(QRect(250, 500, 211, 81));
        QFont font1;
        font1.setPointSize(18);
        Exit->setFont(font1);

        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QWidget *Start)
    {
        Start->setWindowTitle(QCoreApplication::translate("Start", "Form", nullptr));
        btn_start_hu->setText(QCoreApplication::translate("Start", "\347\216\251\345\256\266\345\257\271\346\210\230", nullptr));
        btn_start_ai->setText(QCoreApplication::translate("Start", "\344\272\272\346\234\272\345\257\271\346\210\230", nullptr));
        Exit->setText(QCoreApplication::translate("Start", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
