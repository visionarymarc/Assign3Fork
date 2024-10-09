/*
* Marcus Valbrun (R01873916)
* CSC343 Operations Systems

* Assignment 3 Question 3
* Write a C++ programs that creates and array of 20 elements. 
  Fill the array elements by using the random number generator. 
  Create a child process and finds the minimum number in the second half of the array. 
  Parent process will find the minimum number in the first half of the array. 
  Display the minimum numbers found in each process and their processor ids and finally the minimum number of the array.

* Due 2024-10-9 11:59 pm
* Assign3Fork.c
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <limits.h> 
/* 
Required for INT_MAX 

INT_MAX is a constant defined in <limits.h> that represents the largest value 
that an int type can hold in your system. It is system-dependent, 
but on most systems, this value is 2147483647 (for a 32-bit signed integer).

*/

#define ARRAY_SIZE 20  // Size of the array

// Function Declarations
/* 
* findMin: Finds the minimum value in a portion of the array
* Parameters: array (int[]) - the array to search, start (int) - starting index, end (int) - ending index
* Returns: int - the minimum value found
*/
int findMin(int array[], int start, int end);



/* Main Function

* Creates an array of random numbers and splits the task between parent and child processes
* Returns: 0 upon successful execution
*/
int main() {
    int array[ARRAY_SIZE];  // Array of 20 elements
    int parentMin, childMin;  // Variables to hold the minimum values
    pid_t pid;  // Process ID for fork

    // Seed the random number generator
    srand(time(NULL));

    // Fill the array with random numbers between 1 and 100
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100 + 1;
    }

    // Fork to create a child process
    pid = fork();

    if (pid < 0) {
        // Error occurred in fork
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }

    printf("\n");

    if (pid == 0) {
        // Child process: Find the minimum in the second half of the array
        childMin = findMin(array, ARRAY_SIZE / 2, ARRAY_SIZE);
        printf("Child Process (PID: %d) found minimum in second half: %d\n", getpid(), childMin);
        exit(0);  // Child process exits
    } else {
        // Parent process: Find the minimum in the first half of the array
        parentMin = findMin(array, 0, ARRAY_SIZE / 2);
        printf("Parent Process (PID: %d) found minimum in first half: %d\n", getpid(), parentMin);

        // Wait for child process to complete
        wait(NULL);

        // Find the overall minimum
        int overallMin = (parentMin < childMin) ? parentMin : childMin;
        printf("\nFinal Result: Overall Minimum Number in the Array is: %d\n", overallMin);
    }

    printf("\n");

        // Logic Check Print Report
    printf("\nLOGIC CHECK PRINTED ARRAY:\n");

    // Print the first half of the array
    printf("1st Half: ");
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    // Print the second half of the array
    printf("2nd Half: ");
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\n");



    return 0;
}

/* Function: findMin

* Finds the minimum value in a portion of the array
* Parameters: 
            array (int[]) - the array to search, 
            start (int) - starting index, 
            end (int) - ending index

* Returns: int - the minimum value found
*/
int findMin(int array[], int start, int end) {
    int min = INT_MAX;  // Initialize min to maximum possible integer value
    for (int i = start; i < end; i++) {
        if (array[i] < min) {
            min = array[i];  // Update min if a smaller value is found
        }
    }
    return min;
}
