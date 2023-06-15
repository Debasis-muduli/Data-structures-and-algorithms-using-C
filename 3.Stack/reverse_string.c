#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 50

int top=-1;
char stack[max];
char str1[max];
char str2[max];
void push(char[],char);
char pop(char []);
void display();

int main(){
	printf("Enter a strting:");
	scanf("%s",str1);
	reverse();
	printf("The reversed string is :%s\n",str2);
	return 0;
}
void reverse(){
	int i;
	char s;
	for(i=0;str1[i]!='\0';i++){
		s=str1[i];
		push(stack,s);
	}	
	for(i=0;str1[i]!='\0';i++){
		str2[i]=pop(stack);
	}
}

void push(char ch[],char x){
	if(top==max-1){
		printf("Stack is full\n");
	}
	else{
		top++;
		ch[top]=x;
	}
}
char pop(char st[]){
	char n;
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		n=st[top];
		top--;
		return n;
	}
}
