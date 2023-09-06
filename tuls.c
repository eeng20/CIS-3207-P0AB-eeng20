/* code for tuls */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>				// recur & visit directories
#include <sys/stat.h>			// determine what a file object is



int tuls(directory) {

	struct dirent **namelist;
	int n; 
	n=scandir(directory,&namelist,NULL,alphasort);
	
	exit(0);
	// printf("INVALID ARGUEMENT"); 
	// exit(NON_ZERO_INT);
}
