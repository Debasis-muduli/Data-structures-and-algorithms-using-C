#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int data)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;

	if (front == NULL && rear == NULL)
	{
		front = rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = rear->next;
	}
}
void display()
{
	if (front == NULL && rear == NULL)
	{
		printf("Nothing to dispaly\n");
	}
	else
	{
		struct node *temp = front;
		printf("HEAD-->");
		while (temp != NULL)
		{
			printf("%d-->", temp->data);
			temp = temp->next;
		}
		printf("TAIL\n");
	}
}

void dequeue()
{
	struct node *temp = front;
	if (front == NULL)
	{
		printf("Queue is Empty\n");
	}
	else if (front == rear)
	{
		printf("Deleted item is %d\n", front->data);
		front = rear = NULL;
	}

	else
	{
		printf("deleted item is %d\n", temp->data);
		front = front->next;
	}
}

void main()
{
	int ch, num;
	while (1)
	{
		printf("...Menu Driven Program...");
		printf("\n0.exit\n1.enqueue\n2.dequeue\n3.display\n");
		printf("enter choice:");
		scanf("%d:", &ch);
		switch (ch)
		{
		case 0:
			exit(0);
			break;
		case 1:
			printf("Enter a number:");
			scanf("%d", &num);
			enqueue(num);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		}
	}
}
