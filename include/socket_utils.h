//
// Created by amucz0 on 9/27/24.
//

#ifndef WAKEANDCONNECT_SOCKET_UTILS_H
#define WAKEANDCONNECT_SOCKET_UTILS_H

int createSocket(const char* ipAddress, int port);
int startServer(const char* ipAddress, int port);
int acceptClient(int server_fd);

#endif // WAKEANDCONNECT_SOCKET_UTILS_H