.c files of tuls.c and tucp.c that compile commonly used commands ls and cp.

repository: https://github.com/eeng20/CIS-3207-P0AB-eeng20/tree/main

PART A:

tuls.c: Using C Library functions scandir(), opendir(), and readdir(), tuls takes 1 or 0 arguements. When given 0, it lists all of the current directory's files. When given 1 arguement, which is the directory's path, it identifies entries inside the given directory as a folder or another directory, which then recursively prints out those directory's files.
    This is done by creating a DIR structure. We then open a directory (checking if it exists, if not it returns an error messsage). Creating an entry by reading the open directory. For as long as that entry Exists, then it will distinguish: the type of the entry (folder or directory), and the name of the entry.
    To print out the files recursively, it will check the entry's type and if it is a directory AND it is not the Current directory, it will take its directory's name and create a path. It takes the original directory path, adds a "/" and then attaches the entry (that is found to be a Directory type) to the String path. Thus allowing us to recursively call upon the tuls again with the newly path name as the arguement.
After it's done with a directory, it closes the directory.
Finally, it prints out the current directory where the command was executed from.

PART B:

tucp.c: open source file read-only
create destination file for write
while there's still data in source file
    read data from source file
    write it to destination file
close both files

