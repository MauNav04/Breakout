//
// Created by mauro on 9/28/21.
//

#include "../Headers/Brick.h"
#include <ctime>
#include <cstdlib>
#include <random>
#include <iostream>

Brick::Brick() {
     /*srand((unsigned)time(0));
     this->hardness = (rand()%3)+1;*/

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 3); //range is 0 to 3

    std::cout << "rand val: " << dist(mt) << std::endl;

    this->hardness = dist(mt);
}

int Brick::setPos(int newXPos, int newYPos) {
    this->yPos = newYPos;
    this->xPos = newXPos;
    return 0;
}

void Brick::hit() {
    this->hardness = this->hardness-1;
}
