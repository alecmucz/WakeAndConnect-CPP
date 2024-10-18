//
// Created by amucz0 on 10/17/24.
//
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/server.h"

void Server::handleClient(int client_fd) {
    char buffer[1024] = {0};
    const char* welcome_message = "Welcome to wake and connect\n";
    send(client_fd, welcome_message, strlen(welcome_message), 0);

    while (true) {
        ssize_t bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) break;
        buffer[bytes_received] = '\0';
        // Process commands (WAKE, CONNECT, etc.)

    }

    close(client_fd);
}

void Server::readConfig(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Failed to open config file: " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        // Parse config and populate sshContents
    }
}
