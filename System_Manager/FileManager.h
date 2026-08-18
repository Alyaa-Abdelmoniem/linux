#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager
{
public:
    void fileInfo(std::string path);
    void changePermission(std::string path, int permission);
};

#endif
