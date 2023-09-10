/* code for tuls */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>				// recur & visit directories
#include <sys/stat.h>			// determine what a file object is

void tuls(const char *dirname) {
	DIR* dir = opendir(dirname);
	if (dir == NULL) {
		perror("tuls: cannot open directory\n");
		exit(1);
	}
    struct dirent* entry;
    printf("\n\tReading files in: %s\n:", dirname);
    entry = readdir(dir);
    while (entry != NULL) {
        // prints type of file & name
        printf("%hhd %s%s\n", entry->d_type, dirname, entry->d_name);
        // checks if entry is a file or a directory (avoids current "." and "..")
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[100] = {0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entry->d_name);
        // recursively prints files
            tuls(path);
        }
        // read files of the opened directory
        entry = readdir(dir);
    }

    closedir(dir);
	}

int main(int argc, char const *argv[]) {
	if (argc == 2) {
        tuls(argv[1]);
    }
    else if (argc > 2) {
        perror("tuls: cannot open directory\n");
        exit(EXIT_FAILURE);
    }
    // read & prints files of the current directory
	printf("\n\tReading files in: Current Directory");
	struct dirent **namelist;
    int n;
    int i = 0;


    n = scandir(".", &namelist, NULL, alphasort);
    if (n == -1) {
        perror("scandir");
        exit(EXIT_FAILURE);
    }
    else {
        for (i = 0; i < n; i++) {
                printf("%s\n", namelist[i]->d_name);
                free(namelist[i]);
                }
            }
    free(namelist);

	return(0);

	}

    // code https://www.youtube.com/watch?v=j9yL30R6npk&ab_channel=CodeVault