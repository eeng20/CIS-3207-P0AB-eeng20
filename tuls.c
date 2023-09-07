/* code for tuls */
//#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>				// recur & visit directories
#include <sys/stat.h>			// determine what a file object is

int tuls(char *path) {
	struct dirent **namelist;
	int n;

	n = scandir(path, &namelist, NULL, alphasort);
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
    exit(EXIT_SUCCESS);
}
