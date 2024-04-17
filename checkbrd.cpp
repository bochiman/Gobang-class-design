#include "checkbrd.h"
#include "ui_checkbrd.h"

CheckBrd::CheckBrd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CheckBrd)
{

    ui->setupUi(this);
    setWindowTitle("GOBANG");//标题
    connect(ui->Tuichu, &QPushButton::clicked, this, CheckBrd::btn_back_clicked);
}

CheckBrd::~CheckBrd()
{
    delete ui;
}
void CheckBrd::paintEvent(QPaintEvent *){
    QPixmap chessBoardPic(QString(":/image/chessBoard.jpg"));
    QPixmap backgroundPic(QString(":/image/backGround2.jpg"));
    //QPixmap Vsimg(QString(":/image/300.jpg"));
    QPixmap blackChessPic(QString(":/image/black.png"));
    QPixmap whiteChessPic(QString(":/image/white.png"));
    QPainter painter(this);
    QPen pen;
    paint=new QPainter;
    paint->begin(this);
    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
    painter.drawPixmap(0, 0, this->width(),this->height(), backgroundPic);
    painter.drawPixmap(0, 0, 810,this->height(), chessBoardPic);
    //painter.drawPixmap(0, 0, 810,this->height(), Vsimg);
    for(int i=0;i<length;i++)
    {
        paint->drawLine(x,y+size*i,x+size*(length-1),y+size*i);//画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
    }
    //画lu+1条竖线
    for(int i=0;i<length;i++)
    {
        paint->drawLine(x+size*i,y,x+size*i,y+size*(length-1));
    }
    //ui->setupUi()
    paint->end();

    //this->update();
}
void CheckBrd::btn_startgame_clicked(){

}

void CheckBrd::btn_stop_clicked(){

}

void CheckBrd::btn_Renshu(){

}
void CheckBrd::btn_regame_clicked(){}//重开游戏


void CheckBrd::btn_Huiqi(){}//悔棋
int CheckBrd::get_idx(int idx){}
void CheckBrd::set_time(int seted_time ){}//设置倒计时时间
void CheckBrd::BeginCountdown(){}//打开计时器
void CheckBrd::OnTimerCountdown(){}//输出倒计时
void CheckBrd::delete_time(){}//删除计时器
void CheckBrd::play_the_Go(QPushButton *now_btn,QPushButton *last_btn){}//绘制棋盘，其实就是把对应的按钮画成黑棋或白棋
int CheckBrd::judge(int idx){}//在每次落子后判断有无胜负,若会吃子或紫砂则传回no，反之则传yes
void CheckBrd::clear_pan(){}
