#include <iostream>
#include <vector>
#include "Sender.h"

/*
Sender::Sender(int max) : SlidingWindow(max){}
int Sender::retransmit(){
    return unacknowledgedNums[0];
}*/

Sender::Sender(const std::string& destinationHost, const std::string& destinationPort) {
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
}