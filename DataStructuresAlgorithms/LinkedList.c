//
//  LinkedList.c
//  DataStructuresAlgorithms
//
//  Created by Matt Finucane on 17/01/2017.
//  Copyright © 2017 Matt Finucane. All rights reserved.
//

#include "LinkedList.h"

struct Person* setup(char *_firstname, char *_lastname, int _age) {
    /**
     *  Define a pointer to a Person struct
     *  and allocate some memory for it.
     */
    struct Person *p = NULL;
    p = malloc(sizeof(struct Person));
    /**
     *  Then set the parameters using the 
     *  function arguments.
     */
    p->firstname = _firstname;
    p->lastname = _lastname;
    p->age = _age;
    p->next = NULL;
    /**
     *  Then return the pointer.
     */
    return p;
}

struct Person* buildOneTwoThree() {
    /**
     *  Calling the setup function will allocate 
     *  memory for these and set up the params.
     *  Given the function returns a pointer, we 
     *  set these variables up as pointers to 
     *  Person.
     */
    struct Person *head = setup("First", "One", 3);
    struct Person *second = setup("Second", "Two", 2);
    struct Person *third = setup("Third", "Three", 1);
    
    head->next = second;
    second->next = third;
    third->next = NULL;
    
    return head;
}

struct Person* buildTwoThree() {
    struct Person *head = setup("Two", "Two", 2);
    struct Person *second = setup("Three", "Three", 3);
    
    head->next = second;
    second->next = NULL;
    
    return head;
}

void wrongPush(struct Person *head, char *_firstname, char *_lastname, int _age) {
    /**
     *  This is an example of how not to push a new node (Person)
     *  on to a linked list.
     *
     *  Here we create a pointer to a newPerson and point that to 
     *  some memory that has been allocated.
     *  
     *  We then set the properties for that new struct Person and 
     *  attempt to point the head that was passed in as an argument
     *  to this new person. 
     *
     *  This won't work because the *head param
     *  is copied and used in a local context here, so changing it 
     *  inside this function will not make a difference.
     */
    struct Person *newPerson = malloc(sizeof(struct Person));
    newPerson->firstname = _firstname;
    newPerson->lastname = _lastname;
    newPerson->age = _age;
    head = newPerson;
}

void push(struct Person **head_ref, char *_firstname, char *_lastname, int _age) {
    /**
     *  This is the correct way to push an item on to the list.
     *
     *  - we create a node (Person) by allocating some memory for it and pointing to that memory.
     *  - we then set the basic parameters for that Person.
     *  - we then dereference the head_ref parameter and set it as next for the Person.
     *  - we can then alter the head_ref parameter by dereferencing it and assigning it to the new Person.
     *
     *  This will push the new Person to the beginning of the list.
     */
    struct Person *newPerson = malloc(sizeof(struct Person));
    newPerson->firstname = _firstname;
    newPerson->lastname = _lastname;
    newPerson->age = _age;
    newPerson->next = *head_ref;
    *head_ref = newPerson;
}

void append(struct Person **head_ref, char *_firstname, char *_lastname, int _age) {
    struct Person *current = *head_ref;
    struct Person *newPerson = setup(_firstname, _lastname, _age);
    
    if(current == NULL) {
        *head_ref = newPerson;
    }
    else {
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newPerson;
    }
}

void changeToNull(struct Person **head_ref) {
    *head_ref = NULL;
}

struct Person* copyList(struct Person *head) {
    struct Person *current = head;
    struct Person *newPerson = NULL;
    struct Person *tail = NULL;
    
    while(current != NULL) {
        if(newPerson == NULL) {
            newPerson = setup(current->firstname, current->lastname, current->age);
            tail = newPerson;
        }
        else {
            tail->next = setup(current->firstname, current->lastname, current->age);
            tail = tail->next;
            tail->next = NULL;
        }
        current = current->next;
    }
    
    return newPerson;
}

int listSize(struct Person *head) {
    struct Person *current = head;
    int count = 0;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void printItems(struct Person *head) {
    struct Person *current = head;
    
    /**
     *  Using and alternative to a while loop to iterate through
     *  the elements of a linked list.
     */
    for(current = head; current != NULL; current = current->next) {
        printf("%s %s \t %i.\n", current->firstname, current->lastname, current->age);
    }
}

void paramaterModTest(int *a) {
    *a *= 2;
}
