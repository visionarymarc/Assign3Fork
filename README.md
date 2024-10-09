# Assign3Fork

## Description

This program is a simulation of process management using `fork()` in C. It creates an array of 20 random integers, and both a parent and child process work concurrently to find the minimum number from different halves of the array. The parent process handles the first half of the array, while the child process handles the second half.

The program showcases basic inter-process communication and demonstrates how to manage different sections of a shared resource (the array) using `fork()` and `wait()` for synchronization.

## Features
- Random number generation to fill an array of 20 elements.
- `fork()` to create a child process that works concurrently with the parent process.
- The parent process finds the minimum value in the first half of the array.
- The child process finds the minimum value in the second half of the array.
- Both processes print their Process IDs (`pid`) and their corresponding minimum values.
- Finally, the program compares both results and prints the overall minimum.

## Compilation and Usage

### Compilation
To compile the program, use the provided Makefile:
```bash
make
