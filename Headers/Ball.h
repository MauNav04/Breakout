//
// Created by mauro on 9/28/21.
//

#ifndef BREAKOUTGAME_BALL_H
#define BREAKOUTGAME_BALL_H


#include <tuple>

class Ball {
public:
    int xPos;
    int yPos;
    int angle; //puede tener valores de {0,1,2}
    int direction; //puede tener valores de  {0,1}

    Ball();
    int setPos(int newYPos, int newXPos);
    std::tuple<int,int> getPos();
    void verticalBump();// posibly this 'll be on board
    void firstHorizontalBump();
    void horizontalBump();
    int switchRandAngle();
    int switchAngle();
    int switchDirection();

};


#endif //BREAKOUTGAME_BALL_H
