#include<stdio.h>

void triplet(int[10][3], int, int, int);
void transpose(int[10][3], int[10][3]);
void display(int[10][3]);

void main() {
    int a[10][3], row, col, n, b[10][3];
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &row, &col);
    printf("Enter the number of non-zero values: ");
    scanf("%d", &n);
    triplet(a, row, col, n);
    transpose(a, b);
    display(b);
}

void triplet(int a[10][3], int row, int col, int n) {
    int i, j;
    a[0][0] = row;
    a[0][1] = col;
    a[0][2] = n;
    printf("Enter the elements of the triplet matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("The entered triplet matrix is:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void transpose(int a[10][3], int b[10][3]) {
    int i, j, k, m;
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];
    k = 1;
    m = a[0][2];
    for (i = 0; i < a[0][1]; i++) {
        for (j = 1; j <= m; j++) {
            if (i == a[j][1]) {
                b[k][0] = i;
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }
        }
    }
}

void display(int b[10][3]) {
    int i, j;
    printf("The transposed matrix is:\n");
    for (i = 0; i <= b[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}
