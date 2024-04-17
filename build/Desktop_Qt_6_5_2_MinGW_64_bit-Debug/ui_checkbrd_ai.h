/********************************************************************************
** Form generated from reading UI file 'checkbrd_ai.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKBRD_AI_H
#define UI_CHECKBRD_AI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Checkbrd_AI
{
public:
    QPushButton *Tuichu;
    QLineEdit *lineEdit_2;
    QLineEdit *Zongshoushu;
    QLabel *label_3;
    QLineEdit *Count;
    QLineEdit *lineEdit;
    QLabel *Blackqi;
    QLabel *label_2;
    QPushButton *Pause;
    QLabel *label;
    QPushButton *Huiqi;
    QPushButton *Regame;
    QLabel *Whiteqi_2;
    QPushButton *RenShu;
    QCheckBox *blackai;
    QCheckBox *whiteai;

    void setupUi(QWidget *Checkbrd_AI)
    {
        if (Checkbrd_AI->objectName().isEmpty())
            Checkbrd_AI->setObjectName("Checkbrd_AI");
        Checkbrd_AI->resize(1291, 815);
        Tuichu = new QPushButton(Checkbrd_AI);
        Tuichu->setObjectName("Tuichu");
        Tuichu->setGeometry(QRect(1150, 30, 111, 61));
        QFont font;
        font.setPointSize(16);
        Tuichu->setFont(font);
        lineEdit_2 = new QLineEdit(Checkbrd_AI);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(1120, 690, 151, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font1.setPointSize(20);
        lineEdit_2->setFont(font1);
        Zongshoushu = new QLineEdit(Checkbrd_AI);
        Zongshoushu->setObjectName("Zongshoushu");
        Zongshoushu->setGeometry(QRect(1080, 140, 131, 61));
        label_3 = new QLabel(Checkbrd_AI);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1020, 700, 81, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Poor Richard")});
        font2.setPointSize(36);
        label_3->setFont(font2);
        Count = new QLineEdit(Checkbrd_AI);
        Count->setObjectName("Count");
        Count->setGeometry(QRect(910, 140, 131, 61));
        lineEdit = new QLineEdit(Checkbrd_AI);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(840, 690, 151, 71));
        lineEdit->setFont(font1);
        Blackqi = new QLabel(Checkbrd_AI);
        Blackqi->setObjectName("Blackqi");
        Blackqi->setGeometry(QRect(880, 610, 51, 51));
        Blackqi->setPixmap(QPixmap(QString::fromUtf8(":/image/black.png")));
        Blackqi->setScaledContents(true);
        label_2 = new QLabel(Checkbrd_AI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1100, 100, 111, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font3.setPointSize(20);
        font3.setBold(false);
        label_2->setFont(font3);
        Pause = new QPushButton(Checkbrd_AI);
        Pause->setObjectName("Pause");
        Pause->setGeometry(QRect(1080, 250, 131, 81));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font4.setPointSize(22);
        Pause->setFont(font4);
        label = new QLabel(Checkbrd_AI);
        label->setObjectName("label");
        label->setGeometry(QRect(930, 100, 101, 31));
        label->setFont(font3);
        Huiqi = new QPushButton(Checkbrd_AI);
        Huiqi->setObjectName("Huiqi");
        Huiqi->setGeometry(QRect(1080, 370, 131, 81));
        Huiqi->setFont(font4);
        Regame = new QPushButton(Checkbrd_AI);
        Regame->setObjectName("Regame");
        Regame->setGeometry(QRect(910, 250, 131, 81));
        Regame->setFont(font4);
        Whiteqi_2 = new QLabel(Checkbrd_AI);
        Whiteqi_2->setObjectName("Whiteqi_2");
        Whiteqi_2->setEnabled(false);
        Whiteqi_2->setGeometry(QRect(1170, 610, 51, 51));
        Whiteqi_2->setPixmap(QPixmap(QString::fromUtf8(":/image/white.png")));
        Whiteqi_2->setScaledContents(true);
        RenShu = new QPushButton(Checkbrd_AI);
        RenShu->setObjectName("RenShu");
        RenShu->setGeometry(QRect(910, 370, 131, 81));
        RenShu->setFont(font4);
        blackai = new QCheckBox(Checkbrd_AI);
        blackai->setObjectName("blackai");
        blackai->setEnabled(true);
        blackai->setGeometry(QRect(950, 530, 111, 31));
        blackai->setFont(font);
        whiteai = new QCheckBox(Checkbrd_AI);
        whiteai->setObjectName("whiteai");
        whiteai->setEnabled(true);
        whiteai->setGeometry(QRect(1120, 520, 98, 51));
        whiteai->setFont(font);

        retranslateUi(Checkbrd_AI);

        QMetaObject::connectSlotsByName(Checkbrd_AI);
    } // setupUi

    void retranslateUi(QWidget *Checkbrd_AI)
    {
        Checkbrd_AI->setWindowTitle(QCoreApplication::translate("Checkbrd_AI", "Form", nullptr));
        Tuichu->setText(QCoreApplication::translate("Checkbrd_AI", "\351\200\200\345\207\272", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Checkbrd_AI", "  \347\216\251\345\256\2662", nullptr));
        label_3->setText(QCoreApplication::translate("Checkbrd_AI", "VS", nullptr));
        lineEdit->setText(QCoreApplication::translate("Checkbrd_AI", "  \347\216\251\345\256\2661", nullptr));
        Blackqi->setText(QString());
        label_2->setText(QCoreApplication::translate("Checkbrd_AI", "\346\200\273\346\211\213\346\225\260", nullptr));
        Pause->setText(QCoreApplication::translate("Checkbrd_AI", "\346\232\202\345\201\234", nullptr));
        label->setText(QCoreApplication::translate("Checkbrd_AI", "\345\200\222\350\256\241\346\227\266", nullptr));
        Huiqi->setText(QCoreApplication::translate("Checkbrd_AI", "\351\207\215\345\274\200", nullptr));
        Regame->setText(QCoreApplication::translate("Checkbrd_AI", "\345\274\200\345\247\213", nullptr));
        Whiteqi_2->setText(QString());
        RenShu->setText(QCoreApplication::translate("Checkbrd_AI", "\350\256\244\350\276\223", nullptr));
        blackai->setText(QCoreApplication::translate("Checkbrd_AI", "AI\351\273\221", nullptr));
        whiteai->setText(QCoreApplication::translate("Checkbrd_AI", "AI\347\231\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Checkbrd_AI: public Ui_Checkbrd_AI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKBRD_AI_H
