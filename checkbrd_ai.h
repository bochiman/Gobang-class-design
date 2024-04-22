#ifndef CHECKBRD_AI_H
#define CHECKBRD_AI_H

#include <QWidget>
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
#include <vector>

struct ChessPos
{
    int row;
    int col;
};
namespace Ui {
class CheckBrd_ai;
}

class CheckBrd_ai : public QWidget
{
    Q_OBJECT

public:
    enum ChessType {null, black, white};
    explicit CheckBrd_ai(QWidget *parent = nullptr);
    ~CheckBrd_ai();
    const int x = 55;
    const int y = 55;
    const int size = 50;
protected:
    void paintEvent(QPaintEvent *e);//绘制棋盘
    QPainter *paint;
    enum STATE{on, off, pause}state=off;
    QTimer *tm;
protected slots:
    void btn_startgame_clicked();//开始游戏
    void btn_stop_clicked();//暂停游戏，如果已经暂停了就开始
    void btn_Renshu();//认输
    void btn_regame_clicked();//重开游戏
    void btn_back_clicked();//返回上一级
    int get_idx(int idx);
    void set_time(int seted_time = 50);//设置倒计时时间
    void BeginCountdown();//打开计时器
    void OnTimerCountdown();//输出倒计时
    void delete_time();//删除计时器
    void play_the_Go();//绘制棋盘，其实就是把对应的按钮画成黑棋或白棋
    int judge(int x, int y);//在每次落子后判断有无胜负
    void clear_pan();//恢复棋盘初始状态，
    void init();//初始化棋盘
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void chooseAI();
    ChessPos MaxScore();
private slots:


     void on_help_black_clicked();

     void on_help_white_clicked();

 private:

    void calculateScore();
    std::vector<std::vector<int>>  ScoreMap;
    int chessNumcalPart(int polarityW, int polarityY, int x, int y);
    bool chessNumcalAll(int polarityW1, int polarityY1, int polarityW2, int polarityY2, int x, int y);
    void AIplay();
    Ui::CheckBrd_ai *ui;
    int const length =15;
    int chessSide=40;
    int rangeCenter=15;        // 落棋点范围
    bool dropChessEnable;   // 落棋使能
    bool dropedFlag;
    int dropX;              // 落棋行
    int dropY;
    int timenow;
    int game_max_time;
    int step=0;
    int LastX;//最后一步棋的坐标
    int LastY;
    friend class AI;
    ChessType AIstate;
    ChessType currentChess;
    ChessType chessOnboard[15][15];
};

#endif // CHECKBRD_AI_H
