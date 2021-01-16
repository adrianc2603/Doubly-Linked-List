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

/**
 * Helper function to create a heap-allocated integer and 
 * return a pointer to it
 */
int *create_element(int e) {
    int *p = malloc(sizeof(int));
    *p = e;
    return p;
}

void test_all_functions_regular_cases() {
    list_t *list = create_list();

    printf("Size of list is %d\n", size(list)); // Size of list is 0
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 1 (True)
    printf("The head of the list is %p\n", first(list)); // The head of the list is 0x0 (NULL)
    printf("The tail of the list is %p\n", last(list)); // The tail of the list is 0x0 (NULL)

    // Insert 4
    int *a = create_element(4);
    insert_first(list, a);
    print_list(list); // 4 - 
    node_t *node_a = get_node(list, a); 
    printf("Size of list is %d\n", size(list)); // Size of list is 1
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

    // Insert 6
    int *b = create_element(6);
    insert_first(list, b);
    print_list(list); // 6 - 4 -
    node_t *node_b = get_node(list, b); 
    printf("Size of list is %d\n", size(list)); // Size of list is 2
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

    // Insert 3
    int *c = create_element(3);
    insert_last(list, c);
    print_list(list); // 6 - 4 - 3 - 
    node_t *node_c = get_node(list, c); 
    printf("Size of list is %d\n", size(list)); // Size of list is 3
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

    // Insert 7
    int *d = create_element(7);
    insert_after(list, node_a, d);
    print_list(list); // 6 - 4 - 7 - 3 - 
    node_t *node_d = get_node(list, d); 
    printf("Size of list is %d\n", size(list)); // Size of list is 4
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

    // Insert 11
    int *e = create_element(11);
    insert_before(list, node_d, e);
    print_list(list); // 6 - 4 - 11 - 7 - 3 - 
    node_t *node_e = get_node(list, e); 
    printf("Size of list is %d\n", size(list)); // Size of list is 5
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

    // Insert 2
    int *f = create_element(2);
    insert_before(list, list->head, f);
    print_list(list); // 2 - 6 - 4 - 11 - 7 - 3 - 
    node_t *node_f = get_node(list, f); 
    printf("Size of list is %d\n", size(list)); // Size of list is 6
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

    // Insert 5
    int *g = create_element(5);;
    insert_after(list, list->tail, g);
    print_list(list); // 2 - 6 - 4 - 11 - 7 - 3 - 5 -
    node_t *node_g = get_node(list, g); 
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
    printf("Size of list is %d\n", size(list)); // Size of list is 7
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

    // Remove the first element (2)
    int *rem = remove_first(list);
    printf("Removed number is %d\n", *rem); // Removed number is 2
    print_list(list); // 6 - 4 - 11 - 7 - 3 - 5 -
    printf("Size of list is %d\n", size(list)); // Size of list is 6
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

    // Remove the last element (5)
    rem = remove_last(list);
    printf("Removed number is %d\n", *rem); // Removed number is 5
    print_list(list); // 6 - 4 - 11 - 7 - 3 -
    printf("Size of list is %d\n", size(list)); // Size of list is 5
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

    // Remove 11
    rem = remove_node(list, node_e);
    printf("Removed number is %d\n", *rem); // Removed number is 11
    print_list(list); // 6 - 4 - 7 - 3 -
    printf("Size of list is %d\n", size(list)); // Size of list is 4
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

    // Remove the tail (3)
    rem = remove_node(list, list->tail);
    printf("Removed number is %d\n", *rem); // Removed number is 3
    print_list(list); // 6 - 4 - 7 -
    printf("Size of list is %d\n", size(list)); // Size of list is 3
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

    // Remove the head (6)
    rem = remove_node(list, list->head);
    printf("Removed number is %d\n", *rem); // Removed number is 6
    print_list(list); // 4 - 7 -
    printf("Size of list is %d\n", size(list)); // Size of list is 2
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

    // Remove 7
    rem = remove_node(list, node_d);
    printf("Removed number is %d\n", *rem); // Removed number is 7
    print_list(list); // 4 -
    printf("Size of list is %d\n", size(list)); // Size of list is 1
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

    // Remove the last element (4)
    rem = remove_last(list);
    printf("Removed number is %d\n", *rem); // Removed number is 4
    print_list(list); // Prints nothing
    printf("Size of list is %d\n", size(list)); // Size of list is 0
    printf("Is this list empty? %d\n", is_empty(list)); // Is this list empty? 1 (True)
    printf("The head of the list is %p\n", first(list)); // The head of the list is 0x0 (NULL)
    printf("The tail of the list is %p\n", last(list)); // The tail of the list is 0x0 (NULL)

    // Insert 25
    int *h = create_element(25);
    insert_last(list, h);
    node_t *node_h = get_node(list, h); 
    print_list(list); // 25 -
    printf("Size of list is %d\n", size(list)); // Size of list is 1
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