#include <stdio.h>
void main()
{
    int n, i;
    printf("enter a length of array\n");
    scanf("%d", &n);
    int arr1[n];
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", arr1[i]);
    }
    int ele, flag = 0;
    printf("enter a element you want to scarch\n");
    scanf("%d", &ele);
    for (i = 0; i <= n - 1; i++)
    {
        if (arr1[i] == ele)
        {
            flag++;
            printf("element is found %d\n", arr1[i]);
        }
    }
    if (flag == 0)
    {
        printf("not found\n");
    }
}