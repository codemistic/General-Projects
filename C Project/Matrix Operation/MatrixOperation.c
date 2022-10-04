#include <stdio.h>
void transpose(int m, int n, int arr[m][n])
{
    printf("\nTranspose of matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
}
void addition(int m, int n, int arr[m][n], int arr1[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j] + arr1[i][j]);
        }
        printf("\n");
    }
}
void subtraction(int m, int n, int arr[m][n], int arr1[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j] - arr1[i][j]);
        }
        printf("\n");
    }
}
void multiplication(int m, int n, int n1, int arr[m][n], int arr1[n][n1])
{
    int multi[m][n1];
    int sum;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum = sum + arr[i][k] * arr1[k][j];
                multi[i][j] = sum;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            printf("%d ", multi[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int m, n, m1, n1;
    printf("Enter the size of the first matrix:");
    scanf("%d%d", &m, &n);
    int arr[m][n];
    printf("\nEnter the elements of the first matrix\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Enter the size of the second matrix:");
    scanf("%d%d", &m1, &n1);
    int arr1[m1][n1];
    printf("\nEnter the elements of the second matrix\n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\nFIRST MATRIX\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\nSECOND MATRIX\n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    int input;
    printf("\nENTER WHICH MATRIX YOU WANT TO FIND THE TRANSPOSE(1 for first and 2 for second)\n");
    scanf("%d", &input);
    if (input == 1)
    {
        transpose(m, n, arr);
    }
    else
    {
        transpose(m1, n1, arr1);
    }
    printf("\nADDITION OF TWO MATRIX\n");
    if (m == m1 && n == n1)
    {
        addition(m, n, arr, arr1);
    }
    else
    {
        printf("\nTwo matrices don't have the same dimensions so addition not possible\n");
    }
    printf("\nSUBTRACTION OF TWO MATRIX\n");
    if (m == m1 && n == n1)
    {
        subtraction(m, n, arr, arr1);
    }
    else
    {
        printf("\nTwo matrices don't have the same dimensions so subtraction not possible\n");
    }
    printf("\nMATRIX MULTIPLICATION\n");
    if (n == m1)
    {
        multiplication(m, n, n1, arr, arr1);
    }
    else
    {
        printf("\nMatrix multiplication not possible\n");
    }

    return 0;
}
