#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    // add *next and *prev here
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct
{
    // add Node* head, tail, current_position and other necessary fields here
    Node *head;
    Node *tail;
    Node *current;
    int size;
} LinkedList;

void init_linkedlist(LinkedList *list)
{
    // printf("implement init_linkedlist\n");
    //  initialize head, tail with null
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    list->size = 0;
    printf("LinkedList is now set to go\n");
}

void clear(LinkedList *list)
{
    // printf("Implement clear\n");
    //  traverse the list and free each node
    //  set head and tail to null
    Node *current = list->head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    list->size = 0;
    printf("Linked list cleared.\n");
}

int get_size(LinkedList *list)
{
    // printf("Implement get_size\n");
    return list->size;
}

void append(LinkedList *list, int value)
{
    // printf("Implement append\n");
    //  create a new node and set its value
    //  consider the case when the list is empty and when it isnt
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = list->tail;
    if (list->size == 0)
    {
        list->head = newNode;
        list->current = newNode;
    }
    else
    {
        list->tail->next = newNode;
    }
    list->tail = newNode;
    list->size++;
}

void insert(LinkedList *list, int value)
{
    // printf("Implement insert\n");
    //  create a new node and set its value
    //  place it at the current position (check order of operations)
    //  consider the case when the list is empty and when it isnt
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    if (list->size == 0)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        list->head = list->tail = list->current = newNode;
    }
    else
    {
        newNode->next = list->current;
        newNode->prev = list->current->prev;
        if (list->current->prev != NULL)
        {
            list->current->prev->next = newNode;
        }
        else
        {
            list->head = newNode;
        }
        list->current->prev = newNode;
        list->current = newNode;
    }
    list->size++;
}

int remove_at_current(LinkedList *list)
{
    // printf("Implement remove_at_current\n");
    //  consider the case when current code is at the begining or at the end
    if (list->size == 0 || list->current == NULL)
        return -1; // because empty or no nodes left
    int value = list->current->data;
    Node *rmv = list->current;
    if (list->current->prev != NULL)
    {
        list->current->prev->next = list->current->next;
    }
    else
    {
        list->head = list->current->next;
    }
    if (list->current->next != NULL)
    {
        list->current->next->prev = list->current->prev;
        list->current = list->current->next;
    }
    else
    {
        list->tail = list->current->prev;
        list->current = list->tail;
    }
    free(rmv);
    list->size--;
    return value;
}

int find(LinkedList *list, int value)
{
    // printf("Implement find\n");
    //  traverse the list and return the position of the value
    Node *temp = list->head; // so that it doesn't get lost
    int pos = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1; // not found T~T
}

void move_to_start(LinkedList *list)
{
    // printf("Implement move_to_start\n");
    list->current = list->head;
}

void move_to_end(LinkedList *list)
{
    // printf("Implement move_to_end\n");
    list->current = list->tail;
}

void prev(LinkedList *list)
{
    // printf("Implement prev\n");
    if (list->current != NULL && list->current->prev != NULL)
    {
        list->current = list->current->prev;
        printf("moved to the previous position from %d to %d.\n", list->current->prev, list->current);
    }
    else
        printf("At the start already.\n");
}

void next(LinkedList *list)
{
    // printf("Implement next\n");
    if (list->current != NULL && list->current->next != NULL)
    {
        list->current = list->current->next;
        printf("moved to the next position from %d to %d\n", list->current->prev, list->current);
    }
    else
        printf("at the end already\n");
}

void move_to_position(LinkedList *list, int position)
{
    // printf("Implement move_to_position\n");
    //  traverse the list and stop at the given position
    if (position < 0 || position >= list->size || list->current == NULL)
        return;
    Node *temp = list->head;
    int pos = 0;
    while (temp != NULL && temp != list->current)
    {
        temp = temp->next;
        pos++;
    }
    if (position == pos)
    {
        printf("already at position %d\n", position);
        return;
    }
    printf("moved to position %d from %d\n", position, pos);
    if (position > pos) // moving forward
    {
        for (int i = pos; i < position; i++)
        {
            list->current = list->current->next;
        }
    }
    else
    {
        for (int i = pos; i > position; i--)
        {
            list->current = list->current->prev;
        }
    }
}

int get_current_position(LinkedList *list)
{
    // printf("Implement get_current_position\n");
    //  traverse the list and stop when you are at the current position
    //  return the position (integer)
    Node *temp = list->head;
    int pos = 0;
    while (temp != NULL && temp != list->current)
    {
        temp = temp->next;
        pos++;
    }
    // printf("current position is %d\n", (temp == NULL) ? -1 : pos);
    return (temp == NULL) ? -1 : pos; // if the current pos is overflowed
}

int get_current_element(LinkedList *list)
{
    // printf("Implement get_current_element\n");
    //  return the value at the current position
    if (list->current == NULL)
        return -1; // no current element
    return list->current->data;
}

void print_list(LinkedList *list)
{
    // printf("< list elements here >");
    Node *temp = list->head;
    printf("<  ");
    while (temp != NULL)
    {
        if (temp == list->current)
            printf("|");
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf(" >");
    printf("\n");
}

void free_list(LinkedList *list)
{
    // printf("Implement free_list\n");
    //  free each node in the list
    free(list);
    printf("freed\n");
}

void skip(LinkedList *list)
{
    if(list->current!=NULL) next(list);
    printf("skip operation done\n");
    print_list(list);
}

void move_and_shift(LinkedList *list, int position)
{
    if(list->current==NULL || position<0 || position>=list->size)
    {
        printf("Invalid move_and_shift operation\n");
        return;
    }
    int value=remove_at_current(list);
    move_to_position(list, position);
    insert(list, value);
    print_list(list);
}

void discard(LinkedList *list)
{
    if(list->current)
    {
        int rmv=remove_at_current(list);
        print_list(list);
    }
    else printf("nothing to discard\n");
}