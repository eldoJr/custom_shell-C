#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "command_parser.h"
#include "builtins.h"
#include "executor.h"

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("Welcome to myshell! Type 'exit' to quit.\n");

    while (1) {
        printf("\033[1;32mmyshell>\033[0m "); // Colored prompt
        nread = getline(&line, &len, stdin);
        if (nread == -1) {
            perror("Error reading input with getline");
            free(line);
            exit(EXIT_FAILURE);
        }

        // Remove newline character
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }

        // Ignore empty commands
        if (strlen(line) == 0) {
            continue;
        }

        // Handle 'exit' command
        if (strcmp(line, "exit") == 0) {
            printf("Exiting myshell. Bye!\n");
            break;
        }

        execute_command(line);
    }

    free(line); // Clean up
    return 0;
}
