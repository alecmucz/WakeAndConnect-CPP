//
// Created by amucz0 on 10/4/24.
//

#include "../include/protocols.h"

void sendWake(const char *macAddress){

}

void sendConnect(const char *ipAddress, const char *hostName){

}

void sendWAC(const char *macAddress, const char *ipAddress, const char *hostName){
    sendWake(macAddress);
    sendConnect(ipAddress, hostName);
}