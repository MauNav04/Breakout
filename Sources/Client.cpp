//
// Created by mauro on 9/28/21.
//

#include "../Headers/Client.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
#define MAX 500

using namespace std;
//Client side
Client::Client() {
    this->port = 2500;
    this->serverIp = "localhost";
    int clientSocket , serverSocket , receiveMsgSize;
    clientSocket = socket(AF_INET , SOCK_STREAM , 0);
    if(clientSocket < 0)
    {
        cout << "Creation of client socket failed" << endl;
    }
    struct sockaddr_in serverAddr , clientAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(port);
    if(connect(clientSocket ,  (struct sockaddr*) & serverAddr , sizeof(serverAddr)) < 0)
    {
        cout << "Connection Error..." << endl;
    }
    else
    {
        cout << "\t\tConnection Established..." << endl;
    }

    while(true)
    {
        string s;
        char input[MAX];
        cout << "Client : ";
        getline(cin , s);
        int n = s.size();
        for(int i = 0 ; i < n ; i++)
        {
            input[i] = s[i];
        }
        input[n] = '\0';
        send(clientSocket , input , strlen(input)+1 , 0);
        char receiveMessage[MAX];
        int rMsgSize = recv(clientSocket , receiveMessage , MAX , 0);
        if(rMsgSize < 0)
        {
            cout << "Packet recieve failed." << endl;
        }
        else if(rMsgSize == 0)
        {
            cout << "Server is off." << endl;
        }

        if(receiveMessage[0] == 'b' && receiveMessage[1] == 'y' && receiveMessage[2] == 'e')
        {
            cout << "\nConnection ended... take care bye bye... " ;
            break;
        }
        cout << "received server : " << receiveMessage <<endl;
    }
    close(clientSocket);
}