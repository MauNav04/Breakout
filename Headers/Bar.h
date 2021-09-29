//
// Created by mauro on 9/28/21.
//

#ifndef BREAKOUTGAME_BAR_H
#define BREAKOUTGAME_BAR_H


class Bar {
public:
    int xPos;
    int yPos;
    int barLen;
    bool powerUp;

    Bar();
    int setPos(int newXPos);
    int switchPUState();
};


#endif //BREAKOUTGAME_BAR_H
