#include "include/socket_utils.h"
#include "include/server.h"
#include <iostream>
#include <unistd.h>

int main() {
    Server server;
    int server_fd = startServer("XXX.XXX.XX.XXX", 56000);
    if (server_fd < 0) {
        std::cerr << "Failed to start the server." << std::endl;
        return 1;
    }

    while (true) {
        int client_fd = acceptClient(server_fd);
        if (client_fd < 0) {
            std::cerr << "Failed to accept client connection." << std::endl;
            continue;
        }
        server.handleClient(client_fd);
    }

    close(server_fd);
    return 0;
}