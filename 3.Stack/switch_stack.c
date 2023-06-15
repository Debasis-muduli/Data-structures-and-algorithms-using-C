#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 5

int top=-1;
int stack[max];
int data;
void push();
void pop();
bool isFull();
bool isEmpty();
void display();

int main(){
	int n;
	printf("\nenter 1 for push\n");
	printf("enter 2 for pop\n");
	printf("enter 3 for display\n");
	printf("Enter 4 for exit\n");
while(1){
	printf("\nEnter a number:");
	scanf("%d",&n);
	switch(n){
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
	}
}
return 0;

}

void push(){
	int x;
	if(isFull==1){
		printf("\nStack is full\n");
	}
	else{
		printf("\nEnter the data:");
		scanf("%d",&x);
		top++;
		stack[top]=x;
	}
}
void pop(){
	int n;
	if(top==-1){
		printf("\nStack is empty\n");
	}
	else{
		n=stack[top];
		top--;
		printf("\nThe number is %d\n",n);
	}
}
bool isFull(){
	if(top==max-1){
		return true;
	}
}
bool isEmpty(){
	if(top==-1){
		return true;
	}
}
void display(){
	int i;
	printf("The elements in stack is\n");
	for(i=top;i>=0;i--){
		printf("%d\n",stack[i]);
	}
}
