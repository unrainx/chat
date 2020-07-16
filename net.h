#ifndef RAIN_NET_H__
#define RAIN_NET_H__

#include <string>
#include <iostream>
#include <cstring>

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

std::string receive(int fd);

#endif // !RAIN_NET_H__