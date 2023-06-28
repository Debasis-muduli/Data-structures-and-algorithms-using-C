#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;

void push(int n)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=n;
	if(top==NULL)
	{
		top=newnode;
		newnode->next=NULL;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}

void pop()
{
	if(top==NULL)
		printf("Stack is empty\n");
	else{
		struct node*temp=top;
		printf("\nDeleted element:%d\n",temp->data);
		top=temp->next;
		free(temp);
	}
}

void display()
{
	if(top==NULL)
		printf("\nstack is empty!!!\n");
	else
	{
		struct node *temp=top;
		printf("Head-->");
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("Tail\n");
	}

}

void main()
{
	int ch,num;
	while(1)
	{
		printf("\n0.exit\n1.push\n2.pop\n3.display\n");
		printf("enter choice:");
		scanf("%d:",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
				break;
			case 1:
				printf("Enter a number:");
				scanf("%d",&num);
				push(num);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			}
	}
}

	
