/********************************************************************************
** Form generated from reading UI file 'confirm_exit.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRM_EXIT_H
#define UI_CONFIRM_EXIT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Confirm_exit
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Confirm_exit)
    {
        if (Confirm_exit->objectName().isEmpty())
            Confirm_exit->setObjectName("Confirm_exit");
        Confirm_exit->resize(333, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/paimeng1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Confirm_exit->setWindowIcon(icon);
        pushButton = new QPushButton(Confirm_exit);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 220, 75, 23));
        pushButton_2 = new QPushButton(Confirm_exit);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 220, 75, 23));
        label = new QLabel(Confirm_exit);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 60, 71, 21));
        pushButton_3 = new QPushButton(Confirm_exit);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(100, 90, 131, 101));
        pushButton_3->setFlat(true);

        retranslateUi(Confirm_exit);

        QMetaObject::connectSlotsByName(Confirm_exit);
    } // setupUi

    void retranslateUi(QDialog *Confirm_exit)
    {
        Confirm_exit->setWindowTitle(QCoreApplication::translate("Confirm_exit", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Confirm_exit", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Confirm_exit", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("Confirm_exit", "\350\246\201\347\246\273\345\274\200\344\272\206\345\220\227", nullptr));
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Confirm_exit: public Ui_Confirm_exit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRM_EXIT_H
