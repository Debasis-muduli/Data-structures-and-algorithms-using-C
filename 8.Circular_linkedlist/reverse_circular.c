#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head, *newnode;
void create();
void reverse();
void display();
void create()
{
	struct node *temp;
	head = NULL;
	int ch = 1;
	while (ch)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter the data:\n");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		if (head == NULL)
		{
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
		printf("Continue...");
		scanf("%d", &ch);
	}
}
void display()
{
	struct node *temp;
	temp = head;
	if (temp == NULL)
	{
		printf("NOTHING TO PRINT...\n");
	}
	else
	{
		printf("....PRINTING VALUES....\n");
		printf("Head-->");
		while (temp != NULL)
		{
			printf("%d-->", temp->data);
			temp = temp->next;
		}
		printf("Tail\n");
	}
}
void main()
{
	create();
	display();
	reverse();
	display();
}
void reverse()
{
	struct node *pnode;
	struct node *cnode;
	pnode = NULL;
	newnode = head;
	cnode = head;
	while (newnode != NULL)
	{
		newnode = newnode->next;
		cnode->next = pnode;
		pnode = cnode;
		cnode = newnode;
	}
	head = pnode;
}
