//
// Created by mauro on 9/28/21.
//

#include "../Headers/Ball.h"

Ball::Ball() {
    this->yPos = 12;
    this->xPos = 7;
}

int Ball::setPos(int newXPos, int newYPos) {
    this->yPos = newYPos;
    this->xPos = newXPos;
    return 0;
}
