/*
BACKTRACKING ALGORYTM
ogolny algorytm wyszukiwania wszytskich (lub kilku) rozwiazan niektorych problemow wyliczeniowych, ktory stopniowo generuje
kandydatow na rozwiazanie; jednak gdy stwierdzi ze znaleziony kandydat x nie moze byc poprawnym rozwiazaniem, nawraca
(ang. backtrack) do punktu, gdzie może podjąć inną decyzję związaną z jego budową

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Chess.h"



//zdefiniowac typ wyliczeniowy od FIRST do EIGHT

//typedef enum num { FIRST, SECOND, THIRD, FOURTH, FIFTH, SIXTH, SEVENTH, EIGHTH };
#define HORSE_MOVE 8




int main( int argc, char** argv )
{

    //odczytac ustawienia początkowe x0, y0 konika szachowego z parametru
   Point a = { atoi ( argv [ 1 ] ),atoi ( argv [ 2 ] ) };

    //sprawdzenie czy poprawne
    if ( ( a.x0 >= 0 ) && ( a.x0 < CHESS_BOARD_SIZE) && ( a.y0 >= 0 ) && ( a. y0 < CHESS_BOARD_SIZE ) )
        printf("\nEntered data are correct\n");
    else return 0;
    
   
    //zdefiniowac tablice do pamietania mozliwych ruchow
    Point HorseMove [ HORSE_MOVE ] = //mozliwe ruchy konia
    {
     {1,-2},
     {2,-1},
     { 2,1},
     {1,2 },
     {-1,2 },
     {-2,1 },
     {-2,-1 },
     {-1,-2 }
    };

    //wykreowac dynamicznie tablice kwadratowa o rozmiarze CHECKBOARD_SIZE
    int** pChess = createChessBoard ( CHESS_BOARD_SIZE );
    if (!pChess)
    {
        printf ( "\nError in memeory allocation\n" );
        return 0;
    }

    

    //jesli nie znaleziono drogi od x0 do y0 - wypisac
    //nie ma mozliwosci odwiedzic jednokrotnie kazdego pola
    //jesli ok to wypisac szachownice z numerami kolejnych krokow

    if (root ( pChess, CHESS_BOARD_SIZE, 1, a.x0, a.y0, HorseMove ))
        printChessBoard ( pChess, CHESS_BOARD_SIZE );

    else
        printf ( "nie znaleziono drogi od %d do %d \n", a.x0, a.y0 );

    //zwolnic pamiec
    freeChessBoard(&pChess);

    return 0;
}


/*
Kwadratowa szachownica ( n x n)
Liczba mozliwych sciezek konia
1x1     1
2x2 3x3 4x4     0
5x5     1728
*/



