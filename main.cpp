#include <iostream>
#include "Headers/Client.h"
#include "Headers/Server.h"
using namespace std;

int main() {
    string data;
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
    }
}
