#include<stdio.h>
int swap(int* x,int* y){
    int t=*x;
    *x=*y;
    *y=t;
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int loc=low-1;
    for(int i=low;i<=high-1;i++){
        if(arr[i]<pivot){
            loc++;
            swap(&arr[loc],&arr[i]);
        }
    }
    swap(&arr[loc+1],&arr[high]);
    return (loc+1);
}
void quicksort(int arr[],int low,int high){
    int lower[high-low+1],higher[high-low+1];
    int top1=-1,top2=-1;
    lower[++top1]=low;
    higher[++top2]=high;
    while(top1!=-1 && top2!=-1){
        low=lower[top1--];
        high=higher[top2--];
        int index=partition(arr,low,high);
        if(index-1>low){
            lower[++top1]=low;
            higher[++top2]=index-1;
        }
        if(index+1<high){
            lower[++top1]=index+1;
            higher[++top2]=high;
        }
    }
}
int main()
{
    int n;
    printf("How many elements?: ");
    scanf("%d",&n);
    printf("Enter array elements:");
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    quicksort(arr,0,n-1);
    printf("After sorting: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}
