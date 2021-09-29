//
// Created by mauro on 9/28/21.
//

#include "../Headers/Server.h"

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
//Server side

Server::Server() {
    this->port = 2500;
    int serverSocketHandler = socket(AF_INET , SOCK_STREAM , 0);
    //creating a socket and assigning it to the socket handler
    if(serverSocketHandler < 0)
    {
        // socket methode return -1 if the creation was not successful
        cout << "Socket creation has failed.";
    }
    struct sockaddr_in serverAddr , clientAddr;
    //specifying address and type for the server to operate under
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int bindStatus = bind(serverSocketHandler , (struct sockaddr*) & serverAddr , sizeof(serverAddr));
    if(bindStatus < 0)
    {
        cout << "Socket binding has failed" << endl;
    }
    //listen to the client while others are waiting in queue of size 5
    int listenStatus = listen(serverSocketHandler , 5);
    if(listenStatus < 0)
    {	// when queue is full listen fails
        cout << "Listner has failed" << endl;
    }
    cout << "\t\t...Waiting for connections... \n\n";
    char buff[MAX];
    int clientSocketHandler;
    socklen_t len = sizeof(clientAddr);
    int connection;
    if((connection = accept(serverSocketHandler , (struct sockaddr*) & clientAddr , &len)) < 0)
    {
        cout << "Server didn't accept the request." << endl;
    }
    else
    {
        cout << "Server accepted the request. \n" ;
    }

    while(true)
    {
        // infinite loop for chatting
        int rMsgSize;

        if((rMsgSize  = recv(connection , buff , MAX , 0)) > 0){
            cout << "received client : " << buff << endl;

            //Closes the server
            if(buff[0] == 'b' && buff[1] == 'y' && buff[2] == 'e'){
                cout << "Server : Bye bro" << endl;
                cout << "\nConnection ended... take care bye bye...\n" ;
                send(connection , buff , strlen(buff)+1 , 0);
                break;
            }

            cout << "Server : ";
            char input[MAX];
            string s;
            getline(cin , s);
            int n = s.size();
            for(int i = 0 ; i < n ; i++)
            {
                input[i] = s[i];
            }

            input[n] = '\0';

            send(connection , input , strlen(input)+1 , 0);
        }
    }
    close(serverSocketHandler);
}
