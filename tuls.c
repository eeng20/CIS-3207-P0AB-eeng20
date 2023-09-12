/* PART A: tuls.c*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>				// recur & visit directories
#include <sys/stat.h>			// determine what a file object is

void tuls(const char *name) {
	DIR* dir = opendir(name);
	if (dir == NULL) {
		perror("tuls: cannot open directory\n");
		exit(1);
	}
    struct dirent* entry;
    printf("\n\tFiles in: %s\n:", name);
    entry = readdir(dir);
    while (entry != NULL) {
        printf("%s\n", entry -> d_name);

        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[100] = {0};
            strcat(path, name);
            strcat(path, "/");
            strcat(path, entry->d_name);
            tuls(path);
        }
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


	printf("\n\tFiles in: Current Directory");
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

    // recursive code portion assist https://www.youtube.com/watch?v=j9yL30R6npk&ab_channel=CodeVault