#include <stdio.h>
#define size 5

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp=0,min=i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        
    }
    
}

void main()
{
    int arr[size] = {5, 2, 4, 1, 3}  ;
    int x, found = 0;
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    selectionsort(arr, size);
    printf("sorted array:\n");
     for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    printf("number to search:");
    scanf("%d", &x);

    int beg = 0, end = size - 1, mid;

    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == x)
        {
            printf("elemnt found at post: %d \n", mid + 1);
            found = 1;
            break;
        }
        else if (x < mid)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }
    if (beg > end && found == 0)
    {
        printf("elemnt not found");
    }
}