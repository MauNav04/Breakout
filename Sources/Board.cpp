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
    //Golpe inicial - D:Arriba A:Directo
    if (this->ball.angle == 0) {
        //Stat: No choca
        if (isEmpty(0)) {
            this->moveBall(this->ball.yPos - 1, this->ball.xPos);
        } else { //Stat: choca
            this->changeMovementCase(0,0);
            this->updateBoard();
        }
    }
    else{
        int tempBallPos[2];
        // verifications for first case (0,1)
        if(this->ball.direction == 0 && this->ball.angle == 1 ){
            // check if ball bumps with a border
            bool conditionY = this->ball.yPos + 1 > 14;
            bool conditionX = this->ball.xPos -1 < 0;
            if(conditionY or conditionX){
                if(conditionY){
                    moveBall(14,7);
                    cout << "El juego ha terminado" << endl;
                }
                else{
                    if (boardMatrix[tempBallPos[0]][this->ball.xPos] == 0) {
                        this->ball.verticalBump();
                    } else {
                        this->ball.horizontalBump();
                    }
                }

            }
            else{

            }
            if(isEmpty(1)){
                this->moveBall(this->ball.yPos + 1, this->ball.xPos -1);
            }
            else{
                if(this->ball.angle == 1 && !isEmpty(1)){
                    this->moveBall(this->ball.yPos + 1, this->ball.xPos -1);
                }
            }
        }
    }
    return 0;
}

bool Board::isEmpty(int caseType) {
    if(caseType == 0 ){
        if(this->boardMatrix[this->ball.yPos -1][this->ball.xPos] == 0){
            return true;}
        else{
            return false;}
    }
    else{
        if(caseType == 1){
            if(this->boardMatrix[this->ball.yPos +1][this->ball.xPos -1] == 0){
                return true;}
            else{
                return false;}
        }
        else {
            if (caseType == 2) {
                if (this->boardMatrix[this->ball.yPos +1][this->ball.xPos +1] == 0) {
                    return true;
                } else {
                    return false;
                }
            }
            else {
                if (caseType == 3) {
                    if (this->boardMatrix[this->ball.yPos -1][this->ball.xPos -1] == 0) {
                        return true;
                    } else {
                        return false;
                    }
                }
                else {
                    if (caseType == 4) {
                        if (this->boardMatrix[this->ball.yPos -1][this->ball.xPos +1] == 0) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void Board::moveBall(int newYpos, int newXpos) {
    this->boardMatrix[this->ball.yPos][this->ball.xPos] = 0;
    this->ball.setPos(newYpos, newXpos);
    this->boardMatrix[this->ball.yPos][this->ball.xPos] = 2;
}

void Board::changeMovementCase(int caseType){
    if(caseType == 0){
        this->ball.firstHorizontalBump();
    }
    if(caseType == 1 ){}
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


