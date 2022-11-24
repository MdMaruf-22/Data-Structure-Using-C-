#include<stdio.h>
int swap(int* x,int* y){
    int t=*x;
    *x=*y;
    *y=t;
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int loc=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            loc++;
            swap(&arr[loc],&arr[j]);
        }
    }
    swap(&arr[loc+1],&arr[high]);
    return (loc+1);
}
void quick_sort(int arr[],int low,int high){
    int stack[high-low+1];
    int top=-1;
    stack[++top]=low;
    stack[++top]=high;
    while(top>=0){
        high=stack[top--];
        low=stack[top--];
        int index=partition(arr,low,high);
        if(index-1>low){
            stack[++top]=low;
            stack[++top]=index-1;
        }
        if(index+1<high){
            stack[++top]=index+1;
            stack[++top]=high;
        }
    }
}
int main(){
    int n;scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}