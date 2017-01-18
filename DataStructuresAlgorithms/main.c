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
    
    struct Person *current = head;
    while(current != NULL) {
        printf("Person: %s %s, %i.\n", current->firstname, current->lastname, current->age);
        current = current->next;
    }
    
    return 0;
}
