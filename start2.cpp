#include "start2.h"
#include "ui_start2.h"
#include <qobject.h>
#include<QMediaPlayer>
#include<QtMultimedia/QtMultimedia>
#include<QtMultimediaWidgets/QVideoWidget>
Start2::Start2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Start2)
{
    ui->setupUi(this);
    setWindowTitle("GOBANG");//标题

}

Start2::~Start2()
{
    delete ui;
}

void Start2::paintEvent(QPaintEvent *)
{
    QPixmap backgroundpic(QString(":/image/start2.jpg"));
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(),this->height(), backgroundpic);
}

void Start2::on_pushButton_3_clicked()
{
    Start *w = new Start();
    w->show();
    this->close();
}


void Start2::on_pushButton_clicked()
{
    ck = new CheckBrd();
    ck->show();
    this->close();
    qDebug() << "玩家对战";
}


void Start2::on_pushButton_2_clicked()
{
    ck_ai = new CheckBrd_ai();
    ck_ai->show();
    this->close();
    qDebug() << "人机对战";
}
void CheckBrd_ai::btn_back_clicked(){
    Start2 *w = new Start2();
    w->show();
    this->close();
}
void CheckBrd::btn_back_clicked(){
    Start2 *w = new Start2();
    w->show();
    this->close();
}//返回上一级
void Start2::on_Exit_clicked(){
    Confirm_exit *w = new Confirm_exit();
    w->show();
    this->close();
    return;
    state = EXIT;
    qApp->quit();
    qDebug() << "btn exit!";
}

