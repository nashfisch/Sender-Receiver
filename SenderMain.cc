#include "Sender.h"
#include "Receiver.h"
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <netdb.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage " << argv[0] << " sender_host, sender_port" << std::endl;
        return 1;
    }

    std::string senderDes = argv[1];
    std::string senderPort = argv[2];

    Sender sender(senderDes, senderPort, 3);
    std::cout << "I AM HERE SENDER" << std::endl;
    sender.SendMessage("Hello world!");


    return 0;
}
