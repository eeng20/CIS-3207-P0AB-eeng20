/* PART B: tucp.c */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>				// recur & visit directories
#include <sys/stat.h>			// determine what a file object is
#include "isDir.c"


void tucp(const char *name, const char *cfile) {
    if (isDir(cfile) == 0) {
        printf("cfile IS A DIRECTORY\n");
        DIR* dir = opendir(cfile);
        FILE * file = fopen(name, "r");
        FILE * copy = fopen(name, "w");
        if (file == NULL || copy == NULL) {
            perror("Error: Could not copy file\n");
            exit(EXIT_FAILURE);
        }
    char c;
    while ( (c = fgetc(file)) != EOF) {
        fputc(c, copy);
    }
    fclose(file);
    fclose(copy);
    closedir(dir);

    }

    // FILE * file = fopen(name, "r");

    // FILE * copy = fopen(cfile, "w");


    // if (file == NULL || copy == NULL) {
    //     perror("Error: Could not copy file\n");
    //     exit(EXIT_FAILURE);
    // }

    // char c;
    // while ( (c = fgetc(file)) != EOF) {
    //     fputc(c, copy);
    // }
    // fclose(file);
    // fclose(copy);
}

int main (int argc, char const *argv[]) {
    if (argc < 1 ) {
        perror("tucp: cannot copy file\n");
        exit(EXIT_FAILURE);
    }
    else {
        for (int i = 0; i < argc-1; i++) {
            tucp(argv[i], argv[argc-1]);
        }
    }

    return(0);
}