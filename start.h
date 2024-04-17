#ifndef START_H
#define START_H

#include <QMainWindow>
#include <QWidget>
#include <checkbrd.h>
#include <checkbrd_ai.h>
#include <qobject.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class Start;
}
QT_END_NAMESPACE

class Start : public QWidget
{
    Q_OBJECT

public:
    Start(QWidget *parent = nullptr);
    ~Start();
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
    void btn_clicked_HU();//进入人人对战
    void btn_clicked_AI();//进入人机对战
    void btn_Exit();
private:
    Ui::Start *ui;
    CheckBrd *ck = nullptr;
    Checkbrd_AI *ck_ai = nullptr;
    RunState state;
};
#endif // START_H
