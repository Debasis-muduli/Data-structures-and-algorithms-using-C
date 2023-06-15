#include<stdio.h>

void input(int arr[], int n);
void display(int [], int n);
void update(int [], int n);

void main() {
    int a[50], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    input(a, n);
    display(a, n);
    printf("Updated array is:\n");
    update(a, n);
    display(a, n);
}

void input(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter element[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n) {
    int i;
    printf("Elements in the array are: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void update(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        a[i] = a[i] * 10;
    }
}
