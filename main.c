#include <stdio.h>
#include <assert.h>

#include "sorted_set.h"

int main() {
    sorted_set s = create_sorted_set();
    assert(is_empty(s)); 
    t_elem e = 0;
    add(s,e);
    e = 2;
    add(s,e);
    e = 1;
    add(s,e);
    dump_sorted_set(s);
    rm(s, 0);
    dump_sorted_set(s);
    destroy_sorted_set(s);
    return (0);
}
