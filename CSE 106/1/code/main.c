#include "arraylist.h"
//#include "linkedlist.h"
#include <stdio.h>

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {

        return 1;
    }
    FILE *out = fopen("out.txt", "w");
    if (out == NULL)
    {
        fclose(file);
        return 1;
    }
    fclose(out);
    freopen("out.txt", "w", stdout);

    int capacity;
    int size;
    fscanf(file, "%d %d", &size, &capacity);

    ArrayList list;
    init_arraylist(&list, capacity);
    // LinkedList list;
    // init_linkedlist(&list);
    int i;
    for (i = 0; i < size; i++)
    {
        int value;
        fscanf(file, "%d", &value);
        append(&list, value);
        printf("appended %d. and now the new size is: %d\n", value, get_size(&list));
        print_list(&list);
    }
    printf("\n");
    print_list(&list);

    int func, param;
    while (fscanf(file, "%d %d", &func, &param) == 2 && func != 0)
    {
        if (func == 1)
        {
            insert(&list, param);
            printf("inserted %d at %d position\n", param, get_current_position(&list));
        }
        else if (func == 2)
        {
            int value = remove_at_current(&list);
            printf("removed %d from position %d\n", value, get_current_position(&list));
        }
        else if (func == 3)
        {
            int ret = find(&list, param);
            if (ret != -1)
                printf("%d found at %d position\n", param, ret);
            else
                printf("%d not found in the list\n", param);
        }
        else if (func == 4)
        {
            move_to_start(&list);
            printf("moved to start.\n");
        }
        else if (func == 5)
        {
            move_to_end(&list);
            printf("moved to end.\n");
        }
        else if (func == 6)
        {
            prev(&list);
        }
        else if (func == 7)
        {
            next(&list);
        }
        else if (func == 8)
        {
            int pos = get_current_position(&list);
            printf("current position is %d\n", pos);
        }
        else if (func == 9)
        {
            move_to_position(&list, param);
        }
        else if (func == 10)
        {
            int len = get_size(&list);
            printf("current size is %d\n", len);
        }
        else if (func == 11)
        {
            int value = get_current_element(&list);
            if (value == -1)
                printf("no current element.\n");
            else
                printf("current element is %d\n", value);
        }
        else if (func == 12)
        {
            append(&list, param);
            printf("appended %d. and now the new size is: %d\n", param, get_size(&list));
        }
        else if (func == 13)
        {
            clear(&list);
        }
        else
        {
            printf("Invalid function\n");
        }
        print_list(&list);
    }
    printf("Program ended\n");
    free_list(&list);
    fclose(out);
    fclose(file);
    return 0;
}