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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckBrd
{
public:
    QLineEdit *Count;
    QPushButton *Regame;
    QLabel *label_2;
    QPushButton *Start;
    QPushButton *RenShu;
    QLineEdit *Zongshoushu;
    QPushButton *Pause;
    QPushButton *Tuichu;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *player2;
    QLineEdit *player1;
    QPushButton *player1_img;
    QPushButton *player2_img;
    QCheckBox *checkBox;
    QPushButton *help_black;
    QPushButton *help_white;

    void setupUi(QWidget *CheckBrd)
    {
        if (CheckBrd->objectName().isEmpty())
            CheckBrd->setObjectName("CheckBrd");
        CheckBrd->resize(1291, 850);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/paimeng1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        CheckBrd->setWindowIcon(icon);
        Count = new QLineEdit(CheckBrd);
        Count->setObjectName("Count");
        Count->setGeometry(QRect(890, 150, 131, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tw Cen MT Condensed Extra Bold")});
        font.setPointSize(24);
        Count->setFont(font);
        Count->setAlignment(Qt::AlignCenter);
        Regame = new QPushButton(CheckBrd);
        Regame->setObjectName("Regame");
        Regame->setGeometry(QRect(1060, 380, 131, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font1.setPointSize(22);
        Regame->setFont(font1);
        label_2 = new QLabel(CheckBrd);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1080, 110, 111, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font2.setPointSize(20);
        font2.setBold(false);
        label_2->setFont(font2);
        Start = new QPushButton(CheckBrd);
        Start->setObjectName("Start");
        Start->setGeometry(QRect(890, 260, 131, 81));
        Start->setFont(font1);
        RenShu = new QPushButton(CheckBrd);
        RenShu->setObjectName("RenShu");
        RenShu->setGeometry(QRect(890, 380, 131, 81));
        RenShu->setFont(font1);
        Zongshoushu = new QLineEdit(CheckBrd);
        Zongshoushu->setObjectName("Zongshoushu");
        Zongshoushu->setGeometry(QRect(1060, 150, 131, 61));
        Zongshoushu->setFont(font);
        Zongshoushu->setAlignment(Qt::AlignCenter);
        Pause = new QPushButton(CheckBrd);
        Pause->setObjectName("Pause");
        Pause->setGeometry(QRect(1060, 260, 131, 81));
        Pause->setFont(font1);
        Tuichu = new QPushButton(CheckBrd);
        Tuichu->setObjectName("Tuichu");
        Tuichu->setGeometry(QRect(1160, 20, 111, 61));
        QFont font3;
        font3.setPointSize(16);
        Tuichu->setFont(font3);
        label = new QLabel(CheckBrd);
        label->setObjectName("label");
        label->setGeometry(QRect(910, 110, 101, 31));
        label->setFont(font2);
        label_3 = new QLabel(CheckBrd);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1010, 650, 81, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Poor Richard")});
        font4.setPointSize(36);
        label_3->setFont(font4);
        player2 = new QLineEdit(CheckBrd);
        player2->setObjectName("player2");
        player2->setGeometry(QRect(1110, 640, 151, 71));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font5.setPointSize(20);
        player2->setFont(font5);
        player2->setAlignment(Qt::AlignCenter);
        player1 = new QLineEdit(CheckBrd);
        player1->setObjectName("player1");
        player1->setGeometry(QRect(830, 640, 151, 71));
        player1->setFont(font5);
        player1->setAlignment(Qt::AlignCenter);
        player1_img = new QPushButton(CheckBrd);
        player1_img->setObjectName("player1_img");
        player1_img->setGeometry(QRect(860, 540, 93, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/black.png"), QSize(), QIcon::Normal, QIcon::Off);
        player1_img->setIcon(icon1);
        player1_img->setIconSize(QSize(40, 40));
        player1_img->setFlat(true);
        player2_img = new QPushButton(CheckBrd);
        player2_img->setObjectName("player2_img");
        player2_img->setGeometry(QRect(1140, 540, 93, 71));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/white.png"), QSize(), QIcon::Normal, QIcon::Off);
        player2_img->setIcon(icon2);
        player2_img->setIconSize(QSize(40, 40));
        player2_img->setFlat(true);
        checkBox = new QCheckBox(CheckBrd);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(1010, 500, 98, 23));
        help_black = new QPushButton(CheckBrd);
        help_black->setObjectName("help_black");
        help_black->setEnabled(true);
        help_black->setGeometry(QRect(850, 730, 111, 91));
        help_black->setFlat(true);
        help_white = new QPushButton(CheckBrd);
        help_white->setObjectName("help_white");
        help_white->setGeometry(QRect(1140, 730, 101, 91));
        help_white->setFlat(true);

        retranslateUi(CheckBrd);

        QMetaObject::connectSlotsByName(CheckBrd);
    } // setupUi

    void retranslateUi(QWidget *CheckBrd)
    {
        CheckBrd->setWindowTitle(QCoreApplication::translate("CheckBrd", "goban", nullptr));
        Count->setText(QCoreApplication::translate("CheckBrd", "60", nullptr));
        Regame->setText(QCoreApplication::translate("CheckBrd", "\351\207\215\345\274\200", nullptr));
        label_2->setText(QCoreApplication::translate("CheckBrd", "\346\200\273\346\211\213\346\225\260", nullptr));
        Start->setText(QCoreApplication::translate("CheckBrd", "\345\274\200\345\247\213", nullptr));
        RenShu->setText(QCoreApplication::translate("CheckBrd", "\350\256\244\350\276\223", nullptr));
        Zongshoushu->setText(QCoreApplication::translate("CheckBrd", "0", nullptr));
        Pause->setText(QCoreApplication::translate("CheckBrd", "\346\232\202\345\201\234", nullptr));
        Tuichu->setText(QCoreApplication::translate("CheckBrd", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("CheckBrd", "\345\200\222\350\256\241\346\227\266", nullptr));
        label_3->setText(QCoreApplication::translate("CheckBrd", "VS", nullptr));
        player2->setText(QCoreApplication::translate("CheckBrd", "\347\216\251\345\256\2662", nullptr));
        player1->setText(QCoreApplication::translate("CheckBrd", "\347\216\251\345\256\2661", nullptr));
        player1_img->setText(QString());
        player2_img->setText(QString());
        checkBox->setText(QCoreApplication::translate("CheckBrd", "\350\220\275\345\255\220\345\211\215\347\241\256\350\256\244", nullptr));
        help_black->setText(QString());
        help_white->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CheckBrd: public Ui_CheckBrd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKBRD_H
