/*
 * utils.h
 *
 *  Created on: 15-Jul-2018
 *  Author: Abhishek Mane <https://abhishek-mane.github.io>
 */

#ifndef LIB_UTILS_H_
#define LIB_UTILS_H_

typedef enum _bool {
	False = 0, True = 1
} Bool;

typedef struct _array {
	int *ptr;
	int length;
} Array;

typedef enum _direction {
	left = 0, right = 1, up = 2, down = 3
} Direction;

#endif /* LIB_UTILS_H_ */
