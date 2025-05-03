#include <stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[], int low, int high){
    int start=low,end=high;
    int pivot=arr[low];
    while (start<end)
    {
    while(arr[start]<=pivot){
        start++;
    }
    while(arr[end]>pivot){
        end--;
    }
    if(start<end){
        swap(&arr[start],&arr[end]);
    }
    }
        swap(&arr[end],&arr[low]);

    return end;
}

void quickSort(int arr[], int low, int high)
{
    if(low<high){
        int loc=partition(arr,low,high);
        quickSort(arr,low,loc-1);
        quickSort(arr,loc+1,high);
    }
}

int main()
{
    int arr3[] = {64, 25, 12, 22,11,0,1,3333,34,23,120};
    int n = sizeof(arr3) / sizeof(arr3[0]);
    quickSort(arr3, 0, n-1
    );
    for (int i = 0; i < n; i++)
        printf("%d ", arr3[i]);
    return 0;
}
