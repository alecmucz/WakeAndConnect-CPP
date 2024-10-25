//
// Created by amucz0 on 10/17/24.
//
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <regex>
#include "../include/server.h"

void Server::handleClient(int client_fd) {
    cout << "Client Connected" << endl;
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

void Server::readConfig(const string& filePath) {
    ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Failed to open config file: " << filePath << std::endl;
        return;
    }

    string key;
    DeviceInfo device;

    string line;
    string sKey;
    while (getline(inputFile, line)) {
        line.erase(line.begin(),find_if(
                line.begin(),line.end(),not_fn(::isspace)));

        sKey = line.substr(0, distance(line.begin(), find_if(line.begin(), line.end(), ::isspace)));

        if (sKey == "Host"){
            key = line.substr(line.find(' ')+1, -1);
            device.Host = line.substr(line.find(' ')+1, -1);
        } else if (sKey == "HostName") {
            device.IPaddress = line.substr(line.find(' ') + 1);
        } else if (sKey == "User"){
            device.User = line.substr(line.find(' ') + 1);
        } else if (sKey == "Port"){
            device.port = line.substr(line.find(' ') + 1);
        } else if (sKey == "# Mac" || sKey == "Mac" || sKey == "#" || sKey == "# "){
            std::regex macR(R"((?:[[:xdigit:]]{2}([-:]))(?:[[:xdigit:]]{2}\1){4}[[:xdigit:]]{2})");
            smatch match;

            if (std::regex_search(line, match, macR)) {
                device.Mac = match.str(0);
            } else {
                device.Mac = "";
            }
        }

        sshContents[key] = device;
    }
    //for (const auto& pair : sshContents) {
    //    cout << "Host: " << pair.first << endl
    //         << "IP: " << pair.second.IPaddress << endl
    //         << "User: " << pair.second.User << endl
    //         << "Port: " << pair.second.port << endl
    //         << "Mac: " << pair.second.Mac << endl;
    //}
}


