//
// Created by mauro on 9/28/21.
//

#ifndef BREAKOUTGAME_BOARD_H
#define BREAKOUTGAME_BOARD_H


#include <string>
#include "Bar.h"
#include "Ball.h"
#include "Brick.h"

class Board {
public:
    int boardMatrix[15][15];
    Bar bar;
    Ball ball;
    //Brick bricks[35];
    bool inGame;

    Board(); // ponga bola y barra en una posición, llena lista de bricks y los coloca en una posicion
    void getBoard(); // Obtiene el tablero en su estado actual
    int updateBoard(); // Actualiza el tablero (posicion de la bola y si choca en algùn bloque)
    void moveBall(int newYpos, int newXpos);
    void changeMovementCase(int direction, int Angle);
    int clearBoard();
    int updateBar(); //Actualiza la posicion de la barra
    void printBoard();

};


#endif //BREAKOUTGAME_BOARD_H
