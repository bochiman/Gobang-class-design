#ifndef JUDGE_H_
#define JUDGE_H_

#include<list>

//�������ӵ���ɫ
enum Color { BLACK = 1, WHITE = 2 };
//����������
class Piece
{
public:
    int row;
    int col;
    Color color;
    Piece(int r, int c, Color color) :row(r), col(c), color(color) {}
};
//����������
class Chessboard
{
private:
    std::list<Piece> blackPieces;//�������� 
    std::list<Piece> whitePieces;//�������� 
    int size;
public:
    Chessboard(int s) :size(s) {}//�������̴�С 
    void placePiece(int row, int col, Color color);//���������������
    void import(int piece[][15]);//�Ӷ�ά�����ʼ������
    bool checkFiveInRow(const std::list<Piece>& pieces, int new_row, int new_col);//�ж�ʤ��
   
    //ͳ�Ƹ��������ͬɫ����
    int count(bool exit, int orientation, const std::list<Piece>& pieces, int new_row, int new_col);
    //���������������У����Լ�piece���� 
    bool findPiece(int row, int col, const std::list<Piece>& pieces) const;
    //�ж�Ӯ��
    int checkWinner(int new_row, int new_col, Color A);
    //�������
    void clearBoard();
    
};










#endif 

