#include <stdio.h>
void main()
{
    int n;
    printf("enter a length\n");
    scanf("%d", &n);
    int arr[n], i, j;
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("array is print");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("sorted array");
    // for(i=0;i<=n-1;i++){
    //     for(j=0;j<=n-1;j++){
    //         if(arr[j]>arr[i]){
    //             int temp=arr[j];
    //             arr[j]=arr[i];
    //             arr[i]=temp;
    //         }
    //     }
    // }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("array is print");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", arr[i]);
    }
    int low = 0, mid, high = n - 1, flag = 0, element;
    printf("enter a element you want to search\n");
    scanf("%d", &element);
    while (low <= high)
    {
        mid = ((low + high) / 2);
        if (element < arr[mid])
        {
            high = mid - 1;
        }
        else if (element > arr[mid])
        {
            low = mid + 1;
        }
        else if (arr[mid] == element)
        {
            flag = 1;
            printf("element found");
            break;
        }
    }
    if (flag == 0)
    {
        printf("not found");
    }
}