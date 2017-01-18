//
//  LinkedList.h
//  DataStructuresAlgorithms
//
//  Created by Matt Finucane on 17/01/2017.
//  Copyright © 2017 Matt Finucane. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include "Person.h"

struct Person* setup(char *_firstname, char *_lastname, int _age);
struct Person* buildOneTwoThree();
struct Person* buildTwoThree();
void wrongPush(struct Person *head, char *_firstname, char *_lastname, int _age);
void push(struct Person **head_ref, char *_firstname, char *_lastname, int _age);
void append(struct Person **head_ref, char *_firstname, char *_lastname, int _age);
void changeToNull(struct Person **head_ref);
int listSize(struct Person *head);
void printItems(struct Person *head);
void paramaterModTest(int *a);

#endif /* LinkedList_h */
