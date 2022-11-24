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
    
}