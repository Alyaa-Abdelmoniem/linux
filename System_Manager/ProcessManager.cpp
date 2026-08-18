#include "ProcessManager.h"
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string>

using namespace std;

void ProcessManager::listProcesses()
{
    DIR* dir = opendir("/proc");

    if (!dir)
    {
        cout << "Cannot open /proc" << endl;
        return;
    }

    struct dirent* entry;

    while ((entry = readdir(dir)) != nullptr)
    {
        string name = entry->d_name;

        if (isdigit(name[0]))
        {
            ifstream file("/proc/" + name + "/status");

            string line;
            string processName;
            string state;
            string ppid;

            while (getline(file, line))
            {
                if (line.find("Name:") == 0)
                    processName = line;

                if (line.find("State:") == 0)
                    state = line;

                if (line.find("PPid:") == 0)
                    ppid = line;
            }

            cout << "PID: " << name << endl;
            cout << processName << endl;
            cout << state << endl;
            cout << ppid << endl;
            cout << "----------------------" << endl;
        }
    }

    closedir(dir);
}

void ProcessManager::processInfo(int pid)
{
    string path = "/proc/" + to_string(pid) + "/status";

    ifstream file(path);

    if (!file)
    {
        cout << "Process does not exist" << endl;
        return;
    }

    string line;

    while (getline(file, line))
    {
        if (line.find("Name:") == 0 ||
            line.find("State:") == 0 ||
            line.find("Pid:") == 0 ||
            line.find("PPid:") == 0 ||
            line.find("Threads:") == 0 ||
            line.find("VmSize:") == 0)
        {
            cout << line << endl;
        }
    }
}

void ProcessManager::createChild()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        cout << "[Child]" << endl;
        cout << "PID: " << getpid() << endl;
        cout << "PPID: " << getppid() << endl;

        _exit(42);
    }
    else if (pid > 0)
    {
        cout << "[Parent]" << endl;
        cout << "PID: " << getpid() << endl;

        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            cout << "Child exit status: "
                 << WEXITSTATUS(status) << endl;
        }
    }
    else
    {
        cout << "Fork failed" << endl;
    }
}

void ProcessManager::sendSignal(int pid, int signalNumber)
{
    if (kill(pid, signalNumber) == 0)
        cout << "Signal sent successfully" << endl;
    else
        cout << "Failed to send signal" << endl;
}
