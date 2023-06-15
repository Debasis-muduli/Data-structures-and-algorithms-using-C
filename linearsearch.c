#include <stdio.h>

void input(int arr[], int n);
void display(int arr[], int n);
int search(int arr[], int n);

int main() {
    int a[50], n, result;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    input(a, n);
    display(a, n);
    result = search(a, n);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}

void input(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Enter element[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int n) {
    int i;

    printf("Elements in the array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int search(int arr[], int n) {
    int num, i;

    printf("Enter the element you want to search: ");
    scanf("%d", &num);

    for (i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i;
        }
    }

    return -1; // Element not found
}
