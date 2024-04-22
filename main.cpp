#include "start.h"

#include <QApplication>
#include <QMediaPlayer>
#include <QUrl>
#include<QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QMediaPlayer *player = new QMediaPlayer;
    //player->setSource(QUrl::fromLocalFile(QString(":/image/genshin.mp4")));
    //player->play();
    Start w;
    w.show();
    return a.exec();
}
