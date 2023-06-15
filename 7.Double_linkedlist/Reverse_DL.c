#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* head;

void create();
void search();
void reverse();
void display();

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert Elements\n2.Search for Elements\n3.Reverse\n4.Display\n0.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				search();
				break;
			case 3:
				reverse();
				break;
			case 4:
				display();
				break;
			case 0:
				exit(0);
			default:
				printf("Enter a valid choice!\n");
		}
	}
}

void create()
{
	head = NULL;
	struct node* temp;
	struct node* newnode;
	int choice = 1;

	while(choice)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		newnode->prev = NULL;

		if(head == NULL)
		{
			head = newnode;
			temp = newnode;
		}
		else
		{
			temp->next = newnode;
			newnode->prev = temp;
			temp = newnode;
		}

		printf("Continue? (1/0): ");
		scanf("%d", &choice);
	}
}

void search()
{
	if (head == NULL)
	{
		printf("Empty List\n");
		return;
	}

	int item, flag = 0;
	printf("Enter item to search: ");
	scanf("%d", &item);

	struct node* temp = head;
	int i = 0;

	while (temp != NULL)
	{
		if (temp->data == item)
		{
			printf("Item found at location %d\n", i + 1);
			flag = 1;
			break;
		}

		temp = temp->next;
		i++;
	}

	if (flag == 0)
	{
		printf("Item not found\n");
	}
}

void reverse()
{
	if (head == NULL)
	{
		printf("Empty List\n");
		return;
	}

	struct node* current = head;
	struct node* temp = NULL;

	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
	{
		head = temp->prev;
	}
}

void display()
{
	if (head == NULL)
	{
		printf("Empty List\n");
		return;
	}

	struct node* temp = head;

	printf("Head");
	while(temp != NULL)
	{
		printf(" <-> %d", temp->data);
		temp = temp->next;
	}
	printf(" <-> Tail\n");
}
