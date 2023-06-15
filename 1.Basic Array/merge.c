#include<stdio.h>

void input(int [], int);
void merge(int [], int, int[], int);
void display(int [], int);

void main() {
    int a[100], n, b[100], m;
    printf("Enter the number of elements for array 1: ");
    scanf("%d", &n);
    printf("Enter the number of elements for array 2: ");
    scanf("%d", &m);

    input(a, n);
    input(b, m);
    merge(a, n, b, m);
}

void input(int a[], int n) {
    int i;
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void merge(int a[], int n, int b[], int m) {
    int i, j, c[200];
    for (i = 0; i < n; i++) {
        c[i] = a[i];
    }
    for (i = n, j = 0; i < n + m; i++, j++) {
        c[i] = b[j];
    }
    display(c, n + m);
}

void display(int a[], int n) {
    int i;
    printf("The merged array is: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
