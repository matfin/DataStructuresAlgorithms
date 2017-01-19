//
//  main.c
//  DataStructuresAlgorithms
//
//  Created by Matt Finucane on 17/01/2017.
//  Copyright © 2017 Matt Finucane. All rights reserved.
//

#include "Person.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  Demonstrating using push() to add items to 
 *  the beginning of a linked list.
 */
int listPushDemo() {
    
    struct Person *head = setup("Head", "Item", 1);
    push(&head, "Second", "Pushed", 2);
    push(&head, "Third", "Pushed", 3);
    push(&head, "Fourth", "Pushed", 4);
    
    printf("The list now has %i items pushed.\n", listSize(head));
    printItems(head);
    printf("\n\n");
    
    push(&head, "Fifth", "Pushed", 5);
    push(&head, "Sixth", "Pushed", 6);
    push(&head, "Seventh", "Pushed", 7);
    
    printf("The list now has %i items pushed.\n", listSize(head));
    printItems(head);
    printf("\n\n");
    
    return 0;
}

/**
 *  Demonstrating using append() to add items 
 *  to the end of a linked list.
 */
int listAppendDemo() {
    
    struct Person *head = setup("Head", "Item", 1);
    append(&head, "Second", "Appended", 2);
    append(&head, "Third", "Appended", 3);
    append(&head, "Fourth", "Appended", 4);
    
    printf("The list now has %i items appended.\n", listSize(head));
    printItems(head);
    printf("\n\n");
    
    append(&head, "Fifth", "Appended", 5);
    append(&head, "Sixth", "Appended", 6);
    append(&head, "Seventh", "Appended", 7);
    
    printf("The list now has %i items.\n", listSize(head));
    printItems(head);
    printf("\n\n");
    
    return 0;
}

/**
 *  Demonstrating the listCopy() function to make a
 *  fresh copy of a linked list.
 */
int listCopyDemo() {
    
    struct Person *head = setup("Head", "Item", 1);
    append(&head, "Second", "Original", 2);
    append(&head, "Third", "Original", 2);
    append(&head, "Fourth", "Original", 2);
    append(&head, "Fifth", "Original", 2);
    
    printf("This is the original linked list with %i items.\n", listSize(head));
    printItems(head);
    printf("\n\n");
    
    struct Person *copy = copyList(head);
    printf("This is the copied linked list with %i items.\n", listSize(copy));
    printItems(copy);
    printf("\n\n");
    
    return 0;
}

int main(int argc, const char * argv[]) {

    int a = listPushDemo();
    int b = listAppendDemo();
    int c = listCopyDemo();
    
    return (a + b + c);
}
