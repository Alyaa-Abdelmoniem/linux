#include "NetworkManager.h"
#include <iostream>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void NetworkManager::showNetwork()
{
    struct ifaddrs* interfaces;

    if (getifaddrs(&interfaces) == -1)
    {
        cout << "Cannot get network information" << endl;
        return;
    }

    for (struct ifaddrs* i = interfaces; i != nullptr; i = i->ifa_next)
    {
        if (i->ifa_addr &&
            i->ifa_addr->sa_family == AF_INET)
        {
            char address[INET_ADDRSTRLEN];

            sockaddr_in* ip =
                (sockaddr_in*)i->ifa_addr;

            inet_ntop(AF_INET,
                      &ip->sin_addr,
                      address,
                      sizeof(address));

            cout << "Interface: " << i->ifa_name << endl;
            cout << "IP: " << address << endl;
            cout << "State: "
                 << ((i->ifa_flags & IFF_UP) ? "UP" : "DOWN")
                 << endl;
            cout << "----------------------" << endl;
        }
    }

    freeifaddrs(interfaces);
}

void NetworkManager::ping(string host)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        execlp("ping", "ping", "-c", "3",
               host.c_str(), nullptr);

        _exit(1);
    }
    else if (pid > 0)
    {
        waitpid(pid, nullptr, 0);
    }
    else
    {
        cout << "Fork failed" << endl;
    }
}

void NetworkManager::dnsLookup(string host)
{
    struct addrinfo hints{}, *result;

    hints.ai_family = AF_INET;

    if (getaddrinfo(host.c_str(), nullptr,
                    &hints, &result) != 0)
    {
        cout << "DNS lookup failed" << endl;
        return;
    }

    char address[INET_ADDRSTRLEN];

    sockaddr_in* ip =
        (sockaddr_in*)result->ai_addr;

    inet_ntop(AF_INET,
              &ip->sin_addr,
              address,
              sizeof(address));

    cout << "IP Address: " << address << endl;

    freeaddrinfo(result);
}
