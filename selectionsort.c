#include <stdio.h>

void main()
{
    int n, i, j;

    printf("Enter the array length: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Your original array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int minj, temp;
    for (i = 0; i < n - 1; i++)
    {
        minj = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minj])
            {
                minj = j;
            }
        }
        temp = arr[minj];
        arr[minj] = arr[i];
        arr[i] = temp;
    }

    printf("Your sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}