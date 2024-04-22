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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckBrd_ai
{
public:
    QLineEdit *player1;
    QLabel *label_3;
    QPushButton *Pause;
    QPushButton *Start;
    QPushButton *RenShu;
    QPushButton *player2_img;
    QPushButton *Regame;
    QPushButton *player1_img;
    QLineEdit *player2;
    QLabel *label;
    QLineEdit *Zongshoushu;
    QPushButton *Tuichu;
    QLineEdit *Count;
    QLabel *label_2;
    QCheckBox *ai_enable_1;
    QCheckBox *ai_enable_2;
    QCheckBox *ai_enable_3;
    QPushButton *help_black;
    QPushButton *help_white;

    void setupUi(QWidget *CheckBrd_ai)
    {
        if (CheckBrd_ai->objectName().isEmpty())
            CheckBrd_ai->setObjectName("CheckBrd_ai");
        CheckBrd_ai->resize(1291, 850);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/paimeng1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        CheckBrd_ai->setWindowIcon(icon);
        player1 = new QLineEdit(CheckBrd_ai);
        player1->setObjectName("player1");
        player1->setGeometry(QRect(840, 620, 151, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font.setPointSize(20);
        player1->setFont(font);
        player1->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(CheckBrd_ai);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1020, 630, 81, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Poor Richard")});
        font1.setPointSize(36);
        label_3->setFont(font1);
        Pause = new QPushButton(CheckBrd_ai);
        Pause->setObjectName("Pause");
        Pause->setGeometry(QRect(1060, 240, 131, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font2.setPointSize(22);
        Pause->setFont(font2);
        Start = new QPushButton(CheckBrd_ai);
        Start->setObjectName("Start");
        Start->setGeometry(QRect(890, 240, 131, 81));
        Start->setFont(font2);
        RenShu = new QPushButton(CheckBrd_ai);
        RenShu->setObjectName("RenShu");
        RenShu->setGeometry(QRect(890, 360, 131, 81));
        RenShu->setFont(font2);
        player2_img = new QPushButton(CheckBrd_ai);
        player2_img->setObjectName("player2_img");
        player2_img->setGeometry(QRect(1140, 520, 93, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/white.png"), QSize(), QIcon::Normal, QIcon::Off);
        player2_img->setIcon(icon1);
        player2_img->setIconSize(QSize(40, 40));
        player2_img->setFlat(true);
        Regame = new QPushButton(CheckBrd_ai);
        Regame->setObjectName("Regame");
        Regame->setGeometry(QRect(1060, 360, 131, 81));
        Regame->setFont(font2);
        player1_img = new QPushButton(CheckBrd_ai);
        player1_img->setObjectName("player1_img");
        player1_img->setGeometry(QRect(860, 520, 93, 71));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/black.png"), QSize(), QIcon::Normal, QIcon::Off);
        player1_img->setIcon(icon2);
        player1_img->setIconSize(QSize(40, 40));
        player1_img->setFlat(true);
        player2 = new QLineEdit(CheckBrd_ai);
        player2->setObjectName("player2");
        player2->setGeometry(QRect(1120, 620, 151, 71));
        player2->setFont(font);
        player2->setAlignment(Qt::AlignCenter);
        label = new QLabel(CheckBrd_ai);
        label->setObjectName("label");
        label->setGeometry(QRect(910, 90, 101, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font3.setPointSize(20);
        font3.setBold(false);
        label->setFont(font3);
        Zongshoushu = new QLineEdit(CheckBrd_ai);
        Zongshoushu->setObjectName("Zongshoushu");
        Zongshoushu->setGeometry(QRect(1060, 130, 131, 61));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Tw Cen MT Condensed Extra Bold")});
        font4.setPointSize(24);
        Zongshoushu->setFont(font4);
        Zongshoushu->setAlignment(Qt::AlignCenter);
        Tuichu = new QPushButton(CheckBrd_ai);
        Tuichu->setObjectName("Tuichu");
        Tuichu->setGeometry(QRect(1160, 20, 111, 61));
        QFont font5;
        font5.setPointSize(16);
        Tuichu->setFont(font5);
        Count = new QLineEdit(CheckBrd_ai);
        Count->setObjectName("Count");
        Count->setGeometry(QRect(890, 130, 131, 61));
        Count->setFont(font4);
        Count->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(CheckBrd_ai);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1080, 90, 111, 31));
        label_2->setFont(font3);
        ai_enable_1 = new QCheckBox(CheckBrd_ai);
        ai_enable_1->setObjectName("ai_enable_1");
        ai_enable_1->setGeometry(QRect(890, 480, 61, 31));
        QFont font6;
        font6.setPointSize(14);
        ai_enable_1->setFont(font6);
        ai_enable_2 = new QCheckBox(CheckBrd_ai);
        ai_enable_2->setObjectName("ai_enable_2");
        ai_enable_2->setGeometry(QRect(1020, 480, 61, 31));
        ai_enable_2->setFont(font6);
        ai_enable_3 = new QCheckBox(CheckBrd_ai);
        ai_enable_3->setObjectName("ai_enable_3");
        ai_enable_3->setGeometry(QRect(1140, 480, 121, 31));
        ai_enable_3->setFont(font6);
        help_black = new QPushButton(CheckBrd_ai);
        help_black->setObjectName("help_black");
        help_black->setGeometry(QRect(840, 710, 151, 111));
        help_black->setFlat(true);
        help_white = new QPushButton(CheckBrd_ai);
        help_white->setObjectName("help_white");
        help_white->setGeometry(QRect(1130, 710, 141, 111));
        help_white->setFlat(true);

        retranslateUi(CheckBrd_ai);

        QMetaObject::connectSlotsByName(CheckBrd_ai);
    } // setupUi

    void retranslateUi(QWidget *CheckBrd_ai)
    {
        CheckBrd_ai->setWindowTitle(QCoreApplication::translate("CheckBrd_ai", "Form", nullptr));
        player1->setText(QCoreApplication::translate("CheckBrd_ai", "\347\216\251\345\256\2661", nullptr));
        label_3->setText(QCoreApplication::translate("CheckBrd_ai", "VS", nullptr));
        Pause->setText(QCoreApplication::translate("CheckBrd_ai", "\346\232\202\345\201\234", nullptr));
        Start->setText(QCoreApplication::translate("CheckBrd_ai", "\345\274\200\345\247\213", nullptr));
        RenShu->setText(QCoreApplication::translate("CheckBrd_ai", "\350\256\244\350\276\223", nullptr));
        player2_img->setText(QString());
        Regame->setText(QCoreApplication::translate("CheckBrd_ai", "\351\207\215\345\274\200", nullptr));
        player1_img->setText(QString());
        player2->setText(QCoreApplication::translate("CheckBrd_ai", "\347\216\251\345\256\2662", nullptr));
        label->setText(QCoreApplication::translate("CheckBrd_ai", "\345\200\222\350\256\241\346\227\266", nullptr));
        Zongshoushu->setText(QCoreApplication::translate("CheckBrd_ai", "0", nullptr));
        Tuichu->setText(QCoreApplication::translate("CheckBrd_ai", "\351\200\200\345\207\272", nullptr));
        Count->setText(QCoreApplication::translate("CheckBrd_ai", "60", nullptr));
        label_2->setText(QCoreApplication::translate("CheckBrd_ai", "\346\200\273\346\211\213\346\225\260", nullptr));
        ai_enable_1->setText(QCoreApplication::translate("CheckBrd_ai", "AI\351\273\221", nullptr));
        ai_enable_2->setText(QCoreApplication::translate("CheckBrd_ai", "AI\347\231\275", nullptr));
        ai_enable_3->setText(QCoreApplication::translate("CheckBrd_ai", "\350\220\275\345\255\220\345\211\215\347\241\256\350\256\244", nullptr));
        help_black->setText(QString());
        help_white->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CheckBrd_ai: public Ui_CheckBrd_ai {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKBRD_AI_H
