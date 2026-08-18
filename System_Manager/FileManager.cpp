#include "FileManager.h"
#include <iostream>
#include <sys/stat.h>

using namespace std;

void FileManager::fileInfo(string path)
{
    struct stat info;

    if (stat(path.c_str(), &info) != 0)
    {
        cout << "File does not exist" << endl;
        return;
    }

    cout << "File Size: " << info.st_size << " bytes" << endl;
    cout << "Owner UID: " << info.st_uid << endl;
    cout << "Group GID: " << info.st_gid << endl;

    if (S_ISREG(info.st_mode))
        cout << "File Type: Regular File" << endl;
    else if (S_ISDIR(info.st_mode))
        cout << "File Type: Directory" << endl;

    cout << "Permissions: "
         << ((info.st_mode & S_IRUSR) ? "r" : "-")
         << ((info.st_mode & S_IWUSR) ? "w" : "-")
         << ((info.st_mode & S_IXUSR) ? "x" : "-")
         << ((info.st_mode & S_IRGRP) ? "r" : "-")
         << ((info.st_mode & S_IWGRP) ? "w" : "-")
         << ((info.st_mode & S_IXGRP) ? "x" : "-")
         << ((info.st_mode & S_IROTH) ? "r" : "-")
         << ((info.st_mode & S_IWOTH) ? "w" : "-")
         << ((info.st_mode & S_IXOTH) ? "x" : "-")
         << endl;
}

void FileManager::changePermission(string path, int permission)
{
    if (chmod(path.c_str(), permission) == 0)
        cout << "Permission changed successfully" << endl;
    else
        cout << "Failed to change permission" << endl;
}
