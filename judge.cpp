#include<list>
#include"judge.h"



//����������

    void Chessboard::placePiece(int row, int col, Color color)//��������������� 
    {
        if (color == BLACK)
            blackPieces.push_back(Piece(row, col, color));//�º��� 
        else if (color == WHITE)
            whitePieces.push_back(Piece(row, col, color));
    }
    void Chessboard::import(int piece[][15]) {
        int i, j;
        for (i = 0; i < 15; i++) {
            for (j = 0; j < 15; j++) {
                if (piece[i][j] == 1) {//����
                    blackPieces.push_back(Piece(i + 1, j + 1, BLACK));
                }
                else if (piece[i][j] == 2) {//����
                    blackPieces.push_back(Piece(i + 1, j + 1, WHITE));
                }
            }
        }
    }
    //�м�Ӧ����㷨���� 
    bool Chessboard::checkFiveInRow(const std::list<Piece>& pieces, int new_row, int new_col) {
        //list<Piece>& pieces->��ǰĳһɫ����/�ף��������,new_row->����ĺ�����,new_col->�����������
       //1.ɨһ��������Χ�˸�λ����û��ͬɫ��
        bool left = findPiece(new_row, new_col - 1, pieces);//��
        bool left_up = findPiece(new_row + 1, new_col - 1, pieces);//����
        bool up = findPiece(new_row + 1, new_col, pieces);//��
        bool right_up = findPiece(new_row + 1, new_col + 1, pieces);//����
        bool right = findPiece(new_row, new_col + 1, pieces);//��
        bool right_down = findPiece(new_row - 1, new_col + 1, pieces);//����
        bool down = findPiece(new_row - 1, new_col, pieces);//��
        bool left_down = findPiece(new_row - 1, new_col - 1, pieces);//����
        //2.�˸�����ֱ�ͳ�����ŵ�ͬɫ��
        int left_num = count(left, 1, pieces, new_row, new_col);
        int left_up_num = count(left_up, 2, pieces, new_row, new_col);
        int up_num = count(up, 3, pieces, new_row, new_col);
        int right_up_num = count(right_up, 4, pieces, new_row, new_col);
        int right_num = count(right, 5, pieces, new_row, new_col);
        int right_down_num = count(right_down, 6, pieces, new_row, new_col);
        int down_num = count(down, 7, pieces, new_row, new_col);
        int left_down_num = count(left_down, 8, pieces, new_row, new_col);
        //�ĸ������ۼӽ����ж�
        int horizontal_line = left_num + right_num + 1;//����
        int vertical_line = up_num + down_num + 1;//����
        int leftup_rightdown = left_up_num + right_down_num + 1;//���ϵ�����
        int leftdown_rightup = left_down_num + right_up_num + 1;//���µ�����
        if ((horizontal_line == 5) || (vertical_line == 5) || (leftup_rightdown == 5) || (leftdown_rightup == 5)) {
            //Ӯ��
            return true;
        }
        else {//��û��Ӯ��������
            return false;
        }
    }
    //ͳ�Ƹ��������ͬɫ����
    int Chessboard::count(bool exit, int orientation, const std::list<Piece>& pieces, int new_row, int new_col) {
        if (!exit) {//�ж��ǰ˸�λ����������
            return 0;
        }
        //������������ʼ�˸�λ�������ӵ����
        int num = 1;
        if (orientation == 1) {//��
            for (int i = 1; i <= 3; i++) {
                if (findPiece(new_row, new_col - i - 1, pieces)) {
                    num++;
                }
            }
        }
        else if (orientation == 2) {//���Ϸ�
            for (int i = 1; i <= 3; i++) {
                if (findPiece(new_row + 1 + i, new_col - 1 - i, pieces)) {
                    num++;
                }
            }
        }
        else if (orientation == 3) {//�Ϸ�
            for (int i = 1; i <= 3; i++) {
                if (findPiece(new_row + 1 + i, new_col, pieces)) {
                    num++;
                }
            }
        }
        else if (orientation == 4) {//���Ϸ�
            for (int i = 1; i <= 3; i++) {
                if (findPiece(new_row + 1 + i, new_col + 1 + i, pieces)) {
                    num++;
                }
            }
        }
        else if (orientation == 5) {//�ҷ�
            for (int i = 1; i <= 3; i++) {
                if (findPiece(new_row, new_col + 1 + i, pieces)) {
                    num++;
                }
            }
        }
        else if (orientation == 6) {//���·�
            for (int i = 1; i <= 3; i++) {
                if (findPiece(new_row - 1 - i, new_col + 1 + i, pieces)) {
                    num++;
                }
            }
        }
        else if (orientation == 7) {//�·�
            for (int i = 1; i <= 3; i++) {
                if (findPiece(new_row - 1 - i, new_col, pieces)) {
                    num++;
                }
            }
        }
        else if (orientation == 8) {//���·�
            for (int i = 1; i <= 3; i++) {
                if (findPiece(new_row - 1 - i, new_col - 1 - i, pieces)) {
                    num++;
                }
            }
        }

        return num;
    }


    //���������������У����Լ�piece���� 
    bool Chessboard::findPiece(int row, int col, const std::list<Piece>& pieces) const
    {   //!!!����ܺ���Ҫ�Ķ�,row�����±߽�[1,15]��Ϊ[0,14]
        //���������̱߽�
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
        blackPieces.clear();//��պ������� 
        whitePieces.clear();//��հ������� 
    }

