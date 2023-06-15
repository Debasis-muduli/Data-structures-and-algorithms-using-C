#include <stdio.h>

void input(int arr[], int n);
void display(int[], int n);
void insert(int a[], int *n);

int main() {
    int a[50], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    input(a, n);
    printf("\n");

    display(a, n);
    printf("\n");

    insert(a, &n);
    printf("\n");

    return 0;
}

void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n) {
    printf("Elements in the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void insert(int a[], int *n) {
    int pos, num;
    printf("Enter the number and position you want to insert: ");
    scanf("%d %d", &num, &pos);

    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position\n");
        return;
    }

    (*n)++;
    for (int i = *n - 1; i >= pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos - 1] = num;

    printf("Array after insertion:\n");
    display(a, *n);
}
