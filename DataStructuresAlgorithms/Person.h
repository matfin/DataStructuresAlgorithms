//
//  Person.h
//  DataStructuresAlgorithms
//
//  Created by Matt Finucane on 17/01/2017.
//  Copyright © 2017 Matt Finucane. All rights reserved.
//

#ifndef Person_h
#define Person_h

struct Person {
    const char *firstname;
    const char *lastname;
    int age;
    struct Person *next;
};

#endif /* Person_h */
