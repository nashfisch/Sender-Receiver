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
    if (argc != 4) {
        std::cerr << "Usage " << argv[0] << " sender_host, sender_port, receiver_port" << std::endl;
        return 1;
    }

    std::string senderDes = argv[1];
    std::string senderPort = argv[2];
    std::string receiverPort = argv[3];

    Sender sender(senderDes, senderPort);
    Receiver receiver(receiverPort);

    sender.SendMessage("Hello world!");

    receiver.ReceiveMessage();


    return 0;
}