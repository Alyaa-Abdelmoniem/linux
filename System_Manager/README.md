Linux System Manager

 Project Description

Linux System Manager is a C++ console application designed to demonstrate basic Linux system programming concepts.

The project provides a simple menu that allows the user to interact with different Linux system features such as system information, processes, files, networking, signals, and multithreading.

 Technologies Used

* C++
* Linux
* Linux System Calls
* POSIX APIs
* Multithreading
* /proc filesystem

 Features

The program provides the following options:

1. System Information
    * Operating System
    * Hostname
    * Kernel Version
    * Architecture
2. Memory Information
    * Total Memory
    * Available Memory
3. Disk Information
    * Total Disk Space
    * Used Disk Space
    * Free Disk Space
4. Process Management
    * List running processes
    * Display process information
    * Create a child process
    * Send signals to processes
5. File Management
    * Display file information
    * File size
    * Owner UID
    * Group GID
    * File type
    * File permissions
    * Change file permissions
6. Network Management
    * Display network interfaces
    * Display IP addresses
    * Check interface state
    * Ping a host
    * DNS lookup
7. Multithreading
    * Create multiple threads
    * Run threads simultaneously
    * Wait for threads using join()

 Project Structure

Linux-System-Manager/
│
├── main.cpp
├── SystemInfo.cpp
├── SystemInfo.h
├── ProcessManager.cpp
├── ProcessManager.h
├── FileManager.cpp
├── FileManager.h
├── NetworkManager.cpp
├── NetworkManager.h
├── ThreadDemo.cpp
├── ThreadDemo.h
└── README.md

 How to Compile

Open the Linux terminal inside the project folder and run:

g++ *.cpp -o System_Manager -pthread

The -pthread option is required because the project uses C++ threads.

 How to Run

After successful compilation, run:

./System_Manager

The program will display the main menu:

============================
    LINUX SYSTEM MANAGER
============================
1. System Information
2. Memory Information
3. Disk Information
4. List Processes
5. Process Information
6. Create Child Process
7. Send Signal
8. File Information
9. Change File Permission
10. Network Information
11. Ping Host
12. DNS Lookup
13. Multi-Thread Demo
0. Exit

Enter the number of the required operation.

🐧 Linux Concepts Used

/proc

The project uses the Linux /proc filesystem to access information about processes and memory.

fork()

Used to create a child process.

waitpid()

Used by the parent process to wait for the child process.

kill()

Used to send signals to processes.

stat()

Used to retrieve information about files.

chmod()

Used to change file permissions.

getifaddrs()

Used to retrieve network interface information.

getaddrinfo()

Used for DNS lookup.

std::thread

Used to demonstrate multithreading in C++.

 Project Goal

The main goal of this project is to practice Linux system programming using C++ and understand how applications interact with the Linux operating system through system calls, the /proc filesystem, process management, file permissions, networking, and multithreading.
