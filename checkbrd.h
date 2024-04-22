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
class Piece;
namespace Ui {
class CheckBrd;
}

class CheckBrd : public QWidget
{
    Q_OBJECT

public:
    enum ChessType {null, black, white};
    explicit CheckBrd(QWidget *parent = nullptr);
    ~CheckBrd();
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
    //void get_btn_sign(int idx);//为了不给每个按钮写个函数，就通过传递按钮的坐标来起到对应的按钮反应
    void btn_regame_clicked();//重开游戏
    void btn_back_clicked();//返回上一级
    int get_idx(int idx);
    void set_time(int seted_time = 50);//设置倒计时时间
    void BeginCountdown();//打开计时器
    void OnTimerCountdown();//输出倒计时
    void delete_time();//删除计时器
    void play_the_Go();//绘制棋盘，其实就是把对应的按钮画成黑棋或白棋
    int judge(int x, int y);//在每次落子后判断有无胜负,若会吃子或紫砂则传回no，反之则传yes
    void clear_pan();//恢复棋盘初始状态，包括清屏,清空气,重设时间
    void init();//初始化棋盘
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
private slots:
    void on_help_black_clicked();

    void on_help_white_clicked();

private:
    int chessNumcalPart(int polarityW, int polarityY, int x, int y);
    bool chessNumcalAll(int polarityW1, int polarityY1, int polarityW2, int polarityY2, int x, int y);
    Ui::CheckBrd *ui;
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
    std::vector<std::vector<int>>  ScoreMap; //AI得分表
    ChessType currentChess;
    ChessType chessOnboard[15][15];
    std::list<Piece> blackPieces;//黑棋链表
    std::list<Piece> whitePieces;
    bool checkFiveInRow(const std::list<Piece>& pieces, int new_row, int new_col);//判断胜负
    //统计各个方向的同色棋数
    int count(bool exit, int orientation, const std::list<Piece>& pieces, int new_row, int new_col);
    //遍历函数：输入行，列以及piece链表
    bool findPiece(int row, int col, const std::list<Piece>& pieces) const;
    //判断赢家
    //清空链表
    void clearBoard();
    void placePiece(int row, int col, ChessType chess);
};
class Piece
{
public:
    int row;
    int col;
    Piece(int r, int c) :row(r), col(c){}
};
#endif // CHECKBRD_H
