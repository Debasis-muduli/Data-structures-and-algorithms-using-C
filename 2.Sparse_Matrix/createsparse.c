#include<stdio.h>

void readmatrix(int[100][100], int, int);
void createsparse(int[100][100], int, int, int[100][3]);
void displaysparse(int[100][3], int);
void display(int[100][100], int, int);

void main() {
    int n, m;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);

    int a[n][m], s[100][3];
    readmatrix(a, n, m);
    printf("The matrix is:\n");
    display(a, n, m);
    printf("\n");
    createsparse(a, n, m, s);
}

void readmatrix(int a[100][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Enter element[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void createsparse(int a[100][100], int n, int m, int s[100][3]) {
    int i, j, k = 1;
    s[0][0] = n;
    s[0][1] = m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
        s[0][2] = k - 1;
    }
    printf("\n");
    displaysparse(s, k);
}

void displaysparse(int s[100][3], int k) {
    int i, j;
    printf("The triplet form is:\n");
    for (i = 0; i < k; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %d ", s[i][j]);
        }
        printf("\n");
    }
}

void display(int a[100][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
}
