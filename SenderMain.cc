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
    std::string message = "";

    Sender sender(senderDes, senderPort, 3);
    std::cout << "Enter a message: ";
    std::getline(std::cin, message);
    sender.SendMessage(message);


    return 0;
}
