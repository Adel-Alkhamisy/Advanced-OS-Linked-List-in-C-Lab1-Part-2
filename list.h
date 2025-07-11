// list/list.h
// 
// Interface definition for linked list.
//
// <Adel Alkhamisy>
// <Adel.Alkhamisy@bison.howard.edu>

#include <stdbool.h>

/* Defines the type of the elements in the linked list. You may change this if
 * you want! */
typedef int elem;

/* Defines the node structure. Each node contains its element, and points to the
 * next node in the list. The last element in the list should have NULL as its
 * next pointer. */
struct node {
	elem value;
	struct node *next;
};
typedef struct node node_t;

/* Defines the list structure, which simply points to the first node in the
 * list. */
struct list {
	node_t *head;
};
typedef struct list list_t;

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
list_t *list_alloc();
void list_free(list_t *l);

/* Prints the list in some format. */
void list_print(list_t *l);

/* returns string of List */
char* listToString(list_t *l);

/* Returns the length of the list. */
int list_length(list_t *l);

/* Methods for adding to the list. */
void list_add_to_back(list_t *l, elem value);
void list_add_to_front(list_t *l, elem value);
void list_add_at_index(list_t *l, elem value, int index);

/* Methods for removing from the list. Returns the removed element. */
elem list_remove_from_back(list_t *l);
elem list_remove_from_front(list_t *l);
elem list_remove_at_index(list_t *l, int index);

/* Checks to see if the given element exists in the list. */
int list_is_in(list_t *l, elem value);

/* Returns the element at the given index. Starting index is 1.  Return -1 error */
elem list_get_elem_at(list_t *l, int index);

/* Returns the index at which the given element appears. return -1 if does not exist */
int list_get_index_of(list_t *l, elem value);
