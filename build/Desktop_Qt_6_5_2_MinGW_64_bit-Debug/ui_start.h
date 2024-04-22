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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QPushButton *Exit;
    QLabel *lab_wid_title;
    QPushButton *pushButton;
    QPushButton *btn_start_hu;
    QPushButton *btn_start_ai;

    void setupUi(QWidget *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName("Start");
        Start->resize(1066, 600);
        Start->setMinimumSize(QSize(731, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/paimeng1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Start->setWindowIcon(icon);
        Exit = new QPushButton(Start);
        Exit->setObjectName("Exit");
        Exit->setGeometry(QRect(20, 500, 101, 81));
        QFont font;
        font.setPointSize(18);
        Exit->setFont(font);
        Exit->setFlat(true);
        lab_wid_title = new QLabel(Start);
        lab_wid_title->setObjectName("lab_wid_title");
        lab_wid_title->setGeometry(QRect(410, 100, 281, 111));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Papyrus")});
        font1.setPointSize(50);
        lab_wid_title->setFont(font1);
        pushButton = new QPushButton(Start);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(360, 510, 361, 71));
        pushButton->setFlat(true);
        btn_start_hu = new QPushButton(Start);
        btn_start_hu->setObjectName("btn_start_hu");
        btn_start_hu->setGeometry(QRect(910, 20, 16, 23));
        btn_start_hu->setFlat(true);
        btn_start_ai = new QPushButton(Start);
        btn_start_ai->setObjectName("btn_start_ai");
        btn_start_ai->setGeometry(QRect(795, 30, 20, 23));
        btn_start_ai->setFlat(true);

        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QWidget *Start)
    {
        Start->setWindowTitle(QCoreApplication::translate("Start", "Form", nullptr));
        Exit->setText(QString());
        lab_wid_title->setText(QCoreApplication::translate("Start", "\345\216\237\346\260\224\346\243\213\345\243\253", nullptr));
        pushButton->setText(QString());
        btn_start_hu->setText(QString());
        btn_start_ai->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
