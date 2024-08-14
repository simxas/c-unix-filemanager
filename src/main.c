#include <stdio.h>
#include <string.h>
#include <unistd.h>


void current_dir_name(const char *str) {
    char cwd[256];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
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
        //printf("current working directory is: %s\n", cwd);
    }
}

int main(int argc, char *argv[]) {
    //printf("Entered number of %d arguments\n", argc);

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        if (strcmp(arg, "pwdn") == 0) {
            printf("Entered: %s\n", arg);
            //printf("Current dir is blabla\n");
            current_dir_name(arg);
        } else if (strcmp(arg, "pwdp") == 0) {
            printf("Entered: %s\n", arg);
            current_dir_name(arg);
        } else {
            printf("Entered nothing good!\n");
        }
    }

    return 0;
}
