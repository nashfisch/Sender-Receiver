#ifndef RECEIVER_H
#define RECEIVER_H
#include "SlidingWindow.h"
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <netdb.h>



class Receiver : public SlidingWindow {
  public:
    /***
     * @brief Constructor
     * @param max: max window size
    */
    //Receiver(int max);
    Receiver(const std::string& listenPort);

    void Initalize();

    void BounceBack(const std::string& message);
    
  private:
  const std::string lPort;
    // Sequence number of the last in sequence frame received
    //int lastAck;
};

#endif
