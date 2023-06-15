#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 50
int top=-1;
int stack[max];
int num1;
void push(int[],int);
void pop(int []);
void binary(int x);
int main(){
	printf("Enter a number:");
	scanf("%d",&num1);
	printf("The num binary value is:");
	binary(num1);
	printf("\n");
	return 0;
}
void binary(int x){
	while(x>0){
	int rem;
	rem=x%2;
	x=x/2;
	push(stack,rem);
	}
	while(top!=-1){
		pop(stack);
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
void pop(int st[]){
	int n;
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		n=st[top];
		top--;
		printf("%d",n);
	}
}