#include <stdio.h>
#include <stdlib.h>

int k = -1;

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* previous;
}Node;

void insert(Node** head, int x)
{
    Node* tail;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;
    newNode -> next = NULL;

        if(*head == NULL)
        {
        newNode -> previous = NULL;
        *head = tail = newNode;
        return;
        }

        tail -> next = newNode;
        newNode -> previous = tail;
        tail = newNode;
}

void delete(Node** head, int x)
{
    Node* s = *head;
    Node* p = NULL;
    while(s != NULL)
    {
        if(s -> data == x)
        {
            if(p == NULL)
            {
                *head = s -> next;
                free(s);
                return;
            }

            p -> next = s -> next;
            if(s -> next != NULL)
            s -> next -> previous = p;

            free(s);
            return;
        }
        p = s;
        s = s -> next;
    }
    printf("Node Not Found!!\n");
}

void display(Node** head, char ch)
{
    Node* s = *head;

    if(s == NULL)
    printf("Empty List");

    if(ch == 'N')
    while(s != NULL)
    {
        printf("%d ", s -> data);
        s = s -> next;
    }

    else if(ch == 'R')
    {
        while(s -> next != NULL)
            s = s -> next;

        while(s != NULL)
        {
            printf("%d ", s -> data);
            s = s -> previous;
        }
    }
    printf("\n");
}

int main()
{
    printf("Menu :\n1. Create a Doubly Linked-List.\n2. Enter elements into the List.\n3. Delete elements from the list.\n4. Display the list.\n");
    int flag = 1;
    int choice;
    Node* arr[10];
    while(flag)
    {
        printf("Enter Choice:\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            arr[++k] = NULL;
            break;

            case 2:
            int n1;
            printf("Enter the number of elements to be inserted:\n");
            scanf("%d", &n1);

            printf("Enter %d elements:\n", n1);
            for(int i = 0; i < n1; i++)
            {
                int a = 0;
                scanf("%d", &a);
                insert(&arr[k], a);
            }
            break;

            case 3:
            int n2;
            printf("Enter the number of elements to be deleted:\n");
            scanf("%d", &n2);

            printf("Enter %d elements to be deleted:\n", n2);
            for(int i = 0; i < n2; i++)
            {
                int a = 0;
                scanf("%d", &a);
                delete(&arr[k], a);
            }
            break;

            case 4:
            char ch;
            printf("Enter N or R to display elements in Normal or Reversed order, respectively:\n");
            getchar();
            scanf("%c", &ch);

            display(&arr[k], ch);
            break;

            default:
            flag = 0;
        }
    }
    return 0;
}