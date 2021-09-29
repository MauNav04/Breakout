//
// Created by mauro on 9/28/21.
//

#ifndef BREAKOUTGAME_BRICK_H
#define BREAKOUTGAME_BRICK_H


class Brick {
public:
    int xPos;
    int yPos;
    int type;// not used for now
    int hardness; // vals form 0-3, if 0 is reached the brick is destroyed

    Brick();
    int setPos(int newXPos, int newYPos);
    void hit();

};


#endif //BREAKOUTGAME_BRICK_H
