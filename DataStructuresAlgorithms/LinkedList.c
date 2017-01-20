//
//  LinkedList.c
//  DataStructuresAlgorithms
//
//  Created by Matt Finucane on 17/01/2017.
//  Copyright © 2017 Matt Finucane. All rights reserved.
//
#include <string.h>
#include <assert.h>
#include "LinkedList.h"

struct Person* setup(char *_firstname, char *_lastname, int _age) {
    /**
     *  Define a pointer to a Person struct
     *  and allocate some memory for it.
     */
    struct Person *p = NULL;
    p = malloc(sizeof(struct Person));
    assert(p != NULL);
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

void shift(struct Person **head_ref) {
    struct Person *current = *head_ref;
    struct Person *tmp = *head_ref;
    if(current != NULL) {
        current = current->next;
        *head_ref = current;
    }
}

void pop(struct Person **head_ref) {
    
    struct Person *tmp = NULL;
    
    if(*head_ref != NULL && (*head_ref)->next == NULL) {
        (*head_ref) = NULL;
        free(*head_ref);
    }
    
    for(struct Person *p = *head_ref; p != NULL; p = p->next) {
        if(p->next != NULL && p->next->next == NULL) {

            tmp = p;
        }
    }
    
    if(tmp != NULL) {
        tmp->next = NULL;
        free(tmp->next);
    }
}

void changeToNull(struct Person **head_ref) {
    *head_ref = NULL;
}

struct Person* copyList(struct Person *head) {
    /**
     *  Create a copy of the head pointer and 
     *  assign it to a new pointer *current.
     */
    struct Person *current = head;
    /**
     *  Teeing up a pointer to a *newPerson with
     *  an initial value of NULL.
     */
    struct Person *newPerson = NULL;
    /**
     *  Doing the same thing for the *tail pointer.
     */
    struct Person *tail = NULL;
    
    /**
     *  Iterate through the current pointer and keep 
     *  going through it...
     *
     *  Since *current is a copy of the *head pointer,
     *  we can loop through it without affecting the 
     *  *head pointer passed in.
     *  
     *  In this while loop, current will be set to 
     *  current->next each time.
     */
    while(current != NULL) {
        /**
         *  If the *newPerson is null, we use the setup() function defined
         *  above to allocate memory for it and assign it values. This will 
         *  tee up the first Person in the list.
         */
        if(newPerson == NULL) {
            newPerson = setup(current->firstname, current->lastname, current->age);
            /**
             *  We then point the *tail pointer to the same location as *newPerson.
             *  This means that we can track what goes into *tail via *newPerson.
             */
            tail = newPerson;
        }
        else {
            /**
             *  If *newPerson is not null, this means that it is not the 
             *  first item in the list.
             *
             *  We use the setup() function defined above to allocate
             *  memory and set the properties for the 'next' pointer
             *  of the tail. We then advance the tail pointer and set that
             *  objects next property to null.
             */
            tail->next = setup(current->firstname, current->lastname, current->age);
            tail = tail->next;
            tail->next = NULL;
        }
        /**
         *  We then need to advance current to its next pointer via its
         *  next property.
         */
        current = current->next;
    }
    
    /**
     *  We then return a pointer to newPerson, which is pointing to the 
     *  same location as the tail pointer we initialised as above. 
     *
     *  We now have a new linked list of items copied from the original
     *  head linked list with completely separate data coming from a 
     *  different memory location.
     */
    return newPerson;
}

struct Person* find(struct Person *list, const char *name) {
    
    /**
     *  Set up a pointer to current which we will use for iteration.
     */
    struct Person *current;
    
    /**
     *  Iterate, advancing the *current pointer until it is null
     *  by using ->next each time.
     */
    for(current = list; current != NULL; current = current->next) {
        
        /**
         *  Declare a new string and allocate memory for it based on
         *  - the string length of the Person->firstname
         *  - the string length of the Person->lastname
         *  - 2 bytes for the space between the names and the null terminator '\0'
         */
        char *fullname = malloc(strlen(current->firstname) + strlen(current->lastname) + 2);
        
        /**
         *  Copy the Person->firstname into the fullname string and 
         *  then concatenate the space and Person->lastname.
         */
        strcpy(fullname, current->firstname);
        strcat(fullname, " ");
        strcat(fullname, current->lastname);
        
        /**
         *  Call the strcmp function to compare the two strings.
         *  This will return an int 0 for a match or another int 
         *  when there is a difference.
         *
         *  We then free the memory occupied by the fullname* char
         *  since we no longer need it.
         */
        int found = strcmp(name, fullname);
        free(fullname);
        
        /**
         *  If found we return a pointer to current.
         */
        if(found == 0) {
            return current;
        }
    }
    
    /**
     *  Or we return null.
     */
    return NULL;
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
