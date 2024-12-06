#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int size;
    int capacity;
    int current;
    // Add more fields here

} ArrayList;

void init_arraylist(ArrayList *list, int capacity)
{
    // printf("implement init_arraylist\n");
    //  dynamically allocate space for the array
    //  initialize the size, capacity, and current position
    list->array = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
    list->current = 0;
    printf("present capacity: %d\n", capacity);
}

void clear(ArrayList *list)
{
    // printf("Implement clear\n");
    //  clear the list but do not free the array
    //  modify the size, capacity, and current position
    list->size = 0;
    list->current = 0;
    printf("Array List cleared.\n");
}

int get_size(ArrayList *list)
{
    // printf("Implement get_size\n");
    return list->size;
}

void resize(ArrayList *list, int new_capacity)
{
    // printf("Implement resize\n");
    //  allocate space for new array with new_capacity
    //  print log message
    int *newlist = (int *)malloc(new_capacity * sizeof(int));
    for (int i = 0; i < list->size; i++)
    {
        newlist[i] = list->array[i]; // copy the elements to the new array
    }
    free(list->array);
    list->array = newlist;
    printf("resized update: old capacity= %d to new capacity= %d\n", list->capacity, new_capacity);
    list->capacity = new_capacity;
}

void append(ArrayList *list, int value)
{
    // printf("Implement append\n");
    //  call resize if necessary
    //  add value to the end of the list
    if (list->size == list->capacity)
    {
        resize(list, list->capacity * 2);
    }
    list->array[list->size++] = value;
}

void insert(ArrayList *list, int value)
{
    // printf("Implement insert\n");
    //  call resize if necessary
    //  shift the elements to the right to make space
    //  add value at the current position
    if (list->size == list->capacity)
    {
        resize(list, list->capacity * 2);
    }
    for (int i = list->size; i > list->current; i--)
    {
        list->array[i] = list->array[i - 1];
    }
    list->array[list->current] = value;
    list->size++;
}

int remove_at_current(ArrayList *list)
{
    // printf("Implement remove_at_current\n");
    if (list->size == 0)
        return -1;
    // save the value of the current element in a variable
    // shift the elements to the left to fill the gap
    // change the size, and current position as necessary
    // call resize if necessary
    // return the saved value
    int value = list->array[list->current];
    for (int i = list->current; i < list->size - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    if (list->size < list->capacity / 4)
    {
        resize(list, list->capacity / 2);
    }
    return value;
}

int find(ArrayList *list, int value)
{
    // printf("Implement find\n");
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == value)
            return i;
    }
    return -1;
    // traverse the list and return the position of the value
    // return -1 if the value is not found
}

void move_to_start(ArrayList *list)
{
    // printf("Implement move_to_start\n");
    //  consider the cases when the list is empty
    list->current = 0;
}

void move_to_end(ArrayList *list)
{
    // printf("Implement move_to_end\n");
    //  consider the cases when the list is empty
    if (list->size == 0)
    {
        list->current = 0;
    }
    else
    {
        list->current = list->size - 1;
    }
}

void prev(ArrayList *list)
{
    // printf("Implement prev\n");
    //  no change if the current position is at the start
    if (list->current > 0)
    {
        list->current--;
        printf("moved to the previous position.\n");
    }
    else
        printf("already at the start.\n");
}

void next(ArrayList *list)
{
    // printf("Implement next\n");
    //  no change if the current position is at the end
    if (list->current < list->size - 1)
    {
        list->current++;
        printf("moved to next position.\n");
    }
    else
        printf("already at the end.\n");
}

void move_to_position(ArrayList *list, int position)
{
    // printf("Implement move_to_position\n");
    if (position >= 0 && position < list->size)
    {
        printf("moved to position %d from %d\n", position, list->current);
        list->current = position; // Move to the specified position
    }
    else
    {
        printf("Invalid position: %d\n", position);
    }
}

int get_current_position(ArrayList *list)
{
    // printf("Implement get_current_position\n");
    return list->current;
}

int get_current_element(ArrayList *list)
{
    // printf("Implement get_current_element\n");
    if (list->size == 0)
        return -1; // no elements
    else
    {
        return list->array[list->current];
    }
}

void print_list(ArrayList *list)
{
    // printf("< list elements here >");
    printf("<  ");
    for (int i = 0; i < list->size; i++)
    {
        if (i == list->current)
            printf("|");
        printf("%d ", list->array[i]);
    }
    printf(" >\n");
}

void free_list(ArrayList *list)
{
    // printf("Implement free_list\n");
    //  free the array before terminating the program
    free(list->array);
    list->array = NULL;
    list->size = 0;
    list->capacity = 0;
    list->current = 0;
    printf("freed Arraylist.\n");
}

void skip(ArrayList *list)
{
    if (list->current < list->size - 1)
    {
        list->current++; // Move to the next book
    }
    else
    {
        printf("Already at the end of the list.\n");
    }
}

void swap_with(ArrayList *list, int index)
{
    if (index >= 0 && index < list->size)
    {
        int temp = list->array[list->current];
        list->array[list->current] = list->array[index];
        list->array[index] = temp;
        printf("Swapped current element with element at index %d.\n", index);
    }
    else
    {
        printf("Invalid index for swap operation.\n");
    }
}

void discard(ArrayList *list)
{
    if (list->size == 0)
    {
        printf("The list is empty. Nothing to discard.\n");
        return;
    }
    for (int i = list->current; i < list->size - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    if (list->current >= list->size)
    {
        list->current = list->size - 1;
    }
    if (list->size < list->capacity / 4 && list->capacity > 1)
    {
        resize(list, list->capacity / 2);
    }
    printf("Discarded current element.\n");
}
