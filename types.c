#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    //argv[1] is the first directory
    //argc contains the length of argv
    struct stat st;
    for (int i = 1; i < argc; i++){
        if (stat(argv[i], &st) < 0){
            printf("%s: path error\n", argv[i]);
        }else{
            if (S_ISREG(st.st_mode)){
                printf("%s: regular file\n", argv[i]);
            }else if (S_ISDIR(st.st_mode)){
                printf("%s: directory\n", argv[i]);
            }
            else if (S_ISCHR(st.st_mode)){
                printf("%s: character device\n", argv[i]);
            }
            else if (S_ISBLK(st.st_mode)){
                printf("%s: block device\n", argv[i]);
            }
            else if (S_ISFIFO(st.st_mode)){
                printf("%s: FIFO\n", argv[i]);
            }
            else if (S_ISLNK(st.st_mode)){
                printf("%s: symbolic link\n", argv[i]);
            }
            else if (S_ISSOCK(st.st_mode)){
                printf("%s: socket\n", argv[i]);
            }
        }
    }
}