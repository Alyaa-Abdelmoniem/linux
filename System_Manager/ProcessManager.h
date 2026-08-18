#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

class ProcessManager
{
public:
    void listProcesses();
    void processInfo(int pid);
    void createChild();
    void sendSignal(int pid, int signalNumber);
};

#endif
