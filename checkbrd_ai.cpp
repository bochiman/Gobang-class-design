#include "checkbrd_ai.h"
#include "ui_checkbrd_ai.h"
#include "qobject.h"
Checkbrd_AI::Checkbrd_AI(QWidget *parent)
    : QWidget(parent)
    , ui2(new Ui::Checkbrd_AI)
{

    ui2->setupUi(this);
    setWindowTitle("GOBANG");//标题
    connect(ui2->Tuichu, &QPushButton::clicked, this, Checkbrd_AI::btn_back_clicked_AI);
    connect(ui2->blackai, &QCheckBox::stateChanged, this, Checkbrd_AI::checkbox_aistate_black);
    connect(ui2->whiteai, &QCheckBox::stateChanged, this, Checkbrd_AI::checkbox_aistate_white);
}

Checkbrd_AI::~Checkbrd_AI()
{
    delete ui2;
}
void Checkbrd_AI::paintEvent(QPaintEvent *){
    QPixmap chessBoardPic(QString(":/image/chessBoard.jpg"));
    QPixmap backgroundPic(QString(":/image/backGround2.jpg"));
    QPixmap blackChessPic(QString(":/image/black.png"));
    QPixmap whiteChessPic(QString(":/image/white.png"));
    QPainter painter(this);
    QPen pen;
    paint=new QPainter;
    paint->begin(this);
    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
    painter.drawPixmap(0, 0, this->width(),this->height(), backgroundPic);
    painter.drawPixmap(0, 0, 810,this->height(), chessBoardPic);

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
void Checkbrd_AI::checkbox_aistate_black(int state){
    AI_black_state = state;
    qDebug()<<AI_black_state;
}
void Checkbrd_AI::checkbox_aistate_white(int state){
    AI_white_state = state;
    qDebug()<<AI_white_state;
}
void Checkbrd_AI::btn_startgame_clicked_AI(){

}

void Checkbrd_AI::btn_stop_clicked_AI(){

}

void Checkbrd_AI::btn_Renshu_AI(){

}
void Checkbrd_AI::btn_regame_clicked_AI(){}//重开游戏
void Checkbrd_AI::btn_Huiqi_AI(){}//悔棋
int Checkbrd_AI::get_idx_AI(int idx){}
void Checkbrd_AI::set_time_AI(int seted_time ){}//设置倒计时时间
void Checkbrd_AI::BeginCountdown_AI(){}//打开计时器
void Checkbrd_AI::OnTimerCountdown_AI(){}//输出倒计时
void Checkbrd_AI::delete_time_AI(){}//删除计时器
void Checkbrd_AI::play_the_Go_AI(QPushButton *now_btn,QPushButton *last_btn){}//绘制棋盘，其实就是把对应的按钮画成黑棋或白棋
int Checkbrd_AI::judge_AI(int idx){}//在每次落子后判断有无胜负,若会吃子或紫砂则传回no，反之则传yes
void Checkbrd_AI::clear_pan_AI(){}

