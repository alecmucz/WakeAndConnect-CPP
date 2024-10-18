#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include "../include/socket_utils.h"

int createSocket(const char* ipAddress, int port) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Failed to create socket: " << strerror(errno) << std::endl;
        return -1;
    }

    struct sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ipAddress, &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid IP address" << std::endl;
        close(server_fd);
        return -1;
    }

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed: " << strerror(errno) << std::endl;
        close(server_fd);
        return -1;
    }

    return server_fd;
}

int startServer(const char* ipAddress, int port) {
    int server_fd = createSocket(ipAddress, port);
    if (server_fd < 0) return -1;

    if (listen(server_fd, SOMAXCONN) < 0) {
        std::cerr << "Listening failed: " << strerror(errno) << std::endl;
        close(server_fd);
        return -1;
    }

    return server_fd;
}

int acceptClient(int server_fd) {
    struct sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);
    return accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
}
