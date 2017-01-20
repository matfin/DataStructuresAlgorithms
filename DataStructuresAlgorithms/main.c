//
//  main.c
//  DataStructuresAlgorithms
//
//  Created by Matt Finucane on 17/01/2017.
//  Copyright © 2017 Matt Finucane. All rights reserved.
//

#include "Person.h"
#include "LinkedList.h"
#include "FunctionPointerDemo.h"
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
    
    head = NULL;
    free(head);
    
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
    
    head = NULL;
    free(head);
    
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
    
    head = NULL;
    copy = NULL;
    free(head);
    free(copy);
    
    return 0;
}

/**
 *  Demonstrating using find() inside a linked list to 
 *  search for a Person by name.
 */
int findDemo(const char *term) {
    
    struct Person *list = setup("Find", "Else", 1);
    append(&list, "Someones", "Name", 2);
    append(&list, "Matt", "Finucane", 34);
    append(&list, "Anna", "Christoffer", 31);
    append(&list, "Another", "Person", 3);
    append(&list, "And", "Again", 4);
    
    struct Person *found = find(list, term);
    
    if(found != NULL) {
        printf("Found %s %s, %i with the term \"%s\".\n", found->firstname, found->lastname, found->age, term);
    }
    else {
        printf("Could not find a result with term: \"%s\".\n", term);
    }
    
    list = NULL;
    found = NULL;
    free(list);
    free(found);
    
    return 0;
}

int shiftDemo() {
    
    struct Person *head = setup("First", "Person", 1);
    append(&head, "Second", "Person", 2);
    append(&head, "Third", "Person", 3);
    append(&head, "Fourth", "Person", 4);
    append(&head, "Fifth", "Person", 5);
    append(&head, "Sixth", "Person", 6);
    
    printf("List in this current state before shift() has %i items.\n", listSize(head));
    printItems(head);
    
    shift(&head);
    printf("Shifting an item from the start yields %i items.\n", listSize(head));
    printItems(head);
    
    shift(&head);
    shift(&head);
    shift(&head);
    printf("Shifting more items from the start yields %i items.\n", listSize(head));
    printItems(head);
    
    shift(&head);
    shift(&head);
    shift(&head);
    shift(&head);

    head = NULL;
    free(head);
    
    return 0;
}

int popDemo() {
    struct Person *head = setup("First", "Pop", 1);
    append(&head, "Second", "Pop", 2);
    append(&head, "Third", "Pop", 3);
    append(&head, "Fourth", "Pop", 4);
    append(&head, "Fifth", "Pop", 5);
    append(&head, "Sixth", "Pop", 6);
    
    printf("List in this current state before pop() has %i items.\n", listSize(head));
    printItems(head);
    
    pop(&head);
    printf("Popping items from the end yields %i items.\n", listSize(head));
    printItems(head);
    
    pop(&head);
    pop(&head);
    printf("Popping more items from the end yields %i items.\n", listSize(head));
    printItems(head);
    
    head = NULL;
    free(head);
    
    return 0;
}

void pointerIncrementDemo() {
    
    /**
     *  Declare a linked list of four items.
     */
    struct Person *root = setup("Inc", "One", 1);
    append(&root, "Inc", "Two", 2);
    append(&root, "Inc", "Three", 3);
    append(&root, "Inc", "Four", 4);
    
    /**
     *  Declare a new pointer *current which
     *  will be set to the *root pointer.
     */
    struct Person *current = root;
    
    /**
     *  *current is now pointing to the same location as *root.
     */
    printf("Person: %s %s, %i.\n", current->firstname, current->lastname, current->age);
    
    /**
     *  Increment *current to get the next item.
     *  Note: doing this using pointer incrmeents is not recommended as it can cause crashes.
     */
    current++;
    printf("Incremented: %s %s, %i.\n", current->firstname, current->lastname, current->age);

    /**
     *  Same as above.
     */
    current++;
    printf("Incremented again: %s %s, %i.\n", current->firstname, current->lastname, current->age);
    
    /**
     *  Cleanup.
     */
    root = NULL;
    current = NULL;
    free(root);
    free(current);
}

void pointerNextDemo() {
    
    /**
     *  Declare a linked list of four items.
     */
    struct Person *root = setup("Inc", "One", 1);
    append(&root, "Inc", "Two", 2);
    append(&root, "Inc", "Three", 3);
    append(&root, "Inc", "Four", 4);
    
    /**
     *  Declare a new pointer *current which 
     *  will be set to the *root pointer.
     */
    struct Person *current = root;
    
    /**
     *  *current is now pointing to the same location as *root.
     */
    printf("Person: %s %s, %i.\n", current->firstname, current->lastname, current->age);
    
    /**
     *  Advance the current pointer by using current->next...
     */
    current = current->next;
    printf("Next: %s %s, %i.\n", current->firstname, current->lastname, current->age);
    
    /**
     *  Same as above.
     */
    current = current->next;
    printf("Next again: %s %s, %i.\n", current->firstname, current->lastname, current->age);
    
    /**
     *  Cleanup
     */
    root = NULL;
    current = NULL;
    free(root);
    free(current);
}

void pointer_indirection_demo() {
    int va = 3;
    int *ptr_va = &va;
    int **ptr_ptr_va = &ptr_va;
    int ***ptr_ptr_ptr_va = &ptr_ptr_va;
    int ****ptr_ptr_ptr_ptr_va = &ptr_ptr_ptr_va;
    
    ptr_va = NULL;
    ptr_ptr_va = NULL;
    ptr_ptr_ptr_va = NULL;
    ptr_ptr_ptr_ptr_va = NULL;
    free(ptr_va);
    free(ptr_ptr_va);
    free(ptr_ptr_ptr_va);
    free(ptr_ptr_ptr_ptr_va);
}

int main(int argc, const char * argv[]) {
    
    int a = listPushDemo();
    int b = listAppendDemo();
    int c = listCopyDemo();
    int d = findDemo("Not Found");
    int e = findDemo("Matt Finucane");
    int f = shiftDemo();
    int g = popDemo();
    

    int h = function_pointer_demo_main(10);
    int i = function_pointer_demo_main(-2);
    printf("a: %i, b: %i.\n", a, b);
    
    function_pointer_arguments_demo();
    
    /**
     *  This works
     */
    for(int i = 0; i < 10; i++) {
        printf("================== Next (%i) =====================\n", i);
        pointerNextDemo();
    }
    
    /**
     *  And this is likely to crash.
     */
    for(int i = 0; i < 10; i++) {
        printf("================= Increment (%i) =================\n", i);
        pointerIncrementDemo();
    }
    
    pointer_indirection_demo();
    
    return (a + b + c + d + e + f + g + h + i);
}
