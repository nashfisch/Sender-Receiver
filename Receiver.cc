#include <iostream>
#include <vector>
#include "Receiver.h"
#include "SlidingWindow.h"
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

/*
Receiver::Receiver(int max) : SlidingWindow(max){
    setMax(max);
    setWinSize(1);
}*/

Receiver::Receiver(std::string& listenPort, int max) : SlidingWindow(max) {
    lPort = listenPort;
    Initialize();
}

void Receiver::Initialize() {
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        std::cerr << "Error creating socket" << std::endl;
        exit(1);
    }
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(std::stoi(lPort));
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if(bind(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error binding socket" << std::endl;
        close(sock);
        exit(1);
    }
}


//originally std::string, removed to get rid of the warning
void Receiver::ReceiveMessage() {
    char buffer[1024];
    socklen_t clientAddressLength;
    struct sockaddr_storage fromaddr;
    clientAddressLength = sizeof(fromaddr);
    
    int receivedBytes = recvfrom(sock, buffer, sizeof(buffer)-1, 0, (struct sockaddr*)&clientAddress, &clientAddressLength);
    if (receivedBytes == -1) {
        std::cerr << "Error receiving data" << std::endl;
    }
    buffer[receivedBytes] = 0;
    std::cout << "Received: " << buffer << std::endl;

    sendto(sock, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&clientAddress, clientAddressLength);

    close(sock);
}

