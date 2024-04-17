#include "start.h"
#include "ui_start.h"
#include <iostream>
#include <qobject.h>
Start::Start(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Start)
{
    ui->setupUi(this);
    setWindowTitle("GOBANG");//标题
    connect(ui->btn_start_hu, &QPushButton::clicked, this, Start::btn_clicked_HU);
    connect(ui->btn_start_ai, &QPushButton::clicked, this, Start::btn_clicked_AI);
    connect(ui->Exit, &QPushButton::clicked, this, Start::btn_Exit);
}

Start::~Start()
{
    delete ui;
}
void Start::btn_clicked_HU(){
    ck = new CheckBrd();
    ck->show();
    this->close();
    qDebug() << "玩家对战";
}
void Start::btn_clicked_AI(){
    ck_ai = new Checkbrd_AI();
    ck_ai->show();
    this->close();
    qDebug() << "人机对战";
}
void CheckBrd::btn_back_clicked(){
    Start *w = new Start();
    w->show();
    this->close();
}//返回上一级
void::Start::btn_Exit(){
    state = EXIT;
    qApp->quit();
    qDebug() << "btn exit!";
}
void Checkbrd_AI::btn_back_clicked_AI(){
    Start *w = new Start();
    w->show();
    this->close();
}
