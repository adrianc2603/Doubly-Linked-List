#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
 * Helper function to create a heap allocated int and return a pointer to it
 */
int *create_element(int e) {
    int *p = malloc(sizeof(int));
    *p = e;
    return p;
}

void test_all_functions_regular_cases() {
    list_t *list = create_list();

    assert(size(list) == 0);
    assert(is_empty(list) == true);
    assert(first(list) == NULL);
    assert(last(list) == NULL);

    // Insert 4
    int *a = create_element(4);
    insert_first(list, a);
    print_list(list); // 4 - 
    node_t *node_a = get_node(list, a);

    // Insert 6
    int *b = create_element(6);
    insert_first(list, b);
    print_list(list); // 6 - 4 - 
    node_t *node_b = get_node(list, b);

    // Insert 3
    int *c = create_element(3);
    insert_last(list, c);
    print_list(list); // 6 - 4 - 3 - 
    node_t *node_c = get_node(list, c);

    assert(size(list) == 3);
    assert(is_empty(list) == false);
    assert(*((int*) first(list)->element) == 6);
    assert(*((int*) last(list)->element) == 3);
    assert(before(list, node_c) == node_a);
    assert(after(list, node_b) == node_a);

    // Insert 7
    int *d = create_element(7);
    insert_after(list, node_a, d);
    print_list(list); // 6 - 4 - 7 - 3 - 
    node_t *node_d = get_node(list, d);

    // Insert 11
    int *e = create_element(11);
    insert_before(list, node_d, e);
    print_list(list); // 6 - 4 - 11 - 7 - 3 - 
    node_t *node_e = get_node(list, e);

    // Insert 2
    int *f = create_element(2);
    insert_before(list, list->head, f);
    print_list(list); // 2 - 6 - 4 - 11 - 7 - 3 - 
    node_t *node_f = get_node(list, f);

    // Insert 5
    int *g = create_element(5);
    insert_after(list, list->tail, g);
    print_list(list); // 2 - 6 - 4 - 11 - 7 - 3 - 5 -
    node_t *node_g = get_node(list, g);

    assert(before(list, node_e) == node_a);
    assert(after(list, node_c) == node_g);
    assert(size(list) == 7);
    assert(is_empty(list) == false);
    assert(*((int*) first(list)->element) == 2);
    assert(*((int*) last(list)->element) == 5);
    assert(before(list, node_f) == NULL);
    assert(after(list, node_g) == NULL);

    // Remove first in list
    int *rem = remove_first(list);
    assert(*rem == 2);
    print_list(list); // 6 - 4 - 11 - 7 - 3 - 5 -

    assert(size(list) == 6);
    assert(is_empty(list) == false);
    assert(*((int*) first(list)->element) == 6);
    assert(*((int*) last(list)->element) == 5);
    assert(before(list, node_b) == NULL);
    assert(after(list, node_b) == node_a);

    // Remove last from list
    rem = remove_last(list);
    assert(*rem == 5);
    print_list(list); // 6 - 4 - 11 - 7 - 3 -

    assert(size(list) == 5);
    assert(is_empty(list) == false);
    assert(*((int*) first(list)->element) == 6);
    assert(*((int*) last(list)->element) == 3);
    assert(before(list, node_c) == node_d);
    assert(after(list, node_c) == NULL);

    // Remove 11 
    rem = remove_node(list, node_e);
    assert(*rem == 11);
    print_list(list); // 6 - 4 - 7 - 3 -

    assert(size(list) == 4);
    assert(is_empty(list) == false);
    assert(*((int*) first(list)->element) == 6);
    assert(*((int*) last(list)->element) == 3);
    assert(before(list, node_d) == node_a);
    assert(after(list, node_a) == node_d);

    // Remove tail
    rem = remove_node(list, list->tail);
    assert(*rem == 3);
    print_list(list); // 6 - 4 - 7 -

    assert(size(list) == 3);
    assert(is_empty(list) == false);
    assert(*((int*) first(list)->element) == 6);
    assert(*((int*) last(list)->element) == 7);
    assert(before(list, node_d) == node_a);
    assert(after(list, node_d) == NULL);

    // Remove head
    rem = remove_node(list, list->head);
    assert(*rem == 6);
    print_list(list); // 4 - 7 -

    assert(size(list) == 2);
    assert(is_empty(list) == false);
    assert(*((int*) first(list)->element) == 4);
    assert(*((int*) last(list)->element) == 7);
    assert(before(list, node_a) == NULL);
    assert(after(list, node_a) == node_d);

    // Remove 7
    rem = remove_node(list, node_d);
    assert(*rem == 7);
    print_list(list); // 4 -

    assert(size(list) == 1);
    assert(is_empty(list) == false);
    assert(*((int*) first(list)->element) == 4);
    assert(*((int*) last(list)->element) == 4);
    assert(before(list, node_a) == NULL);
    assert(after(list, node_a) == NULL);

    // Remove last item in list
    rem = remove_last(list);
    assert(*rem == 4);
    print_list(list); // Prints nothing

    assert(size(list) == 0);
    assert(is_empty(list) == true);
    assert(first(list) == NULL);
    assert(last(list) == NULL);

    // Add 25 to list
    int *h = create_element(25);
    insert_last(list, h);
    node_t *node_h = get_node(list, h);
    print_list(list); // 25 -

    assert(size(list) == 1);
    assert(is_empty(list) == false);
    assert(*((int*) first(list)->element) == 25);
    assert(*((int*) last(list)->element) == 25);
    assert(before(list, node_h) == NULL);
    assert(after(list, node_h) == NULL);    

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