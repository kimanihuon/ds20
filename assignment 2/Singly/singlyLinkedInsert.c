#include <stdio.h>
#include <stdlib.h>

// Define structure of the node
struct Node
{
    int data;
    struct Node *next;
};

// Create function with return type of struct node
struct Node *create()
{
    return (struct Node *)malloc(sizeof(struct Node));
}

/* Given a reference (pointer to pointer) to the head of a list and an int,  inserts a new node on the front of the list. */
void add(struct Node **reference, int new_data)
{
    /* 1. allocate node */
    struct Node *new_node = create();

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = (*reference);

    /* 4. move the head to point to the new node */
    (*reference) = new_node;
}

// Insert after a certain node
void addAfter(struct Node **prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        printf("\nthe given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node *new_node = create();

    /* 3. put in the data  */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = (*prev_node)->next;

    /* 5. move the next of prev_node as new_node */
    (*prev_node)->next = new_node;
}

void append(struct Node **reference, int new_data)
{
    /* 1. allocate node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    struct Node *last = *reference; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so make next of 
          it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*reference == NULL)
    {
        *reference = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

// function to traverse list
void traverse(struct Node **reference)
{
    struct Node *pointer = *reference;

    while (1 == 1)
    {
        // While not at end of node
        if (pointer->next != NULL)
        {
            printf("%d \n", pointer->data);
            pointer = pointer->next;
        }
        // While at end of node
        else
        {
            printf("%d \n", pointer->data);
            return;
        }
    }
}

// Program to create a simple linked
// list with 3 nodes
int main()
{

    // Create three nodes
    // ... first is the HEAD
    struct Node *first = create();
    struct Node *second = create();
    struct Node *third = create();

    /*Data is random because we haven’t assigned  
    anything yet  */

    first->data = 1;      // assign data in first node
    first->next = second; // Link first node with the second node

    second->data = 2;     // assign data to second node
    second->next = third; // Link second node with the third node

    third->data = 3;    // assign data to third node
    third->next = NULL; // Complete list

    printf("Before First Insertion: \n");
    // Pass in a pointer to the head (pointer to pointer)
    traverse(&first);

    printf("\nAfter First insertion: \n");
    // Pass pointer to list and integer to be inserted
    add(&first, 1000);
    traverse(&first);

    printf("\nInsertion after: \n");
    addAfter(&first, 45678);
    traverse(&first);

    printf("\nInsertion Last: \n");
    append(&first, 6567);
    traverse(&first);

    return 0;
}
