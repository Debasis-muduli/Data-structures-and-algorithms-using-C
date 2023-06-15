#include<stdio.h>
#include<stdlib.h>

#define max 10
int q[max];
int f=-1,r=-1;
void dequeue();
void enqueue();
void display();

int main(){
int ch;
printf("enter choice\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
while(1){
printf("Enter choice");
scanf("%d",&ch);
switch(ch){
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
printf("\nThank you\n");
exit(0);
}
}
}

void dequeue(){
int item;
if(f==-1){
printf("\nqueue is underflow");
return;
}
else if(f==r){
item=q[f];
printf("deleted item =%d\n",item);
f=r=-1;
}
else{
item=q[f];
printf("The deleted item =%d\n",item);
f=f+1;
}
}

void enqueue(){
int item;
printf("\nenter the number: ");
scanf("%d",&item);
if(r==max-1){
printf("\nOverflow state");
return;
}
else if(f==-1&&r==-1){
f=0;
r=0;
q[r]=item;
}
else{
r=r+1;
q[r]=item;
}
}

void display(){
int i;
if(f==-1){
printf("\nqueue is underflow");
}
else{
for(i=f;i<=r;i++){
printf("%d\t",q[i]);
}
printf("\n");
}
}
