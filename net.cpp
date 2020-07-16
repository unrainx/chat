#include "net.h"

std::string receive(int fd) {

    int n = 0;
    const size_t bufferSize = 4096;
    char buffer[bufferSize] = { 0 };
    std::string data = "";

    while ((n = recv(fd, buffer, bufferSize, 0)) > 0) {
        buffer[n] = 0;
        data += buffer;
    }

    return data;
}