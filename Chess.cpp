#include "Chess.h"
#include <stdio.h>
#include <stdlib.h>


int move ( int** pChessBoard, int nDim, int moveto, int x, int y, int* px, int* py, Point* pHorseMoves )
{//pChessBoard to szachownica kwadratowa - pamieta ruchy
 //move - numer mozliwego ruchu konia
 //px py - nowe wspolrzedne

    
    //moveto to nr pHorseMoves od 0 do 7

    //1. ustalam nowe wspolrzedne
    //2. sparwdzam czy wyszly poza zakres - jesli tak cofam
    //3. sprawdzam czy juz odwiedzone - jesli tak to cofam, jesli nie to ide tam 

    *px = x + pHorseMoves [ moveto ].x0;
    *py = y + pHorseMoves [ moveto ].y0;
  /*  if ( *px < 0  ||  *px > nDim  ||  *py < 0  ||  *py > nDim  ) //jak wyjdzie poza zakres
     return 0;
    else if (pChessBoard [ *px ][ *py ]!=-1)//jak rozne to znaczy ze juz tam bylam
       return 0;
    
    return 1;*/
  
    return ( *px >= 0 && *px < nDim && *py >= 0 && *py < nDim && pChessBoard [ *px ][ *py ] == 0 );
}


int root ( int** pChessBoard, int nDim, int moveNo, int x, int y, Point* pHorseMoves ) 
{
    pChessBoard [ x ][ y ] = moveNo;

    if (moveNo == nDim * nDim)

        return 1;
   // else {
        int px;
        int py;
        //pChessBoard[x][y];

        for (int i = FIRST; i < EIGHTH; i++) {
            if (move ( pChessBoard, nDim, i, x, y, &px, &py, pHorseMoves )) {
               // pChessBoard [ px ][ py ] = i;
                if (root ( pChessBoard, nDim, moveNo + 1, px, py, pHorseMoves )){ return 1;}
                else {
                    pChessBoard [ px ][ py ] = 0;
                }

            }

        }
    
   // pChessBoard [ x ][ y ] = 0;
   return 0;
}
/*
int root ( int** pChessBoard, int nDim, int moveNo, int x, int y, Point* pHorseMoves )
{
    //pChessBoard to szachownica kwadratowa o wymiarze nDim
   //moveNo to numer ruchu ( do sprawdzenia czy juz wszytskie pola odwiedzone -> nDim * nDim
        //moveto to index pHorse
   //x, y to wspolrzedne skąd robimy kolejny ruch
   //pHorseMoves to offsety ( x i y) wszystkich mozliwych skokow konia z zadanej pozycji
   //int move ( int** pChessBoard, int nDim, int moveto, int x, int y, int* px, int* py, Point * pHorseMoves )

   //ustawiam konia w 1 miejscu
   //sprawdzam gdzie moze
    //jak nie moze to wraca tam gdzie byl i sprawdza czy moze gdzies indziej

    //1.sprawdz czy mozna jeszcze wykonac ruchy
    //2. jesli tak w petli sprawdzaj pHorseMoves 
    //3.jesli nie koniec
    //4. jesli ruch pHorse ok to rekurencyjnie root
    //jak nie to ustal miejsce na -1 i z powrotem move
    pChessBoard [ x ][ y ] = moveNo;
    if (moveNo == nDim * nDim) //dopoki wszytskie mozliwe ruchy nie sa wykonane
    {
        //printChessBoard ( pChessBoard, CHESS_BOARD_SIZE );
       // pChessBoard [ x ][ y ] = 0;
        return 1;
    }
    int next_x = 0;
    int next_y = 0;//nowe wspolrzedne
    for (int i = 0; i < nDim; i++)
    {
        //pChessBoard [ next_x ][ next_y ] = moveNo;
        if (move ( pChessBoard, nDim, i, x, y, &next_x, &next_y, pHorseMoves )) //return 0;
        {//jesli move zwroci 0 to cofnie to petli
            pChessBoard [ next_x ][ next_y ] = i;
            if (root ( pChessBoard, nDim, moveNo + 1, next_x, next_y, pHorseMoves )) return 1;
            // return 1;
            else
            {
                pChessBoard [ next_x ][ next_y ] = -1;
            }

            //pChessBoard [ next_x ][ next_y ] = -1;
            //moveNo++;



        }
        //return 0;
    }
    x = -1;
    y = -1;
    return 0;

}*/

int** createChessBoard(int nDim)
{//kreuje i zeruje tablice chyba ze calloc
   
    int** tab = (int**)calloc(nDim, sizeof(int*));
    if (!tab) return NULL;
    //int** pV = tab;
   /* for (int i = 0; i < nDim; i++)
    {
        tab[i] = (int*)calloc(nDim, sizeof(int));
        if (!tab[i]) return NULL;
    }*/
   
    for (int i = 0; i < nDim; i++)
    {
        tab [ i ] = ( int* ) calloc ( nDim, sizeof ( int ) );
        if (!tab [ i ])
            return NULL;
    }
    return tab;

}
/*
int** createChessBoard ( int nDim ) {

    int** pChessBoard = ( int** ) malloc ( nDim * sizeof ( int* ) );
    for (int i = 0; i < nDim; i++)
        pChessBoard [ i ] = ( int* ) malloc ( nDim * sizeof ( int ) );
    for (int i = 0; i < nDim; i++)
        for (int j = 0; j < nDim; j++)
            pChessBoard [ i ][ j ] = -1;
    return pChessBoard;
}*/


void freeChessBoard(int*** pChessBoard)
{
    int** pPom = *pChessBoard;
    for (int i = 0; i < CHESS_BOARD_SIZE; i++)
        free(*pPom++);
    free(*pChessBoard);
}

void printChessBoard(int** pChessBoard, int nDim)
{
	//wypisuje szachownice

    for (int i = 0; i < nDim; i++)
    {
        int* pPom = *pChessBoard++;
        for (int j = 0; j < nDim; j++)
            printf("%d\t", *pPom++);
        printf("\n");
    }
    printf("\n");

}

