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
    if (argc != 2) {
        std::cerr << "Usage " << argv[0] << " receiver_port" << std::endl;
        return 1;
    }
    std::cout << "I AM HERE RECEIVER" << std::endl;
    std::string receiverPort = argv[1];


    Receiver receiver(receiverPort, 3);


    receiver.ReceiveMessage();


    return 0;
}
