//
//  FunctionPointerDemo.h
//  DataStructuresAlgorithms
//
//  Created by Matt Finucane on 19/01/2017.
//  Copyright © 2017 Matt Finucane. All rights reserved.
//

#ifndef FunctionPointerDemo_h
#define FunctionPointerDemo_h

int addNums(int a, int b);
int subtractNums(int a, int b);
int multiplyNums(int a, int b);
int funcPointerAdjust(int (*functionPointer)(int, int));
int function_pointer_arguments_demo();
int function_pointer_demo_main(int num);

#endif /* FunctionPointerDemo_h */
