#include "include/socket_utils.h"
#include "include/server.h"
#include <iostream>
#include <unistd.h>
#include <cstring>

int main() {
    Server server;
    //memory safety issue : study later
    char *path = getenv("HOME");
    strcat(path, "/.ssh/config");

    server.readConfig(path);

    int server_fd = startServer("XXX.XXX.XX.XXX", 56000);
    if (server_fd < 0) {
        cerr << "Failed to start the server." << endl;
        return 1;
    }

    while (true) {
        int client_fd = acceptClient(server_fd);
        if (client_fd < 0) {
            cerr << "Failed to accept client connection." << endl;
            continue;
        }
        server.handleClient(client_fd);
    }

    close(server_fd);
    return 0;
}