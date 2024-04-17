#ifndef CHECKBRD_H
#define CHECKBRD_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
#include <QDebug>
#include <QImage>
#include <QTimer>
#include <qsignalmapper.h>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include <QPainter>
#include <QDebug>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>
#include <QFile>
#include <QFileDialog>
#include <qcheckbox.h>
#include <QCheckBox>
#include <QLabel>
#include <qobject.h>
namespace Ui {
class CheckBrd;
}

class CheckBrd : public QWidget
{
    Q_OBJECT

public:
    enum ChessType {noChess, blackChess, whiteChess};
    explicit CheckBrd(QWidget *parent = nullptr);
    ~CheckBrd();
    const int x = 55;
    const int y = 55;
    const int size = 50;
protected:
    void paintEvent(QPaintEvent *e);//绘制棋盘
    QPainter *paint;
protected slots:
    void btn_startgame_clicked();//开始游戏
    void btn_stop_clicked();//暂停游戏，如果已经暂停了就开始
    void btn_Renshu();//认输
    //void get_btn_sign(int idx);//为了不给每个按钮写个函数，就通过传递按钮的坐标来起到对应的按钮反应
    void btn_regame_clicked();//重开游戏
    void btn_back_clicked();//返回上一级
    void btn_Huiqi();//悔棋
    int get_idx(int idx);
    void set_time(int seted_time = 50);//设置倒计时时间
    void BeginCountdown();//打开计时器
    void OnTimerCountdown();//输出倒计时
    void delete_time();//删除计时器
    void play_the_Go(QPushButton *now_btn,QPushButton *last_btn);//绘制棋盘，其实就是把对应的按钮画成黑棋或白棋
    int judge(int idx);//在每次落子后判断有无胜负,若会吃子或紫砂则传回no，反之则传yes
    void clear_pan();//恢复棋盘初始状态，包括清屏,清空气,重设时间
private:
    Ui::CheckBrd *ui;
    int const length =15;
    int topW;
    int topH;
    int chequerSide;
    int chessSide;
    int chequerNumOfLine;   // 棋盘一行格子数
    int rangeCenter;        // 落棋点范围
    bool dropChessEnable;   // 落棋使能
    bool dropedFlag;
    int dropW;              // 落棋行
    int dropH;
};

#endif // CHECKBRD_H
