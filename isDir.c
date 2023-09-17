// C program to check a file is a directory or not

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int isDir(const char* fileName)
{
    struct stat path;

    stat(fileName, &path);

    return S_ISREG(path.st_mode);

}