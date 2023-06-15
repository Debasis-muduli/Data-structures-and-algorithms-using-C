#include<stdio.h>

void readtriplet(int [100][3], int);
void creatematrix(int[100][3], int, int, int);
void displaytriplet(int[100][3], int);
void displaymatrix(int[100][100], int, int);

int main()
{
    int k;
    printf("Enter the number of values: ");
    scanf("%d", &k);
    int t[100][3];
    readtriplet(t, k);
    return 0;
}

void readtriplet(int t[100][3], int k)
{
    int i, j, r, c;
    printf("Enter the elements:\n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &t[i][j]);
        }
    }
    r = t[0][0];
    c = t[0][1];
    creatematrix(t, r, c, k);
}

void displaymatrix(int a[100][100], int r, int c)
{
    int i, j;
    printf("The sparse matrix is:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void displaytriplet(int t[100][3], int k)
{
    int i, j;
    printf("The triplet matrix is:\n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }
}

void creatematrix(int t[100][3], int r, int c, int k)
{
    int i, j, a[100][100], l = 1;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            a[i][j] = 0;
        }
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (t[l][0] == i && t[l][1] == j)
            {
                a[i][j] = t[l][2];
                l++;
            }
        }
    }
    displaytriplet(t, k);
    displaymatrix(a, r, c);
}
