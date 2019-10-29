#include <stdlib.h>
#include <stdio.h>

#include "sorted_set.h"

typedef struct _node_s * node_s;

struct _node_s {
    t_elem elem;
    node_s next;
};

typedef struct _sorted_set {
    node_s set;
} _sorted_set;

sorted_set create_sorted_set(){
    sorted_set s = (sorted_set)malloc(sizeof(struct _sorted_set));
    s->set = NULL;
    return (s);
}

void add(sorted_set s, t_elem e) {
    if (!contains(s,e)) {
        node_s new = (node_s)malloc(sizeof(struct _node_s));
        new->elem = e;
        if (s->set == NULL) {
            s->set = new;
            new->next = NULL;
        } else {
            if (e < first(s)) {
                new->next = s->set;
                s->set = new;
            } else {
                node_s previous = s->set;
                node_s current = s->set;
                while(current->elem < e && current->next != NULL) {
                    previous = current;
                    current = current->next;
                }
                if(e > current->elem) {
                    current->next = new;
                    new->next = NULL;
                } else {
                    previous->next = new;
                    new->next = current;
                }
            }
        }
    }
}

void rm(sorted_set s, t_elem e) {
    if (contains(s,e)) {
        node_s previous = s->set;
        node_s current = s->set;
        while (current->elem != e) {
            previous = current;
            current = current->next;
        }
        if(e == first(s)) {
            s->set = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

int size(sorted_set s) {
    int size_set = 0;
    if (!is_empty(s)) {
        node_s aux = s->set;
        while (aux != NULL) {
            size_set++;
            aux = aux->next;
        }
    }
    return (size_set);
}

bool is_empty(sorted_set s) {
    return (s->set == NULL);
}

bool contains(sorted_set s, t_elem e) {
    bool b = false;
    if (!is_empty(s)) {
        node_s aux = s->set;
        while ((aux != NULL) & !b) {
            if (aux->elem == e) {
                b = true;
            }
            aux = aux->next;
        }
    }
    return (b);
}

t_elem first(sorted_set s) {
    return (s->set->elem);
}

t_elem last(sorted_set s) {
    node_s aux;
    t_elem e;
    if(!is_empty(s)) {
        aux = s->set;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        e = aux->elem;
    }
    return (e);
}

void dump_sorted_set(sorted_set s) {
    node_s aux = s->set;
    while (aux != NULL) {
        fprintf(stdout, "%d ", aux->elem);
        aux = aux->next;
    }
    printf("\n");
}

void destroy_sorted_set(sorted_set s) {
    node_s aux = s->set;
    while (aux != NULL) {
        node_s tmp = aux->next;
        free(aux);
        aux = tmp;
    }
    free(s);
}

