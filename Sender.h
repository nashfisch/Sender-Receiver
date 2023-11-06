#ifndef SENDER_H
#define SENDER_H
#include "SlidingWindow.h"
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <netdb.h>

class Sender : public SlidingWindow {
  public:
    Sender(const std::string& destinationHost, const std::string& destinationPort);
    void Initialize();
    void SendMessage(const std::string& message);

    //bool req(int SN);
    //int retransmit();
   


  private:
    std::string destHost;
    std::string destPort;
    int sock;
    struct addrinfo* destAddr;
    
};

#endif