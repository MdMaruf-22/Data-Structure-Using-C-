#include<stdio.h>
int binary_search(int arr[],int size,int number_to_find){
    int low=1,high=size,mid;
    while(high-low>1){
        mid=(high+low)/2;
        if(arr[mid]<number_to_find) low=mid+1;
        else high=mid;
    }
    if(number_to_find==arr[low]) return low;
    else if(number_to_find==arr[high]) return high; 
}
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for(int i=1;i<=size;i++){
        scanf("%d",&arr[i]);
    }
    int remove;
    printf("Which number you want to remove?\n");
    scanf("%d",&remove);
    int index=binary_search(arr,size,remove);
    for(int i=index;i<=size;i++){
        arr[i]=arr[i+1];
    }
    size--;
    for(int i=1;i<=size;i++){
        printf("%d ",arr[i]);
    }
}