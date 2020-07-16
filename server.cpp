#include "net.h"

int main(int argc, char ** argv) {
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddress = { 0 };
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8989);

    int n = bind(socketFd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if (n != -1) {
        std::cout << "bind successfully\n";
    }
    n = listen(socketFd, 10);

    const size_t bufferSize = 1024;
    std::string message = "";

    char buffer[bufferSize] = { 0 };

    while (true) {
        int connection = accept(socketFd, NULL, NULL);
        time_t ticks = time(NULL);
        snprintf(buffer, sizeof(buffer), "%.24s\r\n", ctime(&ticks));
        send(connection, buffer, sizeof(buffer), 0);
        close(connection);
    }

}
