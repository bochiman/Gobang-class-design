#include "start1.h"
#include "ui_start1.h"
#include<QMediaPlayer>
#include<QtMultimedia/QtMultimedia>
#include<QtMultimediaWidgets/QVideoWidget>
Start1::Start1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Start1)
{

    QVideoWidget* win1=new QVideoWidget(this);
    win1->resize(1066,600);
    QMediaPlayer *player1=new QMediaPlayer(this);
    player1->setVideoOutput(win1);
    player1->setSource(QUrl::fromLocalFile("F:/Qt project/Gobang_final/Gobang_final/image/genshin2.mp4"));
    player1->play();
    ui->setupUi(this);
}

Start1::~Start1()
{
    delete ui;
}

void Start1::on_pushButton_clicked()
{
    Start2 *w = new Start2();
    w->show();
    this->close();
}

