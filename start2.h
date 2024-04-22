#ifndef START2_H
#define START2_H



#include <QMainWindow>
#include <QWidget>
#include <ui_start.h>
#include <start.h>
#include <start1.h>
#include <checkbrd.h>
#include <checkbrd_ai.h>
#include<confirm_exit.h>
#include <qobject.h>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
namespace Ui {
class Start2;
}
QT_END_NAMESPACE
class Start2 : public QWidget
{
    Q_OBJECT

public:
    explicit Start2(QWidget *parent = nullptr);
    ~Start2();
    enum RunState {NO_RUNNING, START, RUNNING, GAME_OVER,RESTART,EXIT, AI_ON, AI_OFF};
    enum Chess
    {
        black=-1,blank,white
    }chess;//母棋盘中每个子是前三个状态中的一个，子棋盘中loseQi_or_unchecked指还没检查或检查后没气的，
    enum Player_state
    {
        black_player=-1,white_player =1
    }player_state;
    enum WINLOSE
    {
        no,yes
    }winlose;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_Exit_clicked();
private:
    Ui::Start2 *ui;
    CheckBrd *ck = nullptr;
    CheckBrd_ai *ck_ai = nullptr;
    RunState state;
protected:
    void paintEvent(QPaintEvent *e);//绘制棋盘
    QPainter *paint;
};

#endif // START2_H
