//
// Created by mauro on 9/28/21.
//

#ifndef BREAKOUTGAME_SERVER_H
#define BREAKOUTGAME_SERVER_H


#include "Board.h"

class Server {
public:
    int port;
    char msg[1500];

    [[noreturn]] Server();
    int calcBallPos(Board *board);
};


#endif //BREAKOUTGAME_SERVER_H
