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
    Sender(std::string& destinationHost, std::string& destinationPort, int max);
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
