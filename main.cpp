#include <iostream>
#include "Headers/Client.h"
#include "Headers/Server.h"
using namespace std;

int main() {
    // Test creating the server directly
    /*string data;
    cout << "Please Type S for server or C for Client:" << endl;
    getline(cin, data);
    if(data == "S")
    {
        cout << "Initiating Server..." << endl;
        Server();
    }
    else{
        cout << "Initiating Client..." << endl;
        Client();
    }*/

    // Testing Board Functions
    Board * board =  new Board();
    board->printBoard();

    for(int i = 0; i < 10 ; i++){
        board->updateBoard();
        board->printBoard();
    }

}
