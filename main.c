/* testing code ls with main */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "tuls.c"

void listFiles(const char *dirname) {
	DIR* dir = opendir(dirname);
	if (dir == NULL) {
		perror("tuls: cannot open directory");
		exit(1);
	}

	printf("\n\tReading files in: %s\n:", dirname);

	struct dirent* entry;
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
			listFiles(path);
		}
		// read files of the opened directory
		entry = readdir(dir);
	}
	closedir(dir);

	// read & prints files of the current directory
	dir = opendir(".");
	if (dir == NULL) {
		perror("tuls: cannot open directory");
		exit(1);
	}
	/* printf("\n\tReading files in: Current Directory");
	entry = readdir(dir);
	while (entry != NULL) {
		printf("%s\n", entry -> d_name);
		entry = readdir(dir);
		}
	closedir(dir); */

	}
int main(int argc, char const *argv[]) {
	listFiles("/home/TU/tul40997/CIS3207_Fall2023");
	return 0;

	}

