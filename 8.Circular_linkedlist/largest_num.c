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

int largest()
{
	struct node *temp = head->next;

	int a = head->data;

	while (temp != head)
	{
		if (a < temp->data)
		{
			a = temp->data;
		}
		temp = temp->next;
	}
	return a;
}

void main()
{
	int ch, num;
	while (1)
	{
		printf("...Menu Driven Program...");
		printf("0.exit\n1.create\n2.find largest\n3.display\n");
		printf("enter choice:");
		scanf("%d:", &ch);
		switch (ch)
		{
		case 0:
			exit(0);
			break;
		case 1:
			create();
			break;
		case 2:
			num = largest();
			printf("The largest number is %d\n\n", num);
			break;
		case 3:
			display();
			break;
		}
	}
}
