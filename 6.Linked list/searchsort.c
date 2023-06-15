#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* start = NULL;

void insert(int value);
void sort();
int search(int key);
void display();

int main()
{
    int choice, value, key, position;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Sort");
        printf("\n3. Search");
        printf("\n4. Display");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                sort();
                printf("List sorted\n");
                break;
            case 3:
                printf("\nEnter the element to search:\n");
                scanf("%d", &key);
                position = search(key);
                if (position != -1)
                {
                    printf("Element found at position %d\n", position);
                }
                else
                {
                    printf("Element not found\n");
                }
                break;
            case 4:
                display();
                break;
            case 0:
                exit(0);
            default:
                printf("\nEnter a valid choice!!!!\n");
        }
    }
    return 0;
}

void insert(int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        struct node* current = start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Element inserted\n");
}

void sort()
{
    if (start == NULL || start->next == NULL)
    {
        return;
    }

    struct node* current;
    struct node* index;
    int temp;

    for (current = start; current->next != NULL; current = current->next) 
    {
        for (index = current->next; index != NULL; index = index->next)
        {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }	
    }
}

int search(int key)
{
    struct node* current = start;
    int position = 1;

    while (current != NULL)
    {
        if (current->data == key)
        {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Element not found
}

void display()
{
    struct node* current = start;

    if (current == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("\nPrinting values\n\n");
    printf("Head -> ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
