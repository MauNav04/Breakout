//
// Created by mauro on 9/28/21.
//

#include <random>
#include "../Headers/Ball.h"

Ball::Ball() {
    this->yPos = 12;
    this->xPos = 7;
    this->angle = 0;
    this->direction = 1;
}

// Coloca las coordenada en las que la bola se encuentra
int Ball::setPos(int newYPos, int newXPos) {
    this->yPos = newYPos;
    this->xPos = newXPos;
    return 0;
}

// cambia el angulo de rebote
void Ball::verticalBump() {
    int newAngle = this->switchAngle();
    this->angle = newAngle;
}

// cambia la direccion y el angulo de rebote
void Ball::firstHorizontalBump() {
    int newDirection = this->switchDirection();
    this->direction = newDirection;
    int newAngle = this->switchRandAngle();
    this->angle = newAngle;
}

// cambia la direccion y el angulo de rebote
void Ball::horizontalBump() {
    int newDirection = this->switchDirection();
    this->direction = newDirection;
    int newAngle = this->switchAngle();
    this->angle = newAngle;
}

// cambia el valor del angulo en el que viaja la bola
int Ball::switchRandAngle() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 2);
    return dist(mt);
}

// cambia el valor de la direccion en la que viaja la bola
int Ball::switchDirection() {
    if(this->direction == 0){
        return 1;
    }
    else{if(this->direction == 1){
        return 0;
    }}
}

int Ball::switchAngle() {
    if(this->angle == 1){
        return 2;
    }
    else{if(this->angle == 2){
            return 1;
        }}
}


std::tuple<int, int> Ball::getPos() {
    return {this->yPos,this->xPos};
}
