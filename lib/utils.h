//
// Created by abhishek on 12/7/18.
//

#ifndef DATA_STRUCTURES_UTILS_H
#define DATA_STRUCTURES_UTILS_H

typedef enum _bool {
    false = 0,
    true = 1
} Bool;

typedef enum _direction {
    left = 0,
    right = 1,
    head = 2,
    tail = 4,
    up = 5,
    down = 6
} Direction;

typedef struct _array {
    int *ptr;
    int length;
} Array;

#endif //DATA_STRUCTURES_UTILS_H
