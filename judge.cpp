#include<list>
#include"judge.h"



//定义棋盘类

    void Chessboard::placePiece(int row, int col, Color color)//给棋盘添加新棋子 
    {
        if (color == BLACK)
            blackPieces.push_back(Piece(row, col, color));//下黑棋 
        else if (color == WHITE)
            whitePieces.push_back(Piece(row, col, color));
    }
    void Chessboard::import(int piece[][15]) {
        int i, j;
        for (i = 0; i < 15; i++) {
            for (j = 0; j < 15; j++) {
                if (piece[i][j] == 1) {//黑棋
                    blackPieces.push_back(Piece(i + 1, j + 1, BLACK));
                }
                else if (piece[i][j] == 2) {//白棋
                    blackPieces.push_back(Piece(i + 1, j + 1, WHITE));
                }
            }
        }
    }
    //中间应添加算法函数 
    bool Chessboard::checkFiveInRow(const std::list<Piece>& pieces, int new_row, int new_col) {
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
    //统计各个方向的同色棋数
    int Chessboard::count(bool exit, int orientation, const std::list<Piece>& pieces, int new_row, int new_col) {
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


    //遍历函数：输入行，列以及piece链表 
    bool Chessboard::findPiece(int row, int col, const std::list<Piece>& pieces) const
    {   //!!!这可能后续要改动,row的上下边界[1,15]变为[0,14]
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
    int Chessboard::checkWinner(int new_row,int new_col,Color A)
    {
        if (A == 1 && checkFiveInRow(blackPieces,new_row,new_col)) return BLACK;
        if (A == 2 && checkFiveInRow(whitePieces, new_row, new_col)) return WHITE;
        return 0;//No winner
    }
    void Chessboard::clearBoard()
    {
        blackPieces.clear();//清空黑棋链表 
        whitePieces.clear();//清空白棋链表 
    }

