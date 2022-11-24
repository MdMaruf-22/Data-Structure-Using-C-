#include<stdio.h>
#define N 1000
int stack[N];
int top=-1;
int isFull(){
    if(top==N-1) return 1;
    else return 0;
}
int isEmpty(){
    if(top==-1) return 1;
    else return 0;
}
int push(int data){
    if(!isFull()){
        top=top+1;
        stack[top]=data;
    }
    else printf("Coudnt push!!");
}
int pop(){
    int data;
    if(!isEmpty()){
        data=stack[top];
        top-=1;
        return data;
    }
    else printf("Stack is empty!!");
}
int show(){
    while(!isEmpty()){
        int data=pop();
        printf("%d ",data);
    }
    printf("\n");
}
int main(){
    int op;
    while(op!=3){
        printf("What operation you want to do?\n1.Insert\n2.Delete\n3.Show\n4.Exit\n");
        scanf("%d",&op);
        if(op==1){
            printf("How many data you want to insert?: ");
            int ele,data;
            scanf("%d",&ele);
            for(int i=0;i<ele;i++){
                printf("Enter a elemnt: ");
                scanf("%d",&data);
                push(data);
            }
            printf("After inserting:\n");
            show();
        }
        else if(op==2){
            pop();
            printf("After deleting: \n");
            show();
        }
        else if(op==3){
            show();
        }
        else break;
    }
}