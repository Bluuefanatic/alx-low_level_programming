#!/bin/bash

# Compile all .c files into .o files
gcc -c *.c

# Create the static library
ar rcs liball.a *.o

# Clean up the .o files
rm *.o
