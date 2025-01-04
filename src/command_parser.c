#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_parser.h"

#define MAX_ARGS 10

char **parse_command(char *line) {
    int position = 0;
    char **tokens = malloc(MAX_ARGS * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " ");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        token = strtok(NULL, " ");
    }
    tokens[position] = NULL;
    return tokens;
}
