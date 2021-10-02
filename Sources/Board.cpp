//
// Created by mauro on 9/28/21.
//

#include "../Headers/Board.h"
#include <iostream>

using namespace std;


Board::Board() {
    //Place one brick as test
    this->boardMatrix[4][7] = 3;
    //set ball position
    this->boardMatrix[this->ball.yPos][this->ball.xPos] = 2;
    //set bar position
    for (int i = 0; i<this->bar.barLen; i++) {
        this->boardMatrix[this->bar.yPos][this->bar.xPos + i] = 1;
    }

}

void Board::getBoard() {

}

//Verificará si la bola está chocando con un borde horizontal o vertical de la pantalla o
//con un bloque de manera horizontal o vertical o con la barra
int Board::updateBoard() {
    //Golpe inicial - D:Arriba A:Directo - Stat: No choca
    if (this->ball.angle == 0 && this->boardMatrix[this->ball.yPos-1][this->ball.xPos] == 0){
        this->moveBall(this->ball.yPos-1,this->ball.xPos);
    }
    else{
        if (this->ball.angle == 0 && this->boardMatrix[this->ball.yPos-1][this->ball.xPos] != 0){
            this->changeMovementCase(this->ball.direction, this->ball.angle);
            this->moveBall(0, 7);
        }
    }

    return 0;
}

void Board::moveBall(int newYpos, int newXpos) {
    this->boardMatrix[this->ball.yPos][this->ball.xPos] = 0;
    this->ball.setPos(newYpos, newXpos);
    this->boardMatrix[this->ball.yPos][this->ball.xPos] = 2;
}

void Board::changeMovementCase(int direction, int Angle) {
    if(Angle == 0){
        this->ball.firstHorizontalBump();
    }
}

int Board::clearBoard() {
    return 0;
}

int Board::updateBar() {
    return 0;
}

void Board::printBoard() {
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            cout << this->boardMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int ballPosX, ballPosY;
    tie(ballPosY,ballPosX) = this->ball.getPos();

    cout << ballPosY << " , " << ballPosX << endl;
}