#include <iostream>
#include <vector>
#include "Sender.h"
#include "SlidingWindow.h"
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
/*
Sender::Sender(int max) : SlidingWindow(max){}
int Sender::retransmit(){
    return unacknowledgedNums[0];
}*/

Sender::Sender(std::string& destinationHost, std::string& destinationPort, int max) : SlidingWindow(max) {
    destHost = destinationHost;
    destPort = destinationPort;
    Initialize();
}

void Sender::Initialize() {
    struct addrinfo hints;
    memset(&hints, 0 , sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    int rval = getaddrinfo(destHost.c_str(), destPort.c_str(), &hints, &destAddr);
    if (rval != 0) {
        std::cerr << "Error getting the destination address: " << gai_strerror(rval) << std::endl;
        exit(1);
    }

    sock = socket(destAddr->ai_family, destAddr->ai_socktype, destAddr->ai_protocol);
    if(sock == -1) {
        std::cerr << "Failed to open socket" << std::endl;
        exit(1);
    }
}

void Sender::SendMessage(const std::string& message) {
    
    if (sendto(sock, message.c_str(), message.length(), 0, destAddr->ai_addr, destAddr->ai_addrlen) == -1) {
        std::cerr << "Error sending the message" << std::endl;
        exit(1);
    }
    char buffer[1024];
    socklen_t clientAddressLength;
    struct sockaddr_storage fromaddr;
    clientAddressLength = sizeof(fromaddr);
    
    int receivedBytes = recvfrom(sock, buffer, sizeof(buffer)-1, 0, (struct sockaddr*)&fromaddr, &clientAddressLength);
    if (receivedBytes == -1) {
        std::cerr << "Error receiving data" << std::endl;
    }
    buffer[receivedBytes] = 0;
    std::cout << "Received: " << buffer << std::endl;
}
