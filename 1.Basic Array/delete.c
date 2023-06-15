#include <stdio.h>

void input(int arr[], int n);
void display(int[], int n);
void deleteElement(int a[], int *n);

int main() {
    int a[50], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    input(a, n);
    printf("\n");

    display(a, n);
    printf("\n");

    deleteElement(a, &n);
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

void deleteElement(int a[], int *n) {
    int pos = -1, num;
    printf("Enter the number you want to delete: ");
    scanf("%d", &num);

    for (int i = 0; i < *n; i++) {
        if (a[i] == num) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Element not found\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }

    (*n)--;
    printf("Array after deletion:\n");
    display(a, *n);
}
