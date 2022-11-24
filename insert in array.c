#include<stdio.h>
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
    int index,new_number;
    printf("In which position you want to insert the number?\n");
    scanf("%d",&index);
    printf("Which number you want to insert?\n");
    scanf("%d",&new_number);
    size++;
    for(int i=size;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=new_number;
    for(int i=1;i<=size;i++) printf("%d ",arr[i]);
}