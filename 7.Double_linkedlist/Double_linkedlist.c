#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* head;
struct node* newnode;

void create();
void insert_at_beg();
void insert_at_end();
void insert_at_pos();
void delete_at_beg();
void delete_at_end();
void delete_at_pos();
void display(); 

int main()
{
	int ch;

	while(1)
	{
		printf("\n1. Insert Element");
		printf("\n2. Insert at beginning");
		printf("\n3. Insert at end");
		printf("\n4. Insert at position");
		printf("\n5. Delete at beginning");
		printf("\n6. Delete at end");
		printf("\n7. Delete at position");
		printf("\n8. Display Elements");
		printf("\n0. Exit");

		printf("\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				insert_at_beg();
				break;
			case 3:
				insert_at_end();
				break;
			case 4:
				insert_at_pos();
				break;
			case 5:
				delete_at_beg();
				break;
			case 6:
				delete_at_end();
				break;
			case 7:
				delete_at_pos();
				break;
			case 8:
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
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			newnode->prev = temp;
			temp = newnode;
		}

		printf("Continue? (1/0): ");
		scanf("%d",&choice);
	}
}

void insert_at_beg()
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	newnode->prev = NULL;

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		head->prev = newnode;
		newnode->next = head;
		head = newnode;
	}
}

void insert_at_end()
{
	struct node* newnode, *temp;
	temp = head;

	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	newnode->prev = NULL;

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newnode;
		newnode->prev = temp;
	}
}

void insert_at_pos()
{
	struct node* newnode, *temp, *temp2;
	int pos;

	temp = head;

	printf("Enter the position: ");
	scanf("%d",&pos);

	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	newnode->prev = NULL;

	while (pos > 2 && temp != NULL)
	{
		temp = temp->next;
		pos--;
	}

	if (temp != NULL)
	{
		temp2 = temp->next;
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;

		if (temp2 != NULL)
		{
			temp2->prev = newnode;
		}
	}
	else
	{
		printf("Invalid position\n");
		free(newnode);
	}
}

void delete_at_beg()
{
	struct node* temp;

	if (head == NULL)
	{
		printf("Underflow\n");
	}
	else if (head->next == NULL)
	{
		free(head);
		head = NULL;
		printf("Node deleted\n");
	}
	else
	{
		temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
		printf("Node deleted\n");
	}
}

void delete_at_end()
{
	struct node* temp, *temp2;
	if (head == NULL)
	{
		printf("Underflow\n");
	}
	else if (head->next == NULL)
	{
		free(head);
		head = NULL;
		printf("Node deleted\n");
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp2 = temp->prev;
		temp2->next = NULL;
		free(temp);
		printf("Node deleted\n");
	}
}

void delete_at_pos()
{
	struct node* temp, *temp2;
	int pos;
	temp = head;
	printf("\nEnter the position to delete the node: ");
	scanf("%d",&pos);

	while (pos > 1 && temp != NULL)
	{
		temp = temp->next;
		pos--;
	}

	if (temp != NULL)
	{
		temp2 = temp->prev;
		temp2->next = temp->next;

		if (temp->next != NULL)
		{
			temp->next->prev = temp2;
		}

		free(temp);
		printf("Node deleted\n");
	}
	else
	{
		printf("Invalid position\n");
	}
}

void display()
{
	struct node* temp;
	temp = head;

	printf("Head");

	while (temp != NULL)
	{
		printf(" <-> %d", temp->data);
		temp = temp->next;
	}

	printf(" <-> Tail\n");
}
