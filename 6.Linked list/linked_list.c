#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;
struct node* temp;
struct node* p;

void ins_begin();
void display();
void ins_end();
void ins_locc();
void delete_begin();
void delete_last();
void delete_loc();

int main() {
	int ch;
	while (1) {
		printf("..Menu driven program..\n");
		printf("\n0.exit\n1.Insert at the beginning\n2.Display\n3.Insert at end\n4.Insert at any position\n5.Delete at beginning\n");
		printf("\n6.Delete from last\n7.Delete at any loc\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			ins_begin();
			break;
		case 2:
			display();
			break;
		case 3:
			ins_end();
			break;
		case 4:
			ins_locc();
			break;
		case 0:
			exit(0);
		case 5:
			delete_begin();
			break;
		case 6:
			delete_last();
			break;
		case 7:
			delete_loc();
			break;
		}
	}
}

void ins_begin() {
	int value;
	p = (struct node*)malloc(sizeof(struct node));
	if (p == NULL) {
		printf("No memory allocation");
		return;
	}
	else {
		printf("Enter the data: ");
		scanf("%d", &value);
		p->data = value;
		p->next = head;
		head = p;
	}
}

void ins_end() {
	int value;
	p = (struct node*)malloc(sizeof(struct node));
	if (p == NULL) {
		printf("No memory allocation\n");
		return;
	}
	else {
		printf("Enter the data: ");
		scanf("%d", &value);
		p->data = value;
		p->next = NULL;
		if (head == NULL) {
			head = p;
		}
		else {
			temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = p;
		}
	}
}

void ins_locc() {
	int i, loc, value;
	p = (struct node*)malloc(sizeof(struct node));
	if (p == NULL)
		printf("\nOverflow\n");
	else {
		printf("\nEnter element value: ");
		scanf("%d", &value);
		p->data = value;
		printf("Enter the location after which you want to insert: ");
		scanf("%d", &loc);
		temp = head;
		for (i = 1; i < loc; i++) {
			temp = temp->next;
			if (temp == NULL && loc != 0) {
				printf("\nCannot insert\n");
				return;
			}
		}
		p->next = temp->next;
		temp->next = p;
	}
}

void display() {
	struct node* p;
	p = head;
	if (p == NULL)
		printf("Nothing to print\n");
	else {
		printf("\nPrinting values\n\n");
		printf("Head->");
		while (p != NULL) {
			printf("%d->", p->data);
			p = p->next;
		}
		printf("Tail\n");
	}
}

void delete_begin() {
	struct node* p;
	if (head == NULL) {
		printf("\nList empty\n");
	}
	else {
		p = head;
		head = p->next;
		free(p);
	}
}

void delete_last() {
	struct node* p;
	struct node* p1;
	if (head == NULL) {
		printf("\nList is empty\n");
	}
	else if (head->next == NULL) {
		p = head;
		head = NULL;
		free(p);
		printf("\nOnly node of the list deleted\n");
	}
	else {
		p = head;
		while (p->next != NULL) {
			p1 = p;
			p = p->next;
		}
		p1->next = NULL;
		free(p);
	}
}

void delete_loc() {
	struct node* p;
	struct node* p1;
	int loc, i;
	printf("\nEnter the location of the node after which you want to perform deletion: ");
	scanf("%d", &loc);
	p = head;
	for (i = 0; i < loc; i++) {
		p1 = p;
		p = p->next;
		if (p == NULL) {
			printf("\nCan't Delete\n");
			return;
		}
	}
	p1->next = p->next;
	free(p);
	printf("\nDeleted node %d\n", loc);
}
