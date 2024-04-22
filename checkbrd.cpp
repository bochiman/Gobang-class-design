#include "checkbrd.h"
#include "ui_checkbrd.h"

CheckBrd::CheckBrd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CheckBrd)
{

    ui->setupUi(this);
    setWindowTitle("GOBANG");//标题
    connect(ui->Tuichu, &QPushButton::clicked, this, CheckBrd::btn_back_clicked);
    connect(ui->Start, &QPushButton::clicked, this, CheckBrd::btn_startgame_clicked);
    connect(ui->Pause, &QPushButton::clicked, this, CheckBrd::btn_stop_clicked);
    connect(ui->RenShu, &QPushButton::clicked, this, CheckBrd::btn_Renshu);
    connect(ui->Regame, &QPushButton::clicked, this, CheckBrd::btn_regame_clicked);


    tm = new QTimer(this);
    tm->setInterval(1000);
    connect(tm,&QTimer::timeout,this,CheckBrd::OnTimerCountdown);
    ui->Count->setText("60");
    init();
    ui->help_black->setIconSize(QSize(100,100));
    ui->help_black->setIcon(QIcon(":/image/ask.png"));
    ui->help_white->setIconSize(QSize(100,100));
    ui->help_white->setIcon(QIcon(":/image/ask.png"));


}
CheckBrd::~CheckBrd()
{
    delete ui;
}
void CheckBrd::paintEvent(QPaintEvent *){
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
    //ui->setupUi()
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
    painter.drawText(x-8,y+size*14+17,QString("A"));
    painter.drawText(x-23,y+9,QString("15"));
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
}
void CheckBrd::init(){
    step=0;
    LastX=-10;
    LastY=-10;
    currentChess = black;
    ui->Zongshoushu->setText(QString::number(step));
    memset(chessOnboard, null, sizeof(chessOnboard));
    ui->player1_img->setIcon(QIcon(":/image/black.png"));
    ui->player2_img->setIcon(QIcon(":/image/white.png"));
    this->setMouseTracking(true);
    clearBoard();
}
void CheckBrd::mouseMoveEvent(QMouseEvent *e){
    int inChequerSideX = (e->x() - x) % size;
    int inChequerSideY = (e->y() - y) % size;
    dropX = (e->x() - x) / size;
    dropY = (e->y() - y) / size;
    if ((inChequerSideX < rangeCenter || inChequerSideX > (size - rangeCenter)) &&
        (inChequerSideY < rangeCenter || inChequerSideY > (size - rangeCenter)) && state==on &&(e->x()>x-10&&e->x()<14*size+x)&&(e->y()>y-10&&e->x()>x-10<14*size+y)) {
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
    }
    else {
        this->setCursor(Qt::ArrowCursor);
        dropChessEnable = false;
    }
}
void CheckBrd::mousePressEvent(QMouseEvent *e){
    if (dropChessEnable == false ) {
        return;
    }
    if(e->button() == Qt::LeftButton) {
        // qDebug()<<"pressed";
        // qDebug()<<chessOnboard[dropX][dropY];
        if (chessOnboard[dropX][dropY] == null) {
            int ret1=QMessageBox::Yes;//
            placePiece(dropX,dropY,currentChess);
            if(ui->checkBox->isChecked()==true)
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
                if(CheckBrd::checkFiveInRow(whitePieces, LastX, LastY)==true){
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
            }
            else if(currentChess==black){
                if(CheckBrd::checkFiveInRow(blackPieces, LastX, LastY)==true){
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

            }
            step++;
            ui->Zongshoushu->setText(QString::number(step));//总手数更新
            this->update();
            }
        }
    }
}
void CheckBrd::btn_startgame_clicked(){
    if(state==on){
        return;
    }
    else if(state==off){
        init();
        state = on;
        qDebug()<<"开始游戏";
        ui->player1->setEnabled(false);
        ui->player2->setEnabled(false);
        ui->Count->setEnabled(false);
        set_time(ui->Count->text().toInt());
        tm->start();
    }
}

void CheckBrd::btn_stop_clicked(){
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

void CheckBrd::btn_Renshu(){
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
        init();
        ui->Count->setEnabled(true);
        ui->player2->setEnabled(true);
        ui->player1->setEnabled(true);
        state = off;
        currentChess = black;
        set_time(game_max_time);
        tm->stop();

        }
    }

void CheckBrd::btn_regame_clicked(){
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


int CheckBrd::get_idx(int idx){}
void CheckBrd::set_time(int seted_time ){
    game_max_time = seted_time;
    timenow = game_max_time;
    CheckBrd::BeginCountdown();
    QString temp = QString::number(seted_time);
    ui->Count->setText(temp);
}//设置倒计时时间
void CheckBrd::BeginCountdown(){
    if (tm->isActive() == false)
    {
        tm->start();
    }
}//打开计时器
void CheckBrd::OnTimerCountdown(){
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
            init();
            ui->Count->setEnabled(true);
            ui->player2->setEnabled(true);
            ui->player1->setEnabled(true);
            state = off;
            currentChess = black;
            set_time(game_max_time);
            tm->stop();
        }

    }

}//输出倒计时
void CheckBrd::delete_time(){
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
void CheckBrd::play_the_Go(){
    if(currentChess==black){
        ui->player1_img->setIcon(QIcon(":/image/black.png"));
        ui->player2_img->setIcon(QIcon());
    }
    if(currentChess==white){
        ui->player1_img->setIcon(QIcon());
        ui->player2_img->setIcon(QIcon(":/image/white.png"));
    }
}//绘制棋盘，其实就是把对应的按钮画成黑棋或白棋
int CheckBrd::judge(int x, int y){ 
}
void CheckBrd::clear_pan(){
    init();
    set_time(game_max_time);
}
int CheckBrd::chessNumcalPart(int polarityW, int polarityY, int _x, int _y){

}
bool CheckBrd::chessNumcalAll(int polarityW1, int polarityY1, int polarityW2, int polarityY2, int _x, int _y){

}

void CheckBrd::on_help_black_clicked()
{
    if(state==on&&currentChess==black)
    {
    int temp_row=4,temp_col=3;//之后改为通过算法获取此时最佳的row和col
            chessOnboard[temp_row][temp_col] = currentChess;
            LastX=temp_row;
            LastY=temp_col;
            set_time(game_max_time);//倒计时重置
                if(CheckBrd::judge(LastX, LastY)==true){
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


void CheckBrd::on_help_white_clicked()
{
    if(state==on&&currentChess==white)
    {
        int temp_row=0,temp_col=0;//之后改为通过算法获取此时最佳的row和col
        chessOnboard[temp_row][temp_col] = currentChess;
        LastX=temp_row;
        LastY=temp_col;
        set_time(game_max_time);//倒计时重置
        if(CheckBrd::judge(LastX, LastY)==true){
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

void CheckBrd::placePiece(int row, int col, ChessType chess){
    if (chess == black)
        blackPieces.push_back(Piece(row, col));//下黑棋
    else if (chess == white)
        whitePieces.push_back(Piece(row, col));
}
bool CheckBrd::checkFiveInRow(const std::list<Piece>& pieces, int new_row, int new_col){
    //list<Piece>& pieces->当前某一色（黑/白）落子情况,new_row->新棋的横坐标,new_col->新棋的纵坐标
    //1.扫一遍新棋周围八个位置有没有同色棋
    bool left = findPiece(new_row, new_col - 1, pieces);//左
    bool left_up = findPiece(new_row + 1, new_col - 1, pieces);//左上
    bool up = findPiece(new_row + 1, new_col, pieces);//上
    bool right_up = findPiece(new_row + 1, new_col + 1, pieces);//右上
    bool right = findPiece(new_row, new_col + 1, pieces);//右
    bool right_down = findPiece(new_row - 1, new_col + 1, pieces);//右下
    bool down = findPiece(new_row - 1, new_col, pieces);//下
    bool left_down = findPiece(new_row - 1, new_col - 1, pieces);//左下
    //2.八个方向分别统计连着的同色棋
    int left_num = count(left, 1, pieces, new_row, new_col);
    int left_up_num = count(left_up, 2, pieces, new_row, new_col);
    int up_num = count(up, 3, pieces, new_row, new_col);
    int right_up_num = count(right_up, 4, pieces, new_row, new_col);
    int right_num = count(right, 5, pieces, new_row, new_col);
    int right_down_num = count(right_down, 6, pieces, new_row, new_col);
    int down_num = count(down, 7, pieces, new_row, new_col);
    int left_down_num = count(left_down, 8, pieces, new_row, new_col);
    //四个大方向累加进行判断
    int horizontal_line = left_num + right_num + 1;//横线
    int vertical_line = up_num + down_num + 1;//竖线
    int leftup_rightdown = left_up_num + right_down_num + 1;//左上到右下
    int leftdown_rightup = left_down_num + right_up_num + 1;//左下到右上
    if ((horizontal_line == 5) || (vertical_line == 5) || (leftup_rightdown == 5) || (leftdown_rightup == 5)) {
        //赢了
        return true;
    }
    else {//还没有赢，继续玩
        return false;
    }
}

int CheckBrd::count(bool exit, int orientation, const std::list<Piece>& pieces, int new_row, int new_col){
    if (!exit) {//判断那八个位置有无棋子
        return 0;
    }
    //接下来都是起始八个位置有棋子的情况
    int num = 1;
    if (orientation == 1) {//左方
        for (int i = 1; i <= 3; i++) {
            if (findPiece(new_row, new_col - i - 1, pieces)) {
                num++;
            }
        }
    }
    else if (orientation == 2) {//左上方
        for (int i = 1; i <= 3; i++) {
            if (findPiece(new_row + 1 + i, new_col - 1 - i, pieces)) {
                num++;
            }
        }
    }
    else if (orientation == 3) {//上方
        for (int i = 1; i <= 3; i++) {
            if (findPiece(new_row + 1 + i, new_col, pieces)) {
                num++;
            }
        }
    }
    else if (orientation == 4) {//右上方
        for (int i = 1; i <= 3; i++) {
            if (findPiece(new_row + 1 + i, new_col + 1 + i, pieces)) {
                num++;
            }
        }
    }
    else if (orientation == 5) {//右方
        for (int i = 1; i <= 3; i++) {
            if (findPiece(new_row, new_col + 1 + i, pieces)) {
                num++;
            }
        }
    }
    else if (orientation == 6) {//右下方
        for (int i = 1; i <= 3; i++) {
            if (findPiece(new_row - 1 - i, new_col + 1 + i, pieces)) {
                num++;
            }
        }
    }
    else if (orientation == 7) {//下方
        for (int i = 1; i <= 3; i++) {
            if (findPiece(new_row - 1 - i, new_col, pieces)) {
                num++;
            }
        }
    }
    else if (orientation == 8) {//左下方
        for (int i = 1; i <= 3; i++) {
            if (findPiece(new_row - 1 - i, new_col - 1 - i, pieces)) {
                num++;
            }
        }
    }

    return num;
}

bool CheckBrd::findPiece(int row, int col, const std::list<Piece>& pieces) const{
    //!!!这可能后续要改动,row的上下边界[1,15]变为[0,14]
    //考虑在棋盘边界
    if ((row > 15 || row < 1) || (col > 15 || col < 1)) {
        return false;
    }
    for (std::list<Piece>::const_iterator i = pieces.begin(); i != pieces.end(); ++i)
    {
        if (i->row == row && i->col == col)
            return true;
    }
    return false;
}


void CheckBrd::clearBoard()
{
    blackPieces.clear();//清空黑棋链表
    whitePieces.clear();//清空白棋链表
}
