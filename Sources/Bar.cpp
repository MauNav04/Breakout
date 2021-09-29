//
// Created by mauro on 9/28/21.
//

#include "../Headers/Bar.h"

Bar::Bar() {
    this->yPos = 13;
    this->xPos = 7;
    this->barLen = 3;
    this->powerUp = false;
}

int Bar::setPos(int newXPos) {
    this->xPos = newXPos;
    return 0;
}

int Bar::switchPUState() {
    if(!powerUp){
        powerUp = true;
    }
    else{
        powerUp = false;
    }
    return 0;
}