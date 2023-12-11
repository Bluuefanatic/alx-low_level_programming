#!/bin/bash

# Compile all .c files into a dynamic library
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -shared -fPIC -o liball.so *.c
