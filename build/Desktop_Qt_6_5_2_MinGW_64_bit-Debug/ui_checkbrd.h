/********************************************************************************
** Form generated from reading UI file 'checkbrd.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKBRD_H
#define UI_CHECKBRD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckBrd
{
public:
    QPushButton *Tuichu;
    QPushButton *Regame;
    QPushButton *Pause;
    QPushButton *RenShu;
    QPushButton *Huiqi;
    QLineEdit *Count;
    QLabel *label;
    QLineEdit *Zongshoushu;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *Blackqi;
    QLabel *Whiteqi_2;

    void setupUi(QWidget *CheckBrd)
    {
        if (CheckBrd->objectName().isEmpty())
            CheckBrd->setObjectName("CheckBrd");
        CheckBrd->resize(1291, 815);
        Tuichu = new QPushButton(CheckBrd);
        Tuichu->setObjectName("Tuichu");
        Tuichu->setGeometry(QRect(1170, 10, 111, 61));
        QFont font;
        font.setPointSize(16);
        Tuichu->setFont(font);
        Regame = new QPushButton(CheckBrd);
        Regame->setObjectName("Regame");
        Regame->setGeometry(QRect(900, 320, 131, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font1.setPointSize(22);
        Regame->setFont(font1);
        Pause = new QPushButton(CheckBrd);
        Pause->setObjectName("Pause");
        Pause->setGeometry(QRect(1070, 320, 131, 81));
        Pause->setFont(font1);
        RenShu = new QPushButton(CheckBrd);
        RenShu->setObjectName("RenShu");
        RenShu->setGeometry(QRect(900, 440, 131, 81));
        RenShu->setFont(font1);
        Huiqi = new QPushButton(CheckBrd);
        Huiqi->setObjectName("Huiqi");
        Huiqi->setGeometry(QRect(1070, 440, 131, 81));
        Huiqi->setFont(font1);
        Count = new QLineEdit(CheckBrd);
        Count->setObjectName("Count");
        Count->setGeometry(QRect(900, 210, 131, 61));
        label = new QLabel(CheckBrd);
        label->setObjectName("label");
        label->setGeometry(QRect(920, 170, 101, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font2.setPointSize(20);
        font2.setBold(false);
        label->setFont(font2);
        Zongshoushu = new QLineEdit(CheckBrd);
        Zongshoushu->setObjectName("Zongshoushu");
        Zongshoushu->setGeometry(QRect(1070, 210, 131, 61));
        label_2 = new QLabel(CheckBrd);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1090, 170, 111, 31));
        label_2->setFont(font2);
        lineEdit = new QLineEdit(CheckBrd);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(840, 670, 151, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font3.setPointSize(20);
        lineEdit->setFont(font3);
        lineEdit_2 = new QLineEdit(CheckBrd);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(1120, 670, 151, 71));
        lineEdit_2->setFont(font3);
        label_3 = new QLabel(CheckBrd);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1020, 680, 81, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Poor Richard")});
        font4.setPointSize(36);
        label_3->setFont(font4);
        Blackqi = new QLabel(CheckBrd);
        Blackqi->setObjectName("Blackqi");
        Blackqi->setGeometry(QRect(880, 590, 51, 51));
        Blackqi->setPixmap(QPixmap(QString::fromUtf8(":/image/black.png")));
        Blackqi->setScaledContents(true);
        Whiteqi_2 = new QLabel(CheckBrd);
        Whiteqi_2->setObjectName("Whiteqi_2");
        Whiteqi_2->setEnabled(false);
        Whiteqi_2->setGeometry(QRect(1170, 590, 51, 51));
        Whiteqi_2->setPixmap(QPixmap(QString::fromUtf8(":/image/white.png")));
        Whiteqi_2->setScaledContents(true);

        retranslateUi(CheckBrd);

        QMetaObject::connectSlotsByName(CheckBrd);
    } // setupUi

    void retranslateUi(QWidget *CheckBrd)
    {
        CheckBrd->setWindowTitle(QCoreApplication::translate("CheckBrd", "Form", nullptr));
        Tuichu->setText(QCoreApplication::translate("CheckBrd", "\351\200\200\345\207\272", nullptr));
        Regame->setText(QCoreApplication::translate("CheckBrd", "\345\274\200\345\247\213", nullptr));
        Pause->setText(QCoreApplication::translate("CheckBrd", "\346\232\202\345\201\234", nullptr));
        RenShu->setText(QCoreApplication::translate("CheckBrd", "\350\256\244\350\276\223", nullptr));
        Huiqi->setText(QCoreApplication::translate("CheckBrd", "\351\207\215\345\274\200", nullptr));
        label->setText(QCoreApplication::translate("CheckBrd", "\345\200\222\350\256\241\346\227\266", nullptr));
        label_2->setText(QCoreApplication::translate("CheckBrd", "\346\200\273\346\211\213\346\225\260", nullptr));
        lineEdit->setText(QCoreApplication::translate("CheckBrd", "  \347\216\251\345\256\2661", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("CheckBrd", "  \347\216\251\345\256\2662", nullptr));
        label_3->setText(QCoreApplication::translate("CheckBrd", "VS", nullptr));
        Blackqi->setText(QString());
        Whiteqi_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CheckBrd: public Ui_CheckBrd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKBRD_H
