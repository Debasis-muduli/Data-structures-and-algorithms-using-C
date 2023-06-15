#include<stdio.h>
#include<stdlib.h>

#define max 50

int queue[max];
int front = -1;
int rear = -1;

void enqueue(int num);
int dequeue();
void display();

int main() {
    int num, a, ch;
    printf("Enter 1. enqueue\n2. dequeue\n3. display\n4. exit\n");

    while (1) {
        printf("Enter a choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                enqueue(num);
                break;

            case 2:
                a = dequeue();
                printf("The dequeued element is %d\n", a);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;
        }
    }
}

void enqueue(int num) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = num;
    } else if ((rear + 1) % max == front) {
        printf("Queue is overflow\n");
    } else {
        rear = (rear + 1) % max;
        queue[rear] = num;
    }
}

int dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is underflow\n");
        return ;
    } else if (front == rear) {
        int dequeuedElement = queue[rear];
        front = -1;
        rear = -1;
        return dequeuedElement;
    } else {
        int dequeuedElement = queue[front];
        front = (front + 1) % max;
        return dequeuedElement;
    }
}

void display() {
    int i = front;

    if (front == -1) {
        printf("The circular queue is empty!\n");
        return;
    } else if (front <= rear) {
        printf("\n");
        while (i <= rear) {
            printf("%d\n", queue[i++]);
        }
    } else {
        printf("\n");
        while (i < max) {
            printf("%d\n", queue[i++]);
        }
        i = 0;
        while (i <= rear) {
            printf("%d\n", queue[i++]);
        }
    }
}
