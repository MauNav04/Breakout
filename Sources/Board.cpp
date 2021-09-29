//
// Created by mauro on 9/28/21.
//

#include "../Headers/Board.h"
#include <iostream>

using namespace std;


Board::Board() {
    //set ball position
    this->boardMatrix[this->ball.yPos][this->ball.xPos] = 2;
    //set bar position
    for (int i = 0; i<this->bar.barLen; i++) {
        this->boardMatrix[this->bar.yPos][this->bar.xPos + i] = 1;
    }

}

void Board::getBoard() {

}

int Board::updateBoard() {
    return 0;
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
}
