#include <stdio.h>
void selectionsort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
       int min=i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        
    }
    
}
void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (temp < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
            arr[j+1] = temp;
    }
}
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
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int arr3[] = {64, 25, 12, 22, 11};
    // selectionsort(arr1, 5);
    // insertionsort(arr2, 5);
    quickSort(arr3, 0, 4);
    // for (int i = 0; i < 5;i++)
    //     printf("%d ", arr1[i]);
    // printf("\n");
    // for (int i = 0; i < 5; i++)
    //     printf("%d ", arr2[i]);
    // printf("\n");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr3[i]);
    return 0;
}
