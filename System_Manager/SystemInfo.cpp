#include "SystemInfo.h"
#include <iostream>
#include <sys/utsname.h>
#include <sys/statvfs.h>
#include <fstream>
#include <string>

using namespace std;

void SystemInfo::showSystemInfo()
{
    struct utsname info;

    if (uname(&info) == 0)
    {
        cout << "Operating System: " << info.sysname << endl;
        cout << "Hostname: " << info.nodename << endl;
        cout << "Kernel Version: " << info.release << endl;
        cout << "Architecture: " << info.machine << endl;
    }
}

void SystemInfo::showMemoryInfo()
{
    ifstream file("/proc/meminfo");
    string name;
    long value;
    string unit;

    while (file >> name >> value >> unit)
    {
        if (name == "MemTotal:")
            cout << "Total Memory: " << value / 1024 << " MB" << endl;

        if (name == "MemAvailable:")
            cout << "Available Memory: " << value / 1024 << " MB" << endl;
    }
}

void SystemInfo::showDiskInfo()
{
    struct statvfs disk;

    if (statvfs("/", &disk) == 0)
    {
        unsigned long long total =
            disk.f_blocks * disk.f_frsize;

        unsigned long long freeSpace =
            disk.f_bfree * disk.f_frsize;

        unsigned long long used =
            total - freeSpace;

        cout << "Total Disk: " << total / (1024 * 1024 * 1024)
             << " GB" << endl;

        cout << "Used Disk: " << used / (1024 * 1024 * 1024)
             << " GB" << endl;

        cout << "Free Disk: " << freeSpace / (1024 * 1024 * 1024)
             << " GB" << endl;
    }
}
