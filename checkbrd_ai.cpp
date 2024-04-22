#include "checkbrd_ai.h"
#include "ui_checkbrd_ai.h"

CheckBrd_ai::CheckBrd_ai(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CheckBrd_ai)
{

    ui->setupUi(this);
    setWindowTitle("GOBANG");//标题
    connect(ui->Tuichu, &QPushButton::clicked, this, CheckBrd_ai::btn_back_clicked);
    connect(ui->Start, &QPushButton::clicked, this, CheckBrd_ai::btn_startgame_clicked);
    connect(ui->Pause, &QPushButton::clicked, this, CheckBrd_ai::btn_stop_clicked);
    connect(ui->RenShu, &QPushButton::clicked, this, CheckBrd_ai::btn_Renshu);
    connect(ui->Regame, &QPushButton::clicked, this, CheckBrd_ai::btn_regame_clicked);
    connect(ui->AIblack,&QRadioButton::clicked,this,CheckBrd_ai::chooseAI);
    connect(ui->AIwhite,&QRadioButton::clicked,this,CheckBrd_ai::chooseAI);

    ui->help_black->setIconSize(QSize(100,100));
    ui->help_black->setIcon(QIcon(":/image/ask.png"));
    ui->help_white->setIconSize(QSize(100,100));
    ui->help_white->setIcon(QIcon(":/image/ask.png"));
    tm = new QTimer(this);
    tm->setInterval(1000);
    connect(tm,&QTimer::timeout,this,CheckBrd_ai::OnTimerCountdown);
    ui->Count->setText("60");
    ui->player2->setText("AI");
    ui->player1->setText("玩家");
    ui->AIwhite->clicked(true);
    init();

}
CheckBrd_ai::~CheckBrd_ai()
{
    delete ui;
}
void CheckBrd_ai::chooseAI(){
    if(ui->AIblack->isChecked())
    {
        AIstate=black;
        qDebug()<<"black";
        ui->player1->setText("AI");
        ui->player2->setText("玩家");
        ui->Zongshoushu->setText(QString::number(step));//总手数更新
        this->update();

    }
    else if(ui->AIwhite->isChecked()){
        AIstate=white;
        ui->player2->setText("AI");
        ui->player1->setText("玩家");
    }
}
void CheckBrd_ai::paintEvent(QPaintEvent *){
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
    QFont font;
    font.setPointSize(15);
    painter.setFont(font);

    for(int i=1;i<length;i++)
    {
        painter.drawText(x+size*i-6,y+size*14+17,QChar('A' + i));
        if(i<6){
            painter.drawText(x-23,y+size*i+7,QString::number(15-i));
        }
        else{
            painter.drawText(x-13,y+size*i+7,QString::number(15-i));
        }
    }
    //ui->setupUi()
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            if (chessOnboard[i][j] == black) {
                painter.drawPixmap(x + i * size - chessSide/2, x + j * size - chessSide/2,
                                   chessSide, chessSide, blackChessPic);
            }
            if (chessOnboard[i][j] == white) {
                painter.drawPixmap(x + i * size - chessSide/2, y + j * size - chessSide/2,
                                   chessSide, chessSide, whiteChessPic);
            }
        }
    }
    paint->setPen(QPen(Qt::red,3,Qt::SolidLine));
    paint->drawArc(x+LastX*size-7,y+LastY*size-7,14,14,0*16,360*16);
    //paint->end();
    this->update();
    qDebug()<<AIstate<<" "<<currentChess;
}
void CheckBrd_ai::init(){
    step=0;
    LastX=-10;
    LastY=-10;
    currentChess = black;
    ui->Zongshoushu->setText(QString::number(step));
    memset(chessOnboard, null, sizeof(chessOnboard));
    ui->player1_img->setIcon(QIcon(":/image/black.png"));
    ui->player2_img->setIcon(QIcon(":/image/white.png"));
    this->setMouseTracking(true);
    for (int i = 0; i < 15; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < 15; j++)
        {
            row.push_back(0);
        }
        ScoreMap.push_back(row);
    }

}
void CheckBrd_ai::mouseMoveEvent(QMouseEvent *e){
    int inChequerSideX = (e->x() - x) % size;
    int inChequerSideY = (e->y() - y) % size;
    dropX = (e->x() - x) / size;
    dropY = (e->y() - y) / size;
    if ((inChequerSideX < rangeCenter || inChequerSideX > (size - rangeCenter)) &&
        (inChequerSideY < rangeCenter || inChequerSideY > (size - rangeCenter)) && state==on&&(e->x()>x-10&&e->x()<14*size+x)&&(e->y()>y-10&&e->x()>x-10<14*size+y))
    {
        //this->setCursor(Qt::PointingHandCursor);
        if(currentChess==white)
            this->setCursor(QCursor(QPixmap(":/image/white.png")));
        else if(currentChess==black)
            this->setCursor(QCursor(QPixmap(":/image/black.png")));
        dropChessEnable = true;
        // 落点位置进一格
        if (inChequerSideX > (size - rangeCenter)) {
            dropX++;
        }
        if (inChequerSideY > (size - rangeCenter)) {
            dropY++;
        }
    } else {
        this->setCursor(Qt::ArrowCursor);
        dropChessEnable = false;
    }
}
void CheckBrd_ai::mousePressEvent(QMouseEvent *e){
    if (dropChessEnable == false ) {
        return;
    }
    if(e->button() == Qt::LeftButton) {
        // qDebug()<<"pressed";
        // qDebug()<<chessOnboard[dropX][dropY];
        if (chessOnboard[dropX][dropY] == null) {
            int ret1=QMessageBox::Yes;//
            if(ui->ai_enable_3->isChecked()==true)
            {
                ret1 = QMessageBox::question(this, tr("落子确认"),tr("确定要在此处落子吗？"), QMessageBox::Yes, QMessageBox::No);
            }
            if(ret1==QMessageBox::Yes)
            {
                chessOnboard[dropX][dropY] = currentChess;
                LastX=dropX;
                LastY=dropY;
                // qDebug()<<dropX;
                // qDebug()<<dropY;
                set_time(game_max_time);//倒计时重置
                if(currentChess==white){
                    if(CheckBrd_ai::judge(LastX, LastY)==true){
                        QString infom = "恭喜胜者："+ui->player1->text();
                        QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
                        clear_pan();

                        ui->Count->setEnabled(true);
                        ui->player2->setEnabled(true);
                        ui->player1->setEnabled(true);
                        state = off;
                        currentChess = black;
                        set_time(game_max_time);
                        tm->stop();
                         ui->player1->setText("玩家1");
                         ui->player2->setText("玩家2");
                         step=0;
                        return;
                    }
                    currentChess = black;
                    play_the_Go();
                    AIplay();
                }
                else if(currentChess==black){
                    if(CheckBrd_ai::judge(LastX, LastY)==true){
                        QString infom = "恭喜胜者："+ui->player1->text();
                        QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
                        clear_pan();

                        ui->Count->setEnabled(true);
                        ui->player2->setEnabled(true);
                        ui->player1->setEnabled(true);
                        state = off;
                        currentChess = black;
                        set_time(game_max_time);
                        tm->stop();
                        ui->player1->setText("玩家1");
                        ui->player2->setText("玩家2");
                        step=0;
                        return;
                    }
                    currentChess = white;
                    play_the_Go();
                    AIplay();
                }
                step++;
                ui->Zongshoushu->setText(QString::number(step));//总手数更新
                this->update();
            }
        }
    }
}
void CheckBrd_ai::btn_startgame_clicked(){
    if(state==on){
        return;
    }
    else if(state==off){
        state = on;
        init();
        if(AIstate==black){
            chessOnboard[7][7]=black;
            currentChess=white;
            play_the_Go();
        }
        qDebug()<<"开始游戏";
        ui->player1->setEnabled(false);
        ui->player2->setEnabled(false);
        ui->Count->setEnabled(false);
        ui->AIblack->setEnabled(false);
        ui->AIwhite->setEnabled(false);
        set_time(ui->Count->text().toInt());
        tm->start();
    }
}

void CheckBrd_ai::btn_stop_clicked(){
    if(state==on){
        tm->stop();
        state=pause;
        ui->Pause->setText("继续");
    }
    else if(state==pause){
        tm->start();
        state=on;
        ui->Pause->setText("暂停");
    }
}

void CheckBrd_ai::btn_Renshu(){
    if(state==on||state==pause){
        if(currentChess==black){
            QString infom = "恭喜胜者："+ui->player2->text();
            QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        }
        else if(currentChess==white){
            QString infom = "恭喜胜者："+ui->player1->text();
            QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        }
        clear_pan();
        ui->Count->setEnabled(true);
        ui->player2->setEnabled(true);
        ui->player1->setEnabled(true);
        state = off;
        currentChess = black;
        set_time(game_max_time);
        ui->player1->setText("玩家1");
        ui->player2->setText("玩家2");
        tm->stop();

    }
}

void CheckBrd_ai::btn_regame_clicked(){
    clear_pan();
    init();
    ui->Count->setEnabled(true);
    ui->player2->setEnabled(true);
    ui->player1->setEnabled(true);
    state = off;
    currentChess = black;
    set_time(game_max_time);
    tm->stop();
}//重开游戏


int CheckBrd_ai::get_idx(int idx){}
void CheckBrd_ai::set_time(int seted_time ){
    game_max_time = seted_time;
    timenow = game_max_time;
    CheckBrd_ai::BeginCountdown();
    QString temp = QString::number(seted_time);
    ui->Count->setText(temp);
}//设置倒计时时间
void CheckBrd_ai::BeginCountdown(){
    if (tm->isActive() == false)
    {
        tm->start();
    }
}//打开计时器
void CheckBrd_ai::OnTimerCountdown(){
    timenow -= 1;
    ui->Count->setText(QString::number(timenow));
    if(timenow<=0){
        if(state==on)
        {
            if(currentChess==black)
            {
                QString infom = ui->player1->text()+"你超时了\n恭喜胜者："+ui->player2->text();
                QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            }
            else
            {
                QString infom = ui->player2->text()+"你超时了\n恭喜胜者："+ui->player1->text();
                QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            }
            clear_pan();
            ui->Count->setEnabled(true);
            ui->player2->setEnabled(true);
            ui->player1->setEnabled(true);
            state = off;
            currentChess = black;
            set_time(game_max_time);
            tm->stop();
            ui->player1->setText("玩家1");
            ui->player2->setText("玩家2");
        }

    }

}//输出倒计时
void CheckBrd_ai::delete_time(){
    if (tm)
    {
        if (tm->isActive() == true)
        {
            tm->stop();
        }
        delete tm;
        tm= nullptr;
    }
}//删除计时器
void CheckBrd_ai::play_the_Go(){
    if(currentChess==black){
        ui->player1_img->setIcon(QIcon(":/image/black.png"));
        ui->player2_img->setIcon(QIcon());
    }
    if(currentChess==white){
        ui->player1_img->setIcon(QIcon());
        ui->player2_img->setIcon(QIcon(":/image/white.png"));
    }
}//绘制棋盘，其实就是把对应的按钮画成黑棋或白棋
int CheckBrd_ai::judge(int x, int y){
    bool result = false;
    // 判断行, 参数为判断方向上变化的极性
    result |= chessNumcalAll(-1, 0, 1, 0, x, y);
    // 判断列
    result |= chessNumcalAll(0, -1, 0, 1, x, y);
    // 判断反斜线
    result |= chessNumcalAll(-1, 1, 1, -1, x, y);
    // 判断正斜线
    result |= chessNumcalAll(-1, -1, 1, 1, x, y);
    return result;
}//在每次落子后判断有无胜负,若会吃子或紫砂则传回no，反之则传yes
void CheckBrd_ai::clear_pan(){

    LastX=-10;
    LastY=-10;
    step=0;
    currentChess = black;
    ui->Zongshoushu->setText(QString::number(step));
    memset(chessOnboard, null, sizeof(chessOnboard));
    ui->player1_img->setIcon(QIcon(":/image/black.png"));
    ui->player2_img->setIcon(QIcon(":/image/white.png"));
    ui->AIblack->setEnabled(true);
    ui->AIwhite->setEnabled(true);
    this->setMouseTracking(true);
    set_time(game_max_time);
}
int CheckBrd_ai::chessNumcalPart(int polarityW, int polarityY, int _x, int _y){
    int val = 0;
    int W;
    int Y;
    dropX = _x;
    dropY = _y;
    // 当前坐标 dropW dropH
    for (int i = 1; i < 5; i++) {
        W = dropX + i * polarityW;
        Y = dropY + i * polarityY;
        if (W < 0 || Y < 0 || W >= 15 || Y >= 15) {
            break;
        }
        if(chessOnboard[W][Y] == currentChess) {
            val++;
        } else {
            break;
        }
    }
    return val;
}
bool CheckBrd_ai::chessNumcalAll(int polarityW1, int polarityY1, int polarityW2, int polarityY2, int _x, int _y){
    int val = 1;
    val += chessNumcalPart(polarityW1, polarityY1, _x, _y);
    val += chessNumcalPart(polarityW2, polarityY2, _x, _y);
    if(val >= 5) {
        return true;
    }
    return false;
}

void CheckBrd_ai::on_help_black_clicked()
{
    if(state==on&&currentChess==black)
    {
        int temp_row=4,temp_col=3;//之后改为通过算法获取此时最佳的row和col
        chessOnboard[temp_row][temp_col] = currentChess;
        LastX=temp_row;
        LastY=temp_col;
        set_time(game_max_time);//倒计时重置
        if(CheckBrd_ai::judge(LastX, LastY)==true){
            QString infom = "恭喜胜者："+ui->player1->text();
            QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            clear_pan();
            init();
            ui->Count->setEnabled(true);
            ui->player2->setEnabled(true);
            ui->player1->setEnabled(true);
            state = off;
            currentChess = black;
            set_time(game_max_time);
            tm->stop();
            return;
        }
        currentChess = white;
        play_the_Go();
        step++;
        ui->Zongshoushu->setText(QString::number(step));//总手数更新
        this->update();
    }
}



void CheckBrd_ai::on_help_white_clicked()
{
    if(state==on&&currentChess==white)
    {
        int temp_row=0,temp_col=0;//之后改为通过算法获取此时最佳的row和col
        chessOnboard[temp_row][temp_col] = currentChess;
        LastX=temp_row;
        LastY=temp_col;
        set_time(game_max_time);//倒计时重置
        if(CheckBrd_ai::judge(LastX, LastY)==true){
            QString infom = "恭喜胜者："+ui->player1->text();
            QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            clear_pan();
            init();
            ui->Count->setEnabled(true);
            ui->player2->setEnabled(true);
            ui->player1->setEnabled(true);
            state = off;
            currentChess = black;
            set_time(game_max_time);
            tm->stop();
            return;
        }
        currentChess = black;
        play_the_Go();
        step++;
        ui->Zongshoushu->setText(QString::number(step));//总手数更新
        this->update();
    }
}
void CheckBrd_ai::AIplay(){
    qDebug()<<"AIon";
    if(AIstate == white && currentChess==white){
        int x,y;
        qDebug()<<"AIon";
        y=MaxScore().col;
        x=MaxScore().row;
        chessOnboard[x][y]=white;
        if(CheckBrd_ai::judge(x, y)==true){
            QString infom = "你挂了";
            QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            clear_pan();

            ui->Count->setEnabled(true);
            ui->player2->setEnabled(true);
            ui->player1->setEnabled(true);
            state = off;
            currentChess = black;
            set_time(game_max_time);
            tm->stop();
            ui->player1->setText("玩家1");
            ui->player2->setText("玩家2");
            return;
        }

        currentChess=black;
        play_the_Go();
        step++;
    }
    else if(AIstate == black && currentChess==black){
        int x,y;
        y=MaxScore().col;
        x=MaxScore().row;
        chessOnboard[x][y]=black;
        if(CheckBrd_ai::judge(x, y)==true){
            QString infom = "你挂了";
            QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            clear_pan();

            ui->Count->setEnabled(true);
            ui->player2->setEnabled(true);
            ui->player1->setEnabled(true);
            state = off;
            currentChess = black;
            set_time(game_max_time);
            tm->stop();
            ui->player1->setText("玩家1");
            ui->player2->setText("玩家2");
            return;
        }
        currentChess=white;
        step++;
    }
    else{
        qDebug()<<"noAI";
        return;
    }
}

ChessPos CheckBrd_ai::MaxScore(){
    int max = 0;
    std::vector<ChessPos> maxscore_pos;
    ChessPos pos;
    calculateScore();
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 15; col++)
        {
            if (ScoreMap[row][col] > max)
            {
                max = ScoreMap[row][col];
                maxscore_pos.clear();
                pos.row = row;
                pos.col = col;
                maxscore_pos.push_back(pos);
            }
            else if (ScoreMap[row][col] == max)
            {
                pos.row = row;
                pos.col = col;
                maxscore_pos.push_back(pos);
            }
        }
    }

    //计分棋盘归0
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            ScoreMap[i][j] = 0;
        }

    }
    int index = 1 % maxscore_pos.size();
    return maxscore_pos[index];
}
void CheckBrd_ai::calculateScore()
{
    ChessType op;
    if(currentChess == black){
         op = white;
    }
    else{
         op = black;
    }
    int Black_Num = 0;
    int White_Num = 0;
    int Empty_Num = 0;
    for(int row=0;row<15;row++)
        for (int col = 0; col< 15; col++)
        {
            if (chessOnboard[row][col] != null)//有棋子，则跳过判断
            {
                continue;
            }
            //先假设下黑子，计分情况
            for (int i = 0; i <= 1; i++)//分横，竖，上斜，下斜4个方向
            {
                for (int j = -1; j <= 1; j++)
                {
                    //每个方向记连续棋子个数
                    Black_Num = 0;
                    White_Num = 0;
                    Empty_Num = 0;

                    if ((i == 0 && j == 0) || (i ==0 && j == 1))
                    {
                        continue;
                    }
                    for (int k = 1; k <= 4; k++)//最多判断五个子,四个方向中的单向
                    {
                        int Cur_row = row + i * k;
                        int Cur_col = col + j * k;
                        if (Cur_row>=0&&Cur_row<15&&
                            Cur_col>=0&&Cur_col<15&&
                            chessOnboard[Cur_row][Cur_col] == op)
                        {
                            Black_Num++;
                        }
                        else if(Cur_row >= 0 && Cur_row < 15 &&
                                 Cur_col >= 0 && Cur_col < 15 &&
                                 chessOnboard[Cur_row][Cur_col] == null)
                        {
                            Empty_Num++;
                            break;
                        }
                        else//超出棋盘或者是白子
                        {
                            break;
                        }
                    }
                    for (int k = 1; k <= 4; k++)//最多判断五个子，四个方向中单向的另一个方向
                    {
                        int Cur_row = row - i * k;
                        int Cur_col = col - j * k;
                        if (Cur_row >= 0 && Cur_row < 15 &&
                            Cur_col >= 0 && Cur_col < 15 &&
                            chessOnboard[Cur_row][Cur_col] == op)
                        {
                            Black_Num++;
                        }
                        else if (Cur_row >= 0 && Cur_row < 15 &&
                                 Cur_col >= 0 && Cur_col < 15 &&
                                 chessOnboard[Cur_row][Cur_col] == null)
                        {
                            Empty_Num++;
                            break;
                        }
                        else//超出棋盘或者是白子
                        {
                            break;
                        }
                    }
                    //该位置的得分情况
                    if (Black_Num == 1)//2个黑子
                    {
                        ScoreMap[row][col] += 10;
                    }
                    else if (Black_Num == 2)//连续三个黑子
                    {
                        if (Empty_Num == 1)
                        {
                            ScoreMap[row][col] += 30;
                        }
                        else if(Empty_Num==2)
                        {
                            ScoreMap[row][col] += 40;
                        }
                    }
                    else if (Black_Num == 3)//连续4个黑子
                    {
                        if (Empty_Num == 1)
                        {
                            ScoreMap[row][col] += 60;
                        }
                        else if (Empty_Num == 2)
                        {
                            ScoreMap[row][col] += 200;
                        }
                    }
                    else if (Black_Num == 4)//连续5个黑子
                    {
                        ScoreMap[row][col] += 20000;
                    }
                }
            }

            //假设该位置下白子，计分情况
            for (int i = 0; i <= 1; i++)//分横，竖，上斜，下斜4个方向
            {
                for (int j = -1; j <= 1; j++)
                {
                    //每个方向记连续棋子个数
                    Black_Num = 0;
                    White_Num = 0;
                    Empty_Num = 0;

                    if ((i == 0 && j == 0) || (i == 0 && j == 1))
                    {
                        continue;
                    }
                    for (int k = 1; k <= 4; k++)//最多判断五个子,四个方向中的单向
                    {
                        int Cur_row = row + i * k;
                        int Cur_col = col + j * k;
                        if (Cur_row >= 0 && Cur_row < 15 &&
                            Cur_col >= 0 && Cur_col < 15 &&
                            chessOnboard[Cur_row][Cur_col] == currentChess)
                        {
                            White_Num++;
                        }
                        else if (Cur_row >= 0 && Cur_row < 15 &&
                                 Cur_col >= 0 && Cur_col < 15 &&
                                 chessOnboard[Cur_row][Cur_col] == null)
                        {
                            Empty_Num++;
                            break;
                        }
                        else//超出棋盘或者是黑子
                        {
                            break;
                        }
                    }
                    for (int k = 1; k <= 4; k++)//最多判断五个子，四个方向中单向的另一个方向
                    {
                        int Cur_row = row - i * k;
                        int Cur_col = col - j * k;
                        if (Cur_row >= 0 && Cur_row < 15 &&
                            Cur_col >= 0 && Cur_col < 15 &&
                            chessOnboard[Cur_row][Cur_col] == currentChess)
                        {
                            White_Num++;
                        }
                        else if (Cur_row >= 0 && Cur_row < 15 &&
                                 Cur_col >= 0 && Cur_col < 15 &&
                                 chessOnboard[Cur_row][Cur_col] == null)
                        {
                            Empty_Num++;
                            break;
                        }
                        else//超出棋盘或者是黑子
                        {
                            break;
                        }
                    }

                    //该位置的得分情况
                    if (White_Num == 0)//1个白子
                    {

                        ScoreMap[row][col] += 5;

                    }
                    else if (White_Num == 1)//连续2个白子
                    {

                        ScoreMap[row][col] += 10;

                    }
                    else if (White_Num == 2)//连续3个白子
                    {
                        if (Empty_Num == 1)
                        {
                            ScoreMap[row][col] += 25;
                        }
                        else if (Empty_Num == 2)
                        {
                            ScoreMap[row][col] += 50;
                        }
                    }
                    else if (White_Num == 3)//连续4个白子
                    {
                        if (Empty_Num == 1)
                        {
                            ScoreMap[row][col] += 55;
                        }
                        else if (Empty_Num == 2)
                        {
                            ScoreMap[row][col] += 300;
                        }
                    }
                    else if (White_Num == 4)//连续5个白子
                    {
                        ScoreMap[row][col] += 30000;

                    }

                }
            }
        }
}
