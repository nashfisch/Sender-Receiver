#include <iostream>
#include <vector>
#include "Receiver.h"

Receiver::Receiver(int max) : SlidingWindow(max){
    setMax(max);
    setWinSize(1);
}