#include "net.h"

int main(int argc, char ** argv) {
    
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address = { 0 };
    address.sin_family = AF_INET;
    address.sin_port = htons(8989);

    // inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
    inet_pton(AF_INET, "141.164.60.29", &address.sin_addr);

    int n = connect(socketFd, (struct sockaddr *)&address, sizeof(address));

    const size_t bufferSize = 1024;

    char buffer[bufferSize] = { 0 };

    std::string message = receive(socketFd);

    std::cout << message << std::endl;
}