#include <stdio.h>
#include <unistd.h>
#include "builtins.h"

int cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "myshell: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("myshell");
        }
    }
    return 1;
}

int my_exit(char **args) {
    return 0;
}
