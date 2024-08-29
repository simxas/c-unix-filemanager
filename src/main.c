#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>


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

void changing_directory(const char *path) {
    int dir_change = chdir(path);
    if (dir_change == 0) {
        printf("%s\n", path);
        current_dir_name_path("pwdn");    
        list_directory(".");
    } else {
        perror("chdir() error");
    }
}

void create_dir(const char *path, const char *name) {
    struct stat st = {0};
    char combined_string[100];
    
    if (strcmp(path, ".") == 0) {
        if (stat(name, &st) != -1) {
             printf("Directory exists\n");
        } else {
            if (mkdir((name), 0755) == 0) {
                printf("Directory created\n");
            } else {
                perror("mkdir() error");
            }
        }
    } else {
        sprintf(combined_string, path, name);
        printf("%s\n", combined_string);
        if (mkdir((combined_string), 0755) == 0) {
            printf("Directory created\n");
        } else {
            perror("mkdir() error");
        }
    }
}


int main(int argc, char *argv[]) {
    //printf("Entered number of %d arguments\n", argc);

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        if (strcmp(arg, "pwdn") == 0) {
            printf("Entered: %s\n", arg);
            current_dir_name_path(arg);
            break;
        } else if (strcmp(arg, "pwdp") == 0) {
            printf("Entered: %s\n", arg);
            current_dir_name_path(arg);
            break;
        } else if (strcmp(arg, "lsc") == 0) {
            list_directory(".");
            break;                
        } else if (strcmp(arg, "ls") == 0 && i + 1 < argc) {
            list_directory(argv[i + 1]);
            break;
        } else if (strcmp(arg, "cd") == 0 && i + 1 < argc) {
            changing_directory(argv[i + 1]);
            break;
        } else if (strcmp(arg, "cdir") == 0) {
            if (i + 2 < argc) { // Two arguments after "cdir"
                create_dir(argv[i + 1], argv[i + 2]);
            } else if (i + 1 < argc) { // One argument after "cdir"
                create_dir(".", argv[i + 1]);                
            } else {
                printf("Error: no directory name provided \n");
            }
            break;
        } else {
            printf("Entered nothing good!\n");
        }
    }

    return 0;
}
