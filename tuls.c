/* code for tuls */
//#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>				// recur & visit directories
#include <sys/stat.h>			// determine what a file object is

int tuls(int argc, char const *argv[]) {
    struct dirent **namelist;
    int n;
	if (argc != 0) {
        n = scandir(argv[0], &namelist, NULL, alphasort);
        if (n == -1) {
            perror("scandir");
            exit(EXIT_FAILURE);
        }

        else {
            for (int i = 0; i < n; i++) {
                    printf("%s\n", namelist[i]->d_name);
                    free(namelist[i]);
                }
        }
    }
    n = scandir(".", &namelist, NULL, alphasort);
    if (n == -1) {
        perror("scandir");
        exit(EXIT_FAILURE);
    }

    else {
        for (int i = 0; i < n; i++) {
            printf("%s\n", namelist[i]->d_name);
            }
            }
    free(namelist);
    exit(EXIT_SUCCESS);
}

