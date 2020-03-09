#pragma once


//zdefiniowac stala CHESS_BOARD_SIZE - wymiar szachownicy
#define CHESS_BOARD_SIZE 8


//zdefiniowac typ wyliczeniowy od FIRST do EIGHT
typedef enum  { FIRST, SECOND, THIRD, FOURTH, FIFTH, SIXTH, SEVENTH, EIGHTH };

typedef struct 
{
    int x0;
    int y0;
} Point;

int root(int** pChessBoard, int nDim, int moveNo, int x, int y, Point* pHorseMoves);
int** createChessBoard(int nDim);
void freeChessBoard(int*** pChessBoard);
void printChessBoard(int** pChessBoard, int nDim);
int move(int** pChessBoard, int nDim, int moveto, int x, int y, int* px, int* py, Point* pHorseMoves);
