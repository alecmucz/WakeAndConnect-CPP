//
// Created by amucz0 on 10/17/24.
//

#ifndef WAKEANDCONNECT_SERVER_H
#define WAKEANDCONNECT_SERVER_H

#include <string>
#include <unordered_map>

using namespace std;
struct DeviceInfo {
    std::string IPaddress;
    std::string Host;
    std::string User;
    std::string Mac;
};

class Server {
private:
    unordered_map<std::string, DeviceInfo> sshContents;

public:
    void handleClient(int client_fd);
    void readConfig(const std::string& filePath);
};

#endif //WAKEANDCONNECT_SERVER_H
