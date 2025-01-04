# Custom Shell

This project implements a simple custom command-line shell in C with support for a few built-in commands and scripting.

## Features
- Basic command execution
- Built-in commands: `cd`, `exit`
- Simple command parsing

## Installation
Clone the repository:
```sh
    git clone https://github.com/eldoJr/custom_shell-C.git
```


## Navigate into the project directory:
```sh
    cd custom_shell-C
```

## Running the Shell
To run the custom shell, use the following command:
```sh
./myshell
```
## Compile the source code:
```sh
    gcc -Wall -g -o custom_shell src/main.c src/command_parser.c src/builtins.c src/executor.c
```
## Usage
```bash
    ./custom_shell
```
License
This project is licensed under the ![MIT License](./LICENSE.txt) - see the LICENSE file for details.
 
