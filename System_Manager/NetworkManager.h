#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <string>

class NetworkManager
{
public:
    void showNetwork();
    void ping(std::string host);
    void dnsLookup(std::string host);
};

#endifv
