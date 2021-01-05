#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * Helper function that prints each element in the linked list. Note that it 
 * was written to deal with linked lists where the elements are of type int*
 */
void print_list(list_t *list) {
    printf("\n");

    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }

    node_t *current_node = list->head;
    while (current_node != NULL) {
        int *address = (int*) current_node->element;
        printf("%d - ", *address);
        current_node = current_node->next;
    }

    printf("\n\n");
}

void test_all_functions_regular_cases() {
    list_t *list = create_list();

    printf("Size of list is %d\n", list->size); // Size of list is 0
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 1 (True)
    printf("The head of the list is %p\n", first(list)); // The head of the list is 0x0 (NULL)
    printf("The tail of the list is %p\n", last(list)); // The tail of the list is 0x0 (NULL)

    int *a = malloc(sizeof(int));
    *a = 4;
    node_t *node_a = insert_first(list, a);
    print_list(list); // 4 - 

    printf("Size of list is %d\n", list->size); // Size of list is 1
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 0 (False)
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 4
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 4

    if (before(list, node_a) == NULL) {
        printf("The node before node_a is NULL because node_a is the head\n"); // This should print
    }
    else {
        printf("The node before node_a is not NULL, but it should be");
    }

    if (after(list, node_a) == NULL) {
        printf("The node after node_a is NULL because node_a is the tail\n"); // This should print
    }
    else {
        printf("The node after node_a is not NULL, but it should be");
    }

    int *b = malloc(sizeof(int));
    *b = 6;
    node_t *node_b = insert_first(list, b);
    print_list(list); // 6 - 4 -

    printf("Size of list is %d\n", list->size); // Size of list is 2
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 6
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 4

    if (before(list, node_b) == NULL) {
        printf("The node before node_b is NULL because node_b is the head\n"); // This should print
    }
    else {
        printf("The node before node_a is not NULL, but it should be");
    }

    if (after(list, node_a) == NULL) {
        printf("The node after node_a is NULL because node_a is the tail\n"); // This should print
    }
    else {
        printf("The node after node_a is not NULL, but it should be");
    } 

    if (before(list, node_a) == node_b) {
        printf("The node before node_a is node_b\n"); // This should print
    }
    else {
        printf("The node before node_a is not node_b, but it should be");
    }

    if (after(list, node_b) == node_a) {
        printf("The node after node_b is node_a\n"); // This should print
    }
    else {
        printf("The node after node_b is not node_a, but it should be");
    } 

    int *c = malloc(sizeof(int));
    *c = 3;
    node_t *node_c = insert_last(list, c);
    print_list(list); // 6 - 4 - 3 - 

    printf("Size of list is %d\n", list->size); // Size of list is 3
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 0 (False)
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 6
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 3

    if (before(list, node_c) == node_a) {
        printf("The node before node_c is node_a\n"); // This should print
    }
    else {
        printf("The node before node_c is not node_a, but it should be");
    }

    if (after(list, node_b) == node_a) {
        printf("The node after node_b is node_a\n"); // This should print
    }
    else {
        printf("The node after node_b is not node_a, but it should be");
    }

    int *d = malloc(sizeof(int));
    *d = 7;
    node_t *node_d = insert_after(list, node_a, d);
    print_list(list); // 6 - 4 - 7 - 3 - 

    printf("Size of list is %d\n", list->size); // Size of list is 4
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 0 (False)
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 6
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 3

    if (before(list, node_d) == node_a) {
        printf("The node before node_d is node_a\n"); // This should print
    }
    else {
        printf("The node before node_d is not node_a, but it should be");
    }

    if (after(list, node_a) == node_d) {
        printf("The node after node_a is node_d\n"); // This should print
    }
    else {
        printf("The node after node_a is not node_d, but it should be");
    }

    if (before(list, node_c) == node_d) {
        printf("The node before node_c is node_d\n"); // This should print
    }
    else {
        printf("The node before node_c is not node_d, but it should be");
    }

    if (after(list, node_d) == node_c) {
        printf("The node after node_d is node_c\n"); // This should print
    }
    else {
        printf("The node after node_d is not node_c, but it should be");
    }

    int *e = malloc(sizeof(int));
    *e = 11;
    node_t *node_e = insert_before(list, node_d, e);
    print_list(list); // 6 - 4 - 11 - 7 - 3 - 

    printf("Size of list is %d\n", list->size); // Size of list is 5
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 0 (False)
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 6
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 3

    if (before(list, node_e) == node_a) {
        printf("The node before node_e is node_a\n"); // This should print
    }
    else {
        printf("The node before node_e is not node_a, but it should be");
    }

    if (after(list, node_a) == node_e) {
        printf("The node after node_a is node_e\n"); // This should print
    }
    else {
        printf("The node after node_a is not node_e, but it should be");
    }

    if (before(list, node_d) == node_e) {
        printf("The node before node_d is node_e\n"); // This should print
    }
    else {
        printf("The node before node_d is not node_e, but it should be");
    }

    if (after(list, node_e) == node_d) {
        printf("The node after node_e is node_d\n"); // This should print
    }
    else {
        printf("The node after node_e is not node_d, but it should be");
    }

    int *f = malloc(sizeof(int));
    *f = 2;
    node_t *node_f = insert_before(list, list->head, f);
    print_list(list); // 2 - 6 - 4 - 11 - 7 - 3 - 

    printf("Size of list is %d\n", list->size); // Size of list is 6
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 0 (False)
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 2
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 3

    if (before(list, node_b) == node_f) {
        printf("The node before node_b is node_f\n"); // This should print
    }
    else {
        printf("The node before node_b is not node_f, but it should be");
    }

    if (after(list, node_f) == node_b) {
        printf("The node after node_f is node_b\n"); // This should print
    }
    else {
        printf("The node after node_f is not node_b, but it should be");
    }

    if (before(list, node_f) == NULL) {
        printf("The node before node_f is NULL as node_f is the head\n"); // This should print
    }
    else {
        printf("The node before node_f is not NULL, but it should be");
    }

    int *g = malloc(sizeof(int));
    *g = 5;
    node_t *node_g = insert_after(list, list->tail, g);
    print_list(list); // 2 - 6 - 4 - 11 - 7 - 3 - 5 -

    if (before(list, node_g) == node_c) {
        printf("The node before node_g is node_c\n"); // This should print
    }
    else {
        printf("The node before node_g is not node_c, but it should be");
    }
    
    if (after(list, node_c) == node_g) {
        printf("The node after node_c is node_g\n"); // This should print
    }
    else {
        printf("The node after node_c is not node_g, but it should be");
    }

    printf("Size of list is %d\n", list->size); // Size of list is 7
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 0 (False)
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 2
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 5

    if (before(list, node_f) == NULL) {
        printf("The node before node_f is NULL because node_f is the head\n"); // This should print
    }
    else {
        printf("The node before node_f is not NULL, but it should be");
    }

    if (after(list, node_g) == NULL) {
        printf("The node after node_g is NULL because node_g is the tail\n"); // This should print
    }
    else {
        printf("The node after node_g is not NULL, but it should be");
    }

    int *rem = remove_first(list);
    printf("Removed number is %d\n", *rem); // Removed number is 2
    print_list(list); // 6 - 4 - 11 - 7 - 3 - 5 -
    printf("Size of list is %d\n", list->size); // Size of list is 6
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 6
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 5

    if (before(list, node_b) == NULL) {
        printf("The node before node_b is NULL because node_b is the head\n"); // This should print
    }
    else {
        printf("The node before node_b is not NULL, but it should be");
    }

    if (after(list, node_b) == node_a) {
        printf("The node after node_b is node_a\n"); // This should print
    }
    else {
        printf("The node after node_g is not node_a but it should be");
    }

    rem = remove_last(list);
    printf("Removed number is %d\n", *rem); // Removed number is 5
    print_list(list); // 6 - 4 - 11 - 7 - 3 -
    printf("Size of list is %d\n", list->size); // Size of list is 5
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 6
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 3

    if (before(list, node_c) == node_d) {
        printf("The node before node_c is node_d \n"); // This should print
    }
    else {
        printf("The node before node_c is not node_d, but it should be");
    }

    if (after(list, node_c) == NULL) {
        printf("The node after node_c is NULL because node_c is the tail\n"); // This should print
    }
    else {
        printf("The node after node_c is not NULL, but it should be");
    }

    rem = remove_node(list, node_e);
    printf("Removed number is %d\n", *rem); // Removed number is 11
    print_list(list); // 6 - 4 - 7 - 3 -
    printf("Size of list is %d\n", list->size); // Size of list is 4
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 6
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 3

    if (before(list, node_d) == node_a) {
        printf("The node before node_d is node_a\n"); // This should print
    }
    else {
        printf("The node before node_d is not node_a, but it should be");
    }
    
    if (after(list, node_a) == node_d) {
        printf("The node after node_a is node_d\n"); // This should print
    }
    else {
        printf("The node after node_a is not node_d, but it should be");
    }

    rem = remove_node(list, list->tail);
    printf("Removed number is %d\n", *rem); // Removed number is 3
    print_list(list); // 6 - 4 - 7 -
    printf("Size of list is %d\n", list->size); // Size of list is 3
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 6
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 7

    if (before(list, node_d) == node_a) {
        printf("The node before node_d is node_a \n"); // This should print
    }
    else {
        printf("The node before node_d is not node_a, but it should be");
    }

    if (after(list, node_d) == NULL) {
        printf("The node after node_d is NULL because node_d is the tail\n"); // This should print
    }
    else {
        printf("The node after node_d is not NULL, but it should be");
    }

    rem = remove_node(list, list->head);
    printf("Removed number is %d\n", *rem); // Removed number is 6
    print_list(list); // 4 - 7 -
    printf("Size of list is %d\n", list->size); // Size of list is 2
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 4
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 7

    if (before(list, node_a) == NULL) {
        printf("The node before node_a is NULL because node_a is the head\n"); // This should print
    }
    else {
        printf("The node before node_a is not NULL, but it should be");
    }

    if (after(list, node_a) == node_d) {
        printf("The node after node_a is node_d\n"); // This should print
    }
    else {
        printf("The node after node_a is not node_d but it should be");
    }

    if (after(list, node_d) == NULL) {
        printf("The node after node_d is NULL because node_d is the tail\n"); // This should print
    }
    else {
        printf("The node after node_d is not NULL, but it should be");
    }

    rem = remove_node(list, node_d);
    printf("Removed number is %d\n", *rem); // Removed number is 7
    print_list(list); // 4 -
    printf("Size of list is %d\n", list->size); // Size of list is 1
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 0 (False)
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 4
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 4

    if (before(list, node_a) == NULL) {
        printf("The node before node_a is NULL because node_a is the head\n"); // This should print
    }
    else {
        printf("The node before node_a is not NULL, but it should be");
    }

    if (after(list, node_a) == NULL) {
        printf("The node after node_a is NULL because node_a is the tail\n"); // This should print
    }
    else {
        printf("The node after node_a is not NULL, but it should be");
    }

    rem = remove_node(list, node_a);
    printf("Removed number is %d\n", *rem); // Removed number is 4
    print_list(list); // Prints nothing
    printf("Size of list is %d\n", list->size); // Size of list is 0
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 1 (True)
    printf("The head of the list is %p\n", first(list)); // The head of the list is 0x0 (NULL)
    printf("The tail of the list is %p\n", last(list)); // The tail of the list is 0x0 (NULL)

    int *h = malloc(sizeof(int));
    *h = 25;
    node_t *node_h = insert_last(list, h);

    print_list(list); // 25 -
    printf("Size of list is %d\n", list->size); // Size of list is 1
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 0 (False)
    printf("The head of the list is %d\n", *((int*) first(list)->element)); // The head of the list is 25
    printf("The tail of the list is %d\n", *((int*) last(list)->element)); // The tail of the list is 25

    if (before(list, node_h) == NULL) {
        printf("The node before node_h is NULL because node_h is the head\n"); // This should print
    }
    else {
        printf("The node before node_h is not NULL, but it should be");
    }

    if (after(list, node_h) == NULL) {
        printf("The node after node_h is NULL because node_h is the tail\n"); // This should print
    }
    else {
        printf("The node after node_h is not NULL, but it should be");
    }

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);
    free(g);
    free(h);
    destroy_list(list);
}

int main() {

    test_all_functions_regular_cases();

    return 0;
}