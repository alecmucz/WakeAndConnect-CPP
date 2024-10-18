//
// Created by amucz0 on 10/4/24.
//

#ifndef WAKEANDCONNECT_PROTOCOLS_H
#define WAKEANDCONNECT_PROTOCOLS_H


void sendWake(const char *macAddress);
void sendConnect(const char *ipAddress, const char *hostName);
void sendWAC(const char *macAddress, const char *ipAddress, const char *hostName);


#endif //WAKEANDCONNECT_PROTOCOLS_H
