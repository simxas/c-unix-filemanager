#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    //printf("Entered number of %d arguments\n", argc);

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        if (strcmp(arg, "pwd") == 0) {
            printf("Entered: %s\n", arg);
            printf("Current dir is blabla\n");
        } else {
            printf("Entered nothing good!\n");
        }
    }

    return 0;
}
