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

int main(int argc, const char * argv[]) {

    struct Person *head = setup("Head", "Person", 1);
    push(&head, "Second", "Person", 2);
    push(&head, "Third", "Person", 3);
    push(&head, "Fourth", "Person", 4);
    
    printItems(head);
    
    struct Person *empty_head = NULL;
    push(&empty_head, "One", "Empty", 1);
    push(&empty_head, "Two", "Empty", 2);
    
    printItems(empty_head);
    
    struct Person *first_null = setup("Item", "One", 1);
    struct Person *second_null = setup("Second", "Item", 2);
    
    changeToNull(&first_null);
    changeToNull(&second_null);
    
    struct Person *append_head = setup("Tail", "Head", 1);
    append(&append_head, "Tail", "Added", 2);
    append(&append_head, "Added", "Tailagain", 3);
    append(&append_head, "Atthe", "Tailend", 4);
    
    printItems(append_head);
    
    struct Person *copied = copyList(append_head);
    
    return 0;
}
