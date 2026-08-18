#include <iostream>
#include "SystemInfo.h"
#include "ProcessManager.h"
#include "FileManager.h"
#include "NetworkManager.h"
#include "ThreadDemo.h"

using namespace std;

int main()
{
    SystemInfo systemInfo;
    ProcessManager processManager;
    FileManager fileManager;
    NetworkManager networkManager;
    ThreadDemo threadDemo;

    int choice;

    do
    {
        cout << "\n============================\n";
        cout << "    LINUX SYSTEM MANAGER\n";
        cout << "============================\n";

        cout << "1. System Information\n";
        cout << "2. Memory Information\n";
        cout << "3. Disk Information\n";
        cout << "4. List Processes\n";
        cout << "5. Process Information\n";
        cout << "6. Create Child Process\n";
        cout << "7. Send Signal\n";
        cout << "8. File Information\n";
        cout << "9. Change File Permission\n";
        cout << "10. Network Information\n";
        cout << "11. Ping Host\n";
        cout << "12. DNS Lookup\n";
        cout << "13. Multi-Thread Demo\n";
        cout << "0. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            systemInfo.showSystemInfo();

        else if (choice == 2)
            systemInfo.showMemoryInfo();

        else if (choice == 3)
            systemInfo.showDiskInfo();

        else if (choice == 4)
            processManager.listProcesses();

        else if (choice == 5)
        {
            int pid;
            cout << "Enter PID: ";
            cin >> pid;

            processManager.processInfo(pid);
        }

        else if (choice == 6)
            processManager.createChild();

        else if (choice == 7)
        {
            int pid, signalChoice;

            cout << "Enter PID: ";
            cin >> pid;

            cout << "1. SIGTERM\n";
            cout << "2. SIGSTOP\n";
            cout << "3. SIGCONT\n";
            cout << "4. SIGKILL\n";

            cin >> signalChoice;

            if (signalChoice == 1)
                processManager.sendSignal(pid, SIGTERM);
            else if (signalChoice == 2)
                processManager.sendSignal(pid, SIGSTOP);
            else if (signalChoice == 3)
                processManager.sendSignal(pid, SIGCONT);
            else if (signalChoice == 4)
                processManager.sendSignal(pid, SIGKILL);
        }

        else if (choice == 8)
        {
            string path;

            cout << "Enter file path: ";
            cin >> path;

            fileManager.fileInfo(path);
        }

        else if (choice == 9)
        {
            string path;
            int permission;

            cout << "Enter file path: ";
            cin >> path;

            cout << "Enter permission: ";
            cin >> oct >> permission;

            fileManager.changePermission(path, permission);

            cin >> dec;
        }

        else if (choice == 10)
            networkManager.showNetwork();

        else if (choice == 11)
        {
            string host;

            cout << "Enter host: ";
            cin >> host;

            networkManager.ping(host);
        }

        else if (choice == 12)
        {
            string host;

            cout << "Enter hostname: ";
            cin >> host;

            networkManager.dnsLookup(host);
        }

        else if (choice == 13)
            threadDemo.run();

        else if (choice != 0)
            cout << "Invalid choice" << endl;

    } while (choice != 0);

    cout << "Goodbye!" << endl;

    return 0;
}
