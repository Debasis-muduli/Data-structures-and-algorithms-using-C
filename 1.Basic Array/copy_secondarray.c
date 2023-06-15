#include <stdio.h>

void input(int[], int);
void copy(int[], int[], int);
void display(int[], int);

int main() {
    int a[100], b[100], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    input(a, n);
    copy(a, b, n);
    display(b, n);

    return 0;
}

void input(int a[], int n) {
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void copy(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

void display(int a[], int n) {
    printf("The array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
