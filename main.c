// <Adel Alkhamisy>
// <Adel.Alkhamisy@bison.howard.edu>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
    printf("Write your Tests for your linked list implementation\n");
    list_t *mylist = list_alloc(); // Allocate the list

    // Test Case Group 1: Basic List Creation and Printing
    printf("\n----Test Group 1: Basic List Creation and Printing----\n");
    printf("\n The List is empty now: \n");
    list_print(mylist); // Empty list

    list_add_to_front(mylist, 10);
    list_add_to_front(mylist, 20);
    list_add_to_front(mylist, 30);
    printf("\n The List has three elements now (30->20->10->NULL): \n");
    list_print(mylist); // List with 3 elements

    // ----Test Case Group 2: list_add_to_front ----
    printf("\n-----Test Group 2: list_add_to_front------\n");
    list_add_to_front(mylist, 40);
    list_add_to_front(mylist, 50);
    list_add_to_front(mylist, 60);
    list_add_to_front(mylist, 70);
    list_add_to_front(mylist, 80);
    list_add_to_front(mylist, 90);
    list_add_to_front(mylist, 100);
    printf("\n The List content now should be 100->90->80->70->60->50->40->30->20->10->NULL: \n");
    if (strcmp("100->90->80->70->60->50->40->30->20->10->NULL", listToString(mylist)) != 0) {
        printf("list_add_to_front : FAILED\n");
    }
    list_print(mylist);

    // -----Test Case Group 3: list_remove_at_index----
    printf("\n-----Test Group 3: list_remove_at_index-----\n");
    list_remove_at_index(mylist, 3);
    list_print(mylist);

    printf("\n The List content now should be 100->90->70->60->50->40->30->20->10->NULL: and the 80 at index 3 should be deleted: \n");
    if (strcmp("100->90->70->60->50->40->30->20->10->NULL", listToString(mylist)) != 0) {
        printf("list_remove_at_index : FAILED\n");
    }
    printf("\n remove at index 20 which is invalid index: \n");
    list_remove_at_index(mylist, 20); // Invalid index
    list_print(mylist);
    printf("\n remove at index 1 which is 100: \n");
    list_remove_at_index(mylist, 1);
    list_print(mylist);

    printf("\n remove at index 6: \n");
    list_remove_at_index(mylist, 6);
    list_print(mylist);

    if (strcmp("90->70->60->50->40->20->10->NULL", listToString(mylist)) != 0) {
        printf("list_remove_at_index : FAILED\n");
    }

    // --Test Case Group 4: list_length, list_add_to_back---
    printf("\n-----Test Group 4: list_length, list_add_to_back------\n");
    printf("The list length is %d\n", list_length(mylist));

    printf("\n add 39 to the back: \n");
    list_add_to_back(mylist, 39);
    list_print(mylist);

    printf("\n add 18 to the back: \n");
    list_add_to_back(mylist, 18);

    printf("\n add 42 to the back: \n");
    list_add_to_back(mylist, 42);

    printf("\n add 190 to the back: \n");
    list_add_to_back(mylist, 190);
    list_print(mylist);

    // ---Test Case Group 5: list_free and memory allocation------
    printf("\n---Test Group 5: list_free------\n");
    list_free(mylist);

    printf("\n allocate a new list now: \n");
    mylist = list_alloc(); // Allocate a new list after freeing

    printf("\n the list should be NULL now: \n");
    list_print(mylist);

    // ---Test Case Group 6: list_add_to_front, list_add_to_back, list_length----
    printf("\n---Test Group 6: list_add_to_front, list_add_to_back, list_length---\n");
    printf("\n add 81 to the front: \n");
    list_add_to_front(mylist, 81);
    printf("\n add 4 to the back: \n");
    list_add_to_back(mylist, 4);
    printf("\n add 308 to the front: \n");
    list_add_to_front(mylist, 308);
    printf("\n add 70 to the back: \n");
    list_add_to_back(mylist, 70);
    printf("\n add 290 to the front: \n");
    list_add_to_front(mylist, 290);
    list_print(mylist);
    printf("The list length is %d\n", list_length(mylist));

    // -Test Case Group 7: list_add_at_index
    printf("\n------Test Group 7: list_add_at_index-------\n");
    list_add_at_index(mylist, 21, 1);
    list_add_at_index(mylist, 65, 0);
    list_add_at_index(mylist, 10, 8);
    list_print(mylist);
    list_add_at_index(mylist, 10, 7);
    list_print(mylist);

    // Test Case Group 8: list_remove_from_back, list_remove_from_front, list_remove_at_index
    printf("\n-------Test Group 8: list_remove_from_back, list_remove_from_front, list_remove_at_index--------\n");
    list_remove_from_back(mylist);
    list_print(mylist);
    list_remove_from_front(mylist);
    list_print(mylist);
    list_remove_at_index(mylist, 3);
    list_print(mylist);

    // Test Case Group 9: list_is_in, list_get_elem_at, list_get_index_of
    printf("\n-Test Group 9: list_is_in, list_get_elem_at, list_get_index_of---\n");
    printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
    printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(mylist, 3));
    printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
    printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
    printf("Value at %d in the list?: %d\n", -2, list_get_elem_at(mylist, -2));
    printf("Value at %d in the list?: %d\n", 12, list_get_elem_at(mylist, 12));
    printf("Value at %d in the list?: %d\n", 7, list_get_elem_at(mylist, 7));
    printf("Index of %d?: %d\n", 70, list_get_index_of(mylist, 70));
    printf("Index of %d?: %d\n", 20, list_get_index_of(mylist, 20));
    printf("Index of %d?: %d\n", 0, list_get_index_of(mylist, 0));
    printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
    printf("Index of %d?: %d\n", 90, list_get_index_of(mylist, 90));
    printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));

    // --Test Case Group 10: list_free and edge cases
    printf("\n-------Test Group 10: list_free and edge cases--\n");
    list_free(mylist);
    mylist = list_alloc(); // Allocate a new list after freeing
    list_add_at_index(mylist, -1, -1); // Invalid index
    list_print(mylist);
    list_add_at_index(mylist, -1, -1); // Invalid index
    list_print(mylist);
    list_add_at_index(mylist, 10, 0);
    list_print(mylist);
    list_add_at_index(mylist, 20, 1);
    list_print(mylist);
    list_free(mylist);
    mylist = list_alloc(); // Allocate a new list after freeing
    printf("The list length is %d\n", list_length(mylist)); // Length of empty list
    list_print(mylist);

    // --Test Case Group 11: list_remove_from_*, list_add_to_*, list_add_at_index
    printf("\n---Test Group 11: list_remove_from_*, list_add_to_*, list_add_at_index---\n");
    list_remove_from_back(mylist); // Remove from empty
    list_remove_from_front(mylist); // Remove from empty
    list_remove_at_index(mylist, -3); // Invalid index
    list_remove_at_index(mylist, 0); // Remove from empty
    list_remove_at_index(mylist, 2); // Remove from empty
    list_add_to_front(mylist, 10);
    list_add_to_front(mylist, 20);
    list_add_to_front(mylist, 30);
    list_add_to_front(mylist, 40);
    list_add_to_front(mylist, 60);
    list_add_at_index(mylist, 50, 1);
    list_add_at_index(mylist, 0, 6);
    list_add_at_index(mylist, 70, 0);
    list_add_at_index(mylist, 80, 12); // Index out of bounds
    list_print(mylist);

    //Test Case Group 12: list_free, list_add_to_back, list_remove_from_front, list_remove_from_back
    printf("\n-----test Group 12: list_free, list_add_to_back, list_remove_from_front, list_remove_from_back----- \n");
    list_free(mylist);
    mylist = list_alloc(); // Allocate a new list after freeing
    list_add_to_back(mylist, 100);
    list_print(mylist);
    list_remove_from_front(mylist); // Remove the only element
    list_print(mylist);
    list_add_to_back(mylist, 13);
    list_print(mylist);
    list_remove_from_back(mylist); // Remove the only element
    list_print(mylist);

    // ---Test Case Group 13: list_add_to_front, list_remove_at_index
    printf("\n-------Test Group 13: list_add_to_front, list_remove_at_index-----------\n");
    list_add_to_front(mylist, 10);
    list_add_to_front(mylist, 20);
    list_add_to_front(mylist, 30);
    list_add_to_front(mylist, 40);
    list_add_to_front(mylist, 60);
    list_print(mylist);
    list_remove_at_index(mylist, 0); // Remove first element
    list_print(mylist);
    list_remove_at_index(mylist, -2); // Invalid index
    list_print(mylist);
    list_remove_at_index(mylist, 7);  // Index out of bounds
    list_print(mylist);
    list_remove_at_index(mylist, 4);
    list_print(mylist);

    // Test Case Group 14: list_free, list_remove_at_index, list_add_to_front
    printf("\n ------- test Group 14: list_free, list_remove_at_index, list_add_to_front----------\n");
    list_free(mylist);
    mylist = list_alloc(); // Allocate a new list after freeing
    list_print(mylist);
    list_remove_at_index(mylist, 0); // Remove from empty list
    list_print(mylist);
    list_add_to_front(mylist, 60);
    list_print(mylist);
    list_remove_at_index(mylist, 1);  // Index out of bounds
    list_print(mylist);
    list_add_to_front(mylist, 80);
    list_print(mylist);
    list_remove_at_index(mylist, 0);
    list_print(mylist);

    // Test Case Group 15: list_is_in, list_add_to_back
    printf("\n---Test Group 15: list_is_in, list_add_to_back------------\n");
    printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60)); // Check for element
    list_add_to_back(mylist, 50);
    list_add_to_back(mylist, 60);
    list_add_to_back(mylist, 70);
    list_add_to_back(mylist, 80);
    list_add_to_back(mylist, 90);
    list_print(mylist);
    printf("Is %d in the list?: %d\n", 30, list_is_in(mylist, 30)); // Check for absent element
    printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60)); // Check for element
    printf("Is %d in the list?: %d\n", 80, list_is_in(mylist, 80)); // Check for element
    list_add_to_back(mylist, 70);
    list_print(mylist);
    printf("Is %d in the list?: %d\n", 70, list_is_in(mylist, 70)); // Check for element

    // Test Case Group 16: list_length, list_get_elem_at ---
    printf("\n---Test Group 16: list_length, list_get_elem_at---------\n");
    printf("The list length is %d\n", list_length(mylist));
    printf("Value at %d in the list?: %d\n", -4, list_get_elem_at(mylist, -4)); // Invalid index
    printf("Value at %d in the list?: %d\n", 10, list_get_elem_at(mylist, 10));
    printf("Value at %d in the list?: %d\n", 6, list_get_elem_at(mylist, 6));
    printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
    printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));  // Invalid index
    list_free(mylist);
    mylist = list_alloc(); // Allocate a new list after freeing
    list_print(mylist);
    printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));  // Invalid list

    // Test Case Group 17: list_remove_at_index, list_is_in, list_get_index_of
    printf("\n---------Test Group 17: list_remove_at_index, list_is_in, list_get_index_of-----------\n");
    list_remove_at_index(mylist, 0); // Remove from empty
    printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21)); // Check in empty
    printf("Index of %d?: %d\n", 21, list_get_index_of(mylist, 21)); // Index in empty
    list_add_to_front(mylist, 10);
    list_add_to_front(mylist, 20);
    list_add_to_front(mylist, 30);
    list_add_to_front(mylist, 40);
    list_add_to_front(mylist, 50);
    list_print(mylist);
    printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
    printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81)); // Check absent
    printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
    printf("Index of %d?: %d\n", 30, list_get_index_of(mylist, 30));
    return 0;
}