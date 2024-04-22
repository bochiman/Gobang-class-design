#include "confirm_exit.h"
#include "ui_confirm_exit.h"


Confirm_exit::Confirm_exit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Confirm_exit)
{
    ui->setupUi(this);
    ui->pushButton_3->setIconSize(QSize(100,100));
    ui->pushButton_3->setIcon(QIcon(":/image/exit.png"));
}

Confirm_exit::~Confirm_exit()
{
    delete ui;
}

void Confirm_exit::on_pushButton_clicked()
{
    qApp->quit();
    qDebug() << "btn exit!";
}


void Confirm_exit::on_pushButton_2_clicked()
{
    Start *w = new Start();
    w->show();
    this->close();
}

