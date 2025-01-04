#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "command_parser.h"
#include "builtins.h"

void execute_command(char *line) {
    char **args = parse_command(line);

    if (strcmp(args[0], "cd") == 0) {
        cd(args);
    } else if (strcmp(args[0], "exit") == 0) {
        free(args);
        exit(EXIT_SUCCESS);
    } else {
        pid_t pid;
        int status;
        pid = fork();
        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
        } else {
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    free(args);
}
