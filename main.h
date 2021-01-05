#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
    void *element;
    struct node_t *prev;
    struct node_t *next;
} node_t;

typedef struct list_t {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

list_t *create_list();

int size(list_t *list);

bool is_empty(list_t *list);

node_t *first(list_t *list);

node_t *last(list_t *list);

node_t *before(list_t *list, node_t *p);

node_t *after(list_t *list, node_t *p);

node_t *insert_first(list_t *list, void *e);

node_t *insert_before(list_t *list, node_t *p, void *e);

node_t *insert_last(list_t *list, void *e);

node_t *insert_after(list_t *list, node_t *p, void *e);

void *remove_first(list_t *list);

void *remove_last(list_t *list);

void *remove_node(list_t *list, node_t *p);

void destroy_list(list_t *list);