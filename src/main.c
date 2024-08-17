#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>


void current_dir_name_path(const char *str) {
    char cwd[256];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        return;
    } else {
        char *ptr;
        ptr = strrchr(cwd, '/');
        if (ptr != NULL) {
            ptr++;
            if (strcmp(str, "pwdn") == 0) {
                printf("current directory name is: %s\n", ptr);
            } else if (strcmp(str, "pwdp") == 0) {
                printf("current directory path: %s\n", cwd);
            }
        }
    }
}

void list_directory(const char *str) {
    printf("listing stuff intensely\n");

    DIR *dir;
    struct dirent *entry;

    dir = opendir(str);

    if (dir == NULL) {
        perror("opendir() error");
        return;
    }

    while((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir); 
}

int main(int argc, char *argv[]) {
    //printf("Entered number of %d arguments\n", argc);

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        if (strcmp(arg, "pwdn") == 0) {
            printf("Entered: %s\n", arg);
            current_dir_name_path(arg);
        } else if (strcmp(arg, "pwdp") == 0) {
            printf("Entered: %s\n", arg);
            current_dir_name_path(arg);
        } else if (strcmp(arg, "lsc") == 0) {
            list_directory(".");                
        } else if (strcmp(arg, "ls") == 0 && argv[2] != NULL) {
            list_directory(argv[2]);
        } else {
            printf("Entered nothing good!\n");
        }
    }

    return 0;
}
