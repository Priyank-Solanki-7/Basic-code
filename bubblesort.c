// set PATH=%PATH%;C:\your\path\here
#include <stdio.h>
void main()
{
    int n, i, j;
    printf("enter a array length\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter a array\n");
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("your actual array\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", arr[i]);
    }
    // applay bubble sort
    int temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("sorted array:\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", arr[i]);
    }
}
