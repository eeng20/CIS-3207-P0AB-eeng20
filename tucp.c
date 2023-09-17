/* PART B: tucp.c */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>				// recur & visit directories
#include <sys/stat.h>			// determine what a file object is


void tucp(const char *name, const char *cfile) {
    FILE *file, *copy;
    DIR *folder;
    folder = opendir(cfile);
    if (folder == NULL) {
        FILE *file = fopen(name, "r");
        FILE *copy = fopen(cfile, "w");
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
        printf("File copied successfully.\n");

    }

    else {
        char copyName[1000] = {0};
        strcat(copyName, cfile);
        strcat(copyName, "/");
        strcat(copyName, name);

        // opens source file in read mode
        file = fopen(name, "r");
        if (file == NULL) {
            perror("Error opening source file");
            exit(EXIT_FAILURE);
        }

        // opens or creates copy file in write mode
        copy = fopen(copyName, "wb");
        if (copy == NULL) {
            perror("Error: Could not copy file\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        // copy file
        char c;
        while ( (c = fgetc(file)) != EOF) {
            fputc(c, copy);
        }
        fclose(file);
        fclose(copy);
        printf("File copied successfully.\n");


    }


}

int main (int argc, char const *argv[]) {
    if (argc < 1 ) {
        perror("tucp: cannot copy file\n");
        exit(EXIT_FAILURE);
    }
    else {
        for (int i = 1; i < argc-1; i++) {
            tucp(argv[i], argv[argc-1]);
        }
    }

    return(0);
}