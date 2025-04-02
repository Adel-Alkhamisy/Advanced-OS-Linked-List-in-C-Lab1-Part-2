// list/list.c
// 
// Implementation for linked list.
//
// <Adel Alkhamisy>
// <Adel.Alkhamisy@bison.howard.edu>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Include for bool type

#include "list.h"

// Allocate memory for the list using malloc function.
// make the head point to NULL as the list starts empty.
list_t *list_alloc() { 
  list_t* mylist = (list_t *) malloc(sizeof(list_t)); 
  // Check if malloc succeeded
  if (mylist == NULL) {
      // Handle allocation failure (e.g. print error, return NULL)
      perror("Failed to allocate list");
      return NULL; 
  }
  mylist->head = NULL;
  return mylist;
}

//Free the memory allocated for the list and all its nodes
void list_free(list_t *l) {
  // It's safe to free a NULL pointer (does nothing), but checking improves clarity.
  if (l == NULL) return; 
  
  node_t* current = l->head;
  node_t* next;
  
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  
  //Crucially, free the list structure itself!
  free(l); 
}

// Print the list in a readable format
void list_print(list_t *l) {
  printf("List: "); 
  if (l == NULL) {
    printf("<NULL List Pointer>\n"); // Indicate if the list pointer itself is NULL
    return;
  }
  
  node_t* current = l->head;
    
  if (current == NULL) {
    printf("NULL\n"); // Empty list
    return;
  }
  
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  
  printf("NULL\n"); // Terminate the output line
}

// Convert list to string
char * listToString(list_t *l) {
  if (l == NULL) { // Handle NULL list pointer
      // Return a representation or NULL
      char* null_str = malloc(1); // Allocate space for null terminator
      if (null_str) null_str[0] = '\0';
      return null_str; // Return empty string for NULL list pointer
  }

  // Estimate buffer size
  // Start with a reasonable size
  size_t buf_size = 100; // Initial size
  char* buf = (char *) malloc(buf_size);
  if (!buf) return NULL; // Malloc check

  buf[0] = '\0'; // Initialize empty string
  char tbuf[25]; // Buffer for converting one integer
  size_t current_len = 0;

  node_t* curr = l->head;
  while (curr != NULL) {
    int written = snprintf(tbuf, sizeof(tbuf), "%d->", curr->value); 
    if (written < 0) { // Handle snprintf error
        free(buf);
        return NULL;
    }

    // Check if buffer needs resizing
    if (current_len + written + 5 >= buf_size) { // +5 for "NULL" and terminator
        buf_size = buf_size * 2 + written + 5; // Double size + needed space
        char* temp = realloc(buf, buf_size);
        if (!temp) {
            free(buf);
            return NULL; // Realloc failed
        }
        buf = temp;
    }

    strcat(buf, tbuf);
    current_len += written;
    curr = curr->next;
  }
  // Append "NULL" if needed space exists 
  strcat(buf, "NULL");
  return buf;
}


// Returns the length of the list (0-based count)
int list_length(list_t *l) {
  if (l == NULL) { // Handle NULL list pointer
    return 0; // Or perhaps -1 to indicate an error state
  }
  
  int count = 0;
  node_t* current = l->head;
  
  while (current != NULL) {
    count++;
    current = current->next;
  }
  
  return count;
}

// Add a new node with the given value to the back of the list
void list_add_to_back(list_t *l, elem value) {
  if (l == NULL) return; // Cannot add to a NULL list pointer
  
  node_t* new_node = (node_t *) malloc(sizeof(node_t));
  if (!new_node) return; // Malloc check
  new_node->value = value;
  new_node->next = NULL;
  
  // If the list is empty, the new node becomes the head
  if (l->head == NULL) {
    l->head = new_node;
    return;
  }
  
  // Traverse to the end of the list
  node_t* current = l->head;
  while (current->next != NULL) {
    current = current->next;
  }
  
  // Add the new node at the end
  current->next = new_node;
}

// Add a new node with the given value to the front of the list
void list_add_to_front(list_t *l, elem value) {
  if (l == NULL) return; // Cannot add to a NULL list pointer
     
  node_t* new_node = (node_t *) malloc(sizeof(node_t));
  if (!new_node) return; // Malloc check
  new_node->value = value;
  
  // Insert to front
  new_node->next = l->head;
  l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
    if (l == NULL || index < 1) {
        return; // Invalid index.
    }
    
    // Special handling if the list is empty.
    if (l->head == NULL) {
        if (index == 1) {
            node_t *new_node = malloc(sizeof(node_t));
            if (!new_node) {
                perror("Failed to allocate node");
                return;
            }
            new_node->value = value;
            new_node->next = NULL;
            l->head = new_node;
        }
        return;
    }
    
    // Calculate current list length.
    int length = 0;
    node_t *current = l->head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    // Case 1: Insertion at head.
    if (index == 1) {
        node_t *new_node = malloc(sizeof(node_t));
        if (!new_node) {
            perror("Failed to allocate node");
            return;
        }
        new_node->value = value;
        new_node->next = l->head;
        l->head = new_node;
        return;
    }
    
    // Case 2: Append at the back.
    if (index == length + 1) {
        node_t *new_node = malloc(sizeof(node_t));
        if (!new_node) {
            perror("Failed to allocate node");
            return;
        }
        new_node->value = value;
        new_node->next = NULL;
        current = l->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        return;
    }
    
    // Case 3: Replacement if 1 < index <= length.
    if (index <= length) {
        current = l->head;
        int pos = 1;
        while (current != NULL && pos < index) {
            current = current->next;
            pos++;
        }
        if (current != NULL) {
            current->value = value;
        }
        return;
    }
    
    // Otherwise, index > length + 1 is out-of-bounds; do nothing.
}


// Remove and return the value from the back of the list
elem list_remove_from_back(list_t *l) {
  // Use -1 to signify error/empty list
  elem error_val = -1; 

  if (l == NULL || l->head == NULL) {
    return error_val; // Error: NULL list pointer or Empty list
  }
  
  // If there's only one node
  if (l->head->next == NULL) {
    elem value = l->head->value;
    free(l->head);
    l->head = NULL;
    return value;
  }
  
  // Traverse to the second-to-last node
  node_t* current = l->head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  
  // Store the value to return
  node_t* node_to_free = current->next;
  elem value = node_to_free->value;
  
  // Free the last node and update the list
  free(node_to_free);
  current->next = NULL;
  
  return value;
}

// Remove and return the value from the front of the list
elem list_remove_from_front(list_t *l) {
  elem error_val = -1; 
  if (l == NULL || l->head == NULL) {
    return error_val; // Error: NULL list pointer or Empty list
  }
  
  node_t* old_head = l->head;
  elem value = old_head->value;
  
  // Update the head to the next node
  l->head = old_head->next;
  
  // Free the old head
  free(old_head);
  
  return value;
}

// Remove and return the value at the specified 1-based index
elem list_remove_at_index(list_t *l, int index) {
    if (l == NULL || l->head == NULL || index < 1) {
        return -1; // Invalid input, as valid indices are >= 1.
    }
    
    // Removing the head if index is 1.
    if (index == 1) {
        node_t *temp = l->head;
        elem removed = temp->value;
        l->head = temp->next;
        free(temp);
        return removed;
    }
    
    // Traverse to the node immediately before the one to be removed.
    node_t *current = l->head;
    int counter = 1;
    while (current != NULL && counter < index - 1) {
        current = current->next;
        counter++;
    }
    
    // If the next node doesn't exist, the index is out-of-bounds.
    if (current == NULL || current->next == NULL) {
        return -1;
    }
    
    // Remove the target node.
    node_t *target = current->next;
    elem removed = target->value;
    current->next = target->next;
    free(target);
    
    return removed;
}


// Check if the value exists in the list
int list_is_in(list_t *l, elem value) {
    if (l == NULL) {
        return 0;
    }
    int count = 0;
    node_t *current = l->head;
    while (current != NULL) {
        if (current->value == value) {
            count++;
        }
        current = current->next;
    }
    return count;
}

elem list_get_elem_at(list_t *l, int index) {
    if (l == NULL || index < 1) {
        return -1;  // Invalid list pointer or index.
    }
    node_t *current = l->head;
    int pos = 1;
    while (current != NULL) {
        if (pos == index) {
            return current->value;
        }
        current = current->next;
        pos++;
    }
    return -1;  // Index out-of-bounds.
}

int list_get_index_of(list_t *l, elem value) {
    if (l == NULL) {
        return -1;  // Invalid list pointer.
    }
    node_t *current = l->head;
    int pos = 1;
    while (current != NULL) {
        if (current->value == value) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;  // Value not found.
}

