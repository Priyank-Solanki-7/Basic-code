#include<stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Temporary arrays to hold the data
    int leftArr[n1], rightArr[n2];

    // Copy data into the temporary arrays
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    // Copy the remaining elements of rightArr[], if any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort
void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2; // find the mid point

        // Sort the first part
        mergesort(arr, left, mid);

        // Sort the second part
        mergesort(arr, mid + 1, right);

        // Merge the sorted part
        merge(arr, left, mid, right);
    }
}


void main(){
    int n;
    printf("enter a array length\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter a array elemants:\n");
    int i;
    for(i=0;i<=n-1;i++){
        scanf("%d",&arr[i]);
    }
    printf("print array elemants");
    for(i=0;i<=n-1;i++){
        printf("%d ",arr[i]);
    }
    mergesort(arr,0,n-1); 
}