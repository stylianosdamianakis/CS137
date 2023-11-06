#ifndef VLINTEGER_H
#define VLINTEGER_H

struct linteger {	// linteger is a structure with three elements
    int length;	// array is always full
    int *arr;	// pointer to integers (digits)
};

struct linteger *vlintegerCreate(void);

// free the memory
void vlintegerDestroy(struct linteger *v);

// reads digits of a very long integer and store them in t1.
void vlintegerRead(struct linteger *t1);

//prints the digits with no spaces in between ended by \n.
void vlintegerPrint(struct linteger *t1);

// returns the addition of t1 and t2. No leading zeros to the left should be kept in the array.
struct linteger * vlintegerAdd(struct linteger *t1, struct linteger *t2);

// returns the multiplication of t1 and t2. No leading zeros to the left should be kept in the array.
struct linteger * vlintegerMult(struct linteger *t1, struct linteger *t2);


#endif
