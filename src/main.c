#include <stdio.h>
#include <string.h>
#include <unistd.h>


void current_dir_name() {
    char cwd[256];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
    } else {
        printf("current working directory is: %s\n", cwd);
    }
}

int main(int argc, char *argv[]) {
    //printf("Entered number of %d arguments\n", argc);

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        if (strcmp(arg, "pwd") == 0) {
            printf("Entered: %s\n", arg);
            //printf("Current dir is blabla\n");
            current_dir_name();
        } else {
            printf("Entered nothing good!\n");
        }
    }

    return 0;
}
