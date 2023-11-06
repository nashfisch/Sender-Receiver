#include <iostream>
#include <vector>
#include "Receiver.h"

/*
Receiver::Receiver(int max) : SlidingWindow(max){
    setMax(max);
    setWinSize(1);
}*/

Receiver::Receiver(const std::string listenPort) {
    lPort = listenPort;
    Initialize();
} 