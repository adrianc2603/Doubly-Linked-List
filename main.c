#include "main.h"


/**
 * Create linked list and set it's head and tail to NULL
 * Time Complexity: O(1)
 */
list_t *create_list() {
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

/**
 * Return the number of elements stored
 * Time Complexity: O(1)
 */ 
int size(list_t *list) {
    if (list == NULL) {
        return 0;
    }
    return list->size;
}

/**
 * Return whether or not the list is empty
 * Time Complexity: O(1)
 */
bool is_empty(list_t *list) {
    if (list == NULL) {
        return false;
    }
    return (list->size == 0);
}

/**
 * Return the position of the first element (NULL if empty)
 * Time Complexity: O(1)
 */ 
node_t *first(list_t *list) {
    if (list == NULL) {
        return NULL;
    }
    return list->head;
}

/**
 * Return the position of the last element (NULL if empty)
 * Time Complexity: O(1)
 */ 
node_t *last(list_t *list) {
    if (list == NULL) {
        return NULL;
    }
    return list->tail;
}

/**
 * Return the position immediately before p (NULL if p is first)
 * Time Complexity: O(1)
 */
node_t *before(list_t *list, node_t *p) {
    if (list == NULL || p == NULL || p == list->head) {
        return NULL;
    }
    return p->prev;
}

/**
 * Return the position immediately after p (NULL if p is last)
 * Time Complexity: O(1)
 */
node_t *after(list_t *list, node_t *p) {
    if (list == NULL || p == NULL || p == list->tail) {
        return NULL;
    }
    return p->next;
}

/**
 * Create new node with element e and set it as the head of the list. Return 
 * the position of the element
 * Time Complexity: O(1)
 */
node_t *insert_first(list_t *list, void *e) {
     if (list == NULL) {
        return NULL;
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->element = e;
    if (list->head != NULL) {
        list->head->prev = new_node;
    }
    new_node->next = list->head;
    new_node->prev = NULL;
    list->head = new_node;
    list->size++;
    if (list->size == 1) {
        list->tail = list->head;
    }
    return new_node;
}

/**
 * Insert e in front of the element at position p. Return the position
 * of the element. Note you cannot use this if the list is empty
 * Time Complexity: O(1)
 */
node_t *insert_before(list_t *list, node_t *p, void *e) {
    if (list == NULL || p == NULL) {
        return NULL;
    }

    // Insert before the current head
    if (list->head == p) {
        return insert_first(list, e);
    }

    // Create node, set its element to e, and add it before p
    node_t *new_node = malloc(sizeof(node_t));
    new_node->element = e;
    new_node->next = p;
    new_node->prev = p->prev;
    p->prev->next = new_node;
    p->prev = new_node;
    list->size++;
    return new_node;
}

/**
 * Create new node with element e and set it as the tail of the list. Return
 * the position of the element
 * Time Complexity: O(1)
 */
node_t *insert_last(list_t *list, void *e) {
     if (list == NULL) {
        return NULL;
    }
    if (list->size == 0) {
        return insert_first(list, e);
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->element = e;
    new_node->next = NULL;
    new_node->prev = list->tail;
    list->tail->next = new_node;
    list->tail = new_node;
    list->size++;
    return new_node;
}

/**
 * Insert e following the element at position p. Return the 
 * position of the element. Note you cannot use this if the list is empty
 * Time Complexity: O(1)
 */
node_t *insert_after(list_t *list, node_t *p, void *e) {
    if (list == NULL || p == NULL) {
        return NULL;
    }

    // Insert after the current tail
    if (list->tail == p) {
        return insert_last(list, e);
    }

    // Create node, set its element to e, and add it after p
    node_t *new_node = malloc(sizeof(node_t));
    new_node->element = e;
    new_node->prev = p;
    new_node->next = p->next;
    p->next->prev = new_node;
    p->next = new_node;
    list->size++;
    return new_node;
}

/**
 * Remove list->head and return its element. Return NULL if empty
 * Time Complexity: O(1)
 */
void *remove_first(list_t *list) {
    if (list == NULL || list->head == NULL) {
        return NULL;
    }

    // Remove the head
    node_t *rem_node = list->head;
    void *rem_element = rem_node->element;
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    }
    free(rem_node);
    list->size--;
    if (list->size == 0) {
        list->head = NULL;
        list->tail = NULL;
    }
    return rem_element;
}

/**
 * Remove list->tail and return its element. Return NULL if empty
 * Time Complexity: O(1)
 */
void *remove_last(list_t *list) {
    if (list == NULL || list->tail == NULL) {
        return NULL;
    }

    if (list->head == list->tail) {
        return remove_first(list);
    }

    // Remove the tail
    node_t *rem_node = list->tail;
    void *rem_element = rem_node->element;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(rem_node);
    list->size--;
    if (list->size == 0) {
        list->head = NULL;
        list->tail = NULL;
    }
    return rem_element;
}

/**
 * Remove and return the element at position p
 * Time Complexity: O(1)
 */
void *remove_node(list_t *list, node_t *p) {
    if (list == NULL || p == NULL || list->size == 0) {
        return NULL;
    }

    if (list->head == p) {
        return remove_first(list);
    }

    if (list->tail == p) {
        return remove_last(list);
    }

    // Remove current_node (p)
    void *rem_element = p->element;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    list->size--;
    if (list->size == 0) {
        list->head = NULL;
        list->tail = NULL;
    }
    return rem_element;
}

/**
 * Free all memory associated with the list
 * Time Complexity: O(n)
 */
void destroy_list(list_t *list) {
    node_t *next_node = NULL;
    node_t *current_node = list->head;
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(list);
}