.c files of tuls.c and tucp.c that compile commonly used commands ls and cp.

PART A:

tuls.c: Using C Library functions scandir(), opendir(), and readdir(), tuls takes 1 or 0 arguements. When given 0, it lists all of the current directory's files. When given 1 arguement, which is the directory's path, it identifies entries inside the given directory as a folder or another directory, which then recursively prints out those directory's files.
    This is done by opening a directory (checking if it exists, if not it returns an error messsage). Creating an entry by reading the open directory. For as long as that entry Exists, then it will print out: the type of the entry (folder or directory), and the name of the entry.
    After that, to print out the files recursively, it will check the entry's type and if it is a directory AND it is not the Current directory, it will take its directory's name and create a path. Thus allowing us to recursively call upon the tuls again with the newly path name as the arguement.
After it's done with a directory, it closes the directory.
Finally, it prints out the current directory where the command was executed from.

tucp.c: PART B

