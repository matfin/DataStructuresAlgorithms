//
//  FunctionPointerDemo.c
//  DataStructuresAlgorithms
//
//  Created by Matt Finucane on 19/01/2017.
//  Copyright © 2017 Matt Finucane. All rights reserved.
//

#include <stdio.h>
#include "FunctionPointerDemo.h"

/**
 *  Simple function to add, subtract and multiply numbers.
 */
int addNums(int a, int b) {
    return a + b;
}

int subtractNums(int a, int b) {
    return a - b;
}

int multiplyNums(int a, int b) {
    return a * b;
}

/**
 *  This function takes a pointer to another function and calls it,
 *  returning the value as an int.
 */
int funcPointerAdjust(int (*fucntionPointer)(int, int)) {
    /**
     *  To call the function, we need to 
     *  dereference the pointer to it to 
     *  get the actual function.
     */
    return (*fucntionPointer)(10, 20);
}

int function_pointer_arguments_demo() {
    /**
     *  Declare some of pointers to functions.
     */
    int (*numAddPtr)(int, int) = &addNums;
    int (*numSubPtr)(int, int) = &subtractNums;
    int (*numsMulPtr)(int, int) = &multiplyNums;
    
    int added = funcPointerAdjust(numAddPtr);
    int subtracted = funcPointerAdjust(numSubPtr);
    int multiplied = funcPointerAdjust(numsMulPtr);
    
    printf("added: %i, subtracted: %i, multiplied: %i \n", added, subtracted, multiplied);
    
    return 0;
}

int function_pointer_demo_main(int num) {
    
    /**
     *  Setting up a pointer to the addNums function:
     *  - we need to declare the return type
     *  - then declare the name using pointer notation
     *  - then specify the parameters in brackets
     */
    int (*numFuncPtr)(int, int);
    
    /**
     *  If the number passed in is positive we add to it
     *  or we subtract from it.
     *
     *  We do this by pointing to the function we are going to use.
     */
    if(num > 0 ) {
        numFuncPtr = &addNums;
    }
    else {
        numFuncPtr = &subtractNums;
    }
    
    /**
     *  We can then call the function being pointed to
     *  and return the result.
     *  To do this, we access the function by dereferencing it
     *  and pass in the parameters in brackets.
     */
    return (*numFuncPtr)(num, 10);
}

