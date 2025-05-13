#include <stdio.h>
void insertionSort(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
    printf("\nsorted array\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
}
void main()
{
    int n, i;
    printf("enter a array length:\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter a array elements:\n");
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("print array elements:\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    insertionSort(arr, n);
}