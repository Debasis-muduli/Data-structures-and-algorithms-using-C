#include <stdio.h>

void readtriplet(int t[100][3]);
void createsparse(int t[100][3], int s[100][100]);
void display(int s[100][100], int rows, int columns);
void displaytriplet(int t[100][3], int num);

int main()
{
    int t[100][3];
    int s[100][100];
    readtriplet(t);
    createsparse(t, s);
    return 0;
}

void readtriplet(int t[100][3])
{
    int num, i, j;
    int rows, columns;
    printf("Enter the number of rows and columns:\n");
    scanf("%d %d", &rows, &columns);
    printf("Enter the number of non-zero values:\n");
    scanf("%d", &num);
    t[0][0] = rows;
    t[0][1] = columns;
    t[0][2] = num;
    for (i = 1; i <= num; i++)
    {
        printf("Enter the row, column, and value:\n");
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &t[i][j]);
        }
        printf("\n");
    }
    displaytriplet(t, num);
    printf("\n");
}

void createsparse(int t[100][3], int s[100][100])
{
    int i, j, k = 1;
    int rows = t[0][0];
    int columns = t[0][1];
    int value = t[0][2];
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            s[i][j] = 0;
        }
    }
    for (i = 1; i <= value; i++)
    {
        int row = t[i][0];
        int col = t[i][1];
        int val = t[i][2];
        s[row][col] = val;
    }
    display(s, rows, columns);
}

void display(int s[100][100], int rows, int columns)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
}

void displaytriplet(int t[100][3], int num)
{
    int i, j;
    for (i = 0; i <= num; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}
