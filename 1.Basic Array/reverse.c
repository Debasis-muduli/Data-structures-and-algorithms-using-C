#include<stdio.h>

void input(int [], int);
void reverse(int [], int);
void display(int [], int);

void main() {
    int a[100], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    input(a, n);
    reverse(a, n);
    display(a, n);
}

void input(int a[], int n) {
    int i;
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void reverse(int a[], int n) {
    int low = 0, high = n - 1, temp;
    while (low <= high) {
        temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        low++;
        high--;
    }
}

void display(int a[], int n) {
    int i;
    printf("The reversed array is: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
