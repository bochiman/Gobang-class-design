#ifndef JUDGE_H_
#define JUDGE_H_

#include<list>

//定义棋子的颜色
enum Color { BLACK = 1, WHITE = 2 };
//定义棋子类
class Piece
{
public:
    int row;
    int col;
    Color color;
    Piece(int r, int c, Color color) :row(r), col(c), color(color) {}
};
//定义棋盘类
class Chessboard
{
private:
    std::list<Piece> blackPieces;//黑棋链表 
    std::list<Piece> whitePieces;//白棋链表 
    int size;
public:
    Chessboard(int s) :size(s) {}//定义棋盘大小 
    void placePiece(int row, int col, Color color);//给棋盘添加新棋子
    void import(int piece[][15]);//从二维数组初始化棋盘
    bool checkFiveInRow(const std::list<Piece>& pieces, int new_row, int new_col);//判断胜负
   
    //统计各个方向的同色棋数
    int count(bool exit, int orientation, const std::list<Piece>& pieces, int new_row, int new_col);
    //遍历函数：输入行，列以及piece链表 
    bool findPiece(int row, int col, const std::list<Piece>& pieces) const;
    //判断赢家
    int checkWinner(int new_row, int new_col, Color A);
    //清空链表
    void clearBoard();
    
};










#endif 

