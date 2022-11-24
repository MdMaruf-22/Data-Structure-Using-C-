#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

int main(){
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    printf("Enter a value: ");
    scanf("%d",&item);
    ptr->data=item;
    ptr->next=head;
    head=ptr;
    while (ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    
}