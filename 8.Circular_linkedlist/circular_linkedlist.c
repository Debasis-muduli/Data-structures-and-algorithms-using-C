#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;
void create()
{
	struct node *newnode, *temp;
	int ch = 1;
	head = NULL;
	while (ch)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter the data:\n");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		if (head == NULL)
		{
			temp = head = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
		temp->next = head;
		printf("Continue...");
		scanf("%d", &ch);
	}
}

void display()
{
	struct node *temp;
	if (head == NULL)
	{
		printf("LIST IS EMPTY");
	}
	else
	{
		temp = head;
		while (temp->next != head)
		{
			printf("%d<>", temp->data);
			temp = temp->next;
		}
		printf("%d\n", temp->data);
	}
}

void ins_beg()
{
	struct node *newnode;
	struct node *temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	if (newnode == NULL)
	{
		printf("NO MEMORY ALLOCATION\n");
	}
	else
	{
		printf("Enter the data:\n");
		scanf("%d", &newnode->data);
		if (head == NULL)
		{
			head = newnode;
			newnode->next = head;
		}
		else
		{
			temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			newnode->next = head;
			temp->next = newnode;
			head = newnode;
		}
	}
}

void ins_end()
{
	struct node *newnode;
	struct node *temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	if (newnode == NULL)
	{
		printf("No memory allocation\n");
	}
	else
	{
		printf("Enter the data:");
		scanf("%d", &newnode->data);
		if (head == NULL)
		{
			head = newnode;
			newnode->next = head;
		}
		else
		{
			temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			newnode->next = head;
			temp->next = newnode;
		}
	}
}

void ins_pos()
{
	struct node *newnode, *temp;
	int pos;
	newnode = (struct node *)malloc(sizeof(struct node));
	if (head == NULL)
	{
		printf("Cannot enter an element at this place");
		return;
	}
	printf("\nenter the data\n");
	scanf("%d", &newnode->data);
	printf("\nEnter the position to be inserted");
	scanf("%d", &pos);
	temp = head;

	while (--pos > 1)
	{
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}
void del_beg()
{
	struct node *temp = head, *last = NULL;

	if (head == NULL)
		printf("list is empty\n");
	else
	{
		if (temp->next == head)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			while (temp->next != head)
			{
				temp = temp->next;
			}
			last = temp;
			temp = head;
			head = head->next;
			free(temp);
			last->next = head;

			printf("\nDeletion Successful");
		}
	}
}

void del_end()
{
	struct node *temp = head, *last = NULL;

	if (head == NULL)
		printf("list is empty\n");
	else
	{
		if (temp->next == head)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			while (temp->next != head)
			{
				last = temp;
				temp = temp->next;
			}
			last->next = head;
			free(temp);

			printf("\nDeletion Successful");
		}
	}
}
void del_pos(int pos)
{
	struct node *temp = head, *last = NULL;

	if (head == NULL)
		printf("list is empty\n");
	else
	{
		if (temp->next == head)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			while (pos > 1)
			{
				last = temp;
				temp = temp->next;
				pos--;
			}
			last->next = temp->next;
			free(temp);
			printf("\nDeletion Successful");
		}
	}
}

void main()
{
	int c, pos;
	while (1)
	{
		printf("\n...Menu driven program..\n");
		printf("1.Create circular linked list\n2.Display\n3.Insert at begin\n4.Insert at end\n5.Insert at any position\n");
		printf("6.delete at begin\n7.delete at end\n8.delete at any position\n");
		printf("0.Exit\n");
		printf("Enter the choice\n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			ins_beg();
			break;
		case 4:
			ins_end();
			break;
		case 5:
			ins_pos();
			break;
		case 6:
			del_beg();
			break;
		case 7:
			del_end();
			break;
		case 8:
			printf("Enter the position you want to delete: ");
			scanf("%d", &pos);
			del_pos(pos);
			break;

		case 0:
			printf("Thank u");
			exit(0);
			break;
		}
	}
}
