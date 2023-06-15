#include<stdio.h>
#include<stdlib.h>
void insert();
void sorting();
void display();
struct node
{
	int data;
	struct node*next;
};
struct node*start;
void sorting()
{
	struct node*ptr,*cptr;
	int temp;
	ptr=start;
	while(ptr->next!=NULL)
	{
		cptr=ptr->next;
		while(cptr!=NULL)
		{
			if(ptr->data>cptr->data)
			{
				temp=ptr->data;
				ptr->data=cptr->data;
				cptr->data=temp;
			}
			cptr=cptr->next;
		}
		ptr=ptr->next;
	}
	printf("\n");
	display();
	printf("\n");
}
void display()
{
	struct node*p;
	p=start;
	if(p==NULL)
	{
		printf("nothing to display\n");
	}
	else
	{
		printf("\ndisplay values\n");
		printf("head");
		while(p!=NULL)
		{
			printf("%d->",p->data);
			p=p->next;
		}
		printf("tail\n");
	}
}
void insert()
{
	struct node*p;
	int value;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("no memmory allocation\n");
		return;
	}
	else
	{
		printf("enter the data\n");
		scanf("%d",&value);
		p->data=value;
		p->next=start;
		start=p;
	}
}
void main()
{
	int x;
	while(1)
	{
		printf("enter choice\n1.insert a node\n2.display\n3.sort\n4.exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				insert();
				break;
			case 3:
				sorting();
				break;
			case 2:
				display();
				break;
			case 4:
				exit(0);
				break;
		}
	}
}
