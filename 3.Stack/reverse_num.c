#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 50
int top=-1;
int stack[max];
int stack2[max];
int num1;
int num2=0;
void push(int[],int);
int pop(int []);
void display();
void reverse();
int main(){
	printf("Enter a number:");
	scanf("%d",&num1);
	reverse(num1);
	printf("The reversed number is :%d\n",num2);
	return 0;
}
void reverse(num1)
{
	int rem,count=0;
	int x,i;
	while(num1>0)
	{
		rem=num1%10;
		num1=num1/10;
		count++;
		push(stack,rem);
	}
	for(i=0;i<count;i++)
	{
		stack2[i]=stack[count-1-i];
	}	
	while(top>-1)
	{
		x=pop(stack2);
		num2=num2*10+x;
	}
}
void push(int ch[],int x){
	if(top==max-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		top++;
		ch[top]=x;
	}
}
int pop(int st[]){
	int n;
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		n=st[top];
		top--;
		return n;
	}
}
