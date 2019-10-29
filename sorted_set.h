#ifndef _SORTED_SET_H
#define _SORTED_SET_H

#include <stdbool.h>

/* 
 * sorted_set represents a sorted set. 
 * The elements in a sorted_set can be sorted in a natural order
 *
 * sorted_set as pointers to structs to guarantee encapsulation
*/

typedef int t_elem;

typedef struct _sorted_set * sorted_set;

sorted_set create_sorted_set();
/*
    Creates a new sorted_set.
*/

void add(sorted_set s, t_elem e);
/*	
    Adds the specified element e to this set if it is not already present
*/

void rm(sorted_set s, t_elem e);
/*
    Removes the specified element e from this set if it is present 
*/

int size(sorted_set s);
/*
    Returns the number of elements in this set
*/

bool is_empty(sorted_set s);
/*
    Returns true if this set contains no elements.
*/

bool contains(sorted_set s, t_elem e);
/*
    Returns true if this set contains the specified element e.
*/

t_elem first(sorted_set s);
/*
    Returns the first (lowest) element currently in this set.
*/

t_elem last(sorted_set s);
/*
    Returns the last (highest) element currently in this set.

*/

void dump_sorted_set(sorted_set s);
/*
    Write the elements of this set into stdout.
*/

void destroy_sorted_set(sorted_set s);
/*
    Frees the dynamic memory used by the sorted_set.
*/

#endif

