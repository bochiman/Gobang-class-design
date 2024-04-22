#include "start.h"
#include "ui_start.h"
#include<QMediaPlayer>
#include<QtMultimedia/QtMultimedia>
#include<QtMultimediaWidgets/QVideoWidget>
#include <iostream>
#include <qobject.h>
Start::Start(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Start)
{
    QVideoWidget* win=new QVideoWidget(this);
    win->resize(1066,600);
    QMediaPlayer *player=new QMediaPlayer(this);
    player->setVideoOutput(win);
    player->setSource(QUrl::fromLocalFile("F:/Qt project/Gobang_final/Gobang_final/image/genshin.mp4"));
    player->play();
    ui->setupUi(this);
    setWindowTitle("GOBANG");//标题
    connect(ui->btn_start_hu, &QPushButton::clicked, this, Start::btn_clicked_HU);
    connect(ui->btn_start_ai, &QPushButton::clicked, this, Start::btn_clicked_AI);
    connect(ui->Exit, &QPushButton::clicked, this, Start::btn_Exit);
    ui->lab_wid_title->setStyleSheet("font-size:60px;color:white");
}

Start::~Start()
{
    delete ui;
}
void Start::btn_clicked_HU(){
    /*ck = new CheckBrd();
    ck->show();
    this->close();
    qDebug() << "玩家对战";*/
}
void Start::btn_clicked_AI(){
   /*ck_ai = new CheckBrd_ai();
    ck_ai->show();
    this->close();
    qDebug() << "人机对战";*/
}

void::Start::btn_Exit(){
    Confirm_exit *w = new Confirm_exit();
    w->show();
    this->close();
    return;
    state = EXIT;
    qApp->quit();
    qDebug() << "btn exit!";
}
/*void CheckBrd_ai::btn_back_clicked(){
    Start *w = new Start();
    w->show();
    this->close();
}
void CheckBrd::btn_back_clicked(){
    Start *w = new Start();
    w->show();
    this->close();
}//返回上一级*/

void Start::paintEvent(QPaintEvent *){
    QPixmap backgroundpic(QString(":/image/2.jpg"));
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(),this->height(), backgroundpic);
}


void Start::on_pushButton_clicked()
{
    Start1 *w = new Start1();
    w->show();
    this->close();

}

