#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
int num[100];
char op[100];
int topNum=-1,topOp=-1;
void pushNum(int data){
    num[++topNum]=data;
}
void pushChar(char ch){
    op[++topOp]=ch;
}
int popNum(){
    return num[topNum--];
}
char popChar(){
    return op[topOp--];
}
bool isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^') return true;
    return false;
}
int precedence(char ch){
    if(ch=='+'||ch=='-') return 1;
    else if(ch=='*') return 2;
    else if(ch=='/') return 2;
    else if(ch=='^')return 3;
    else return -1;
}
int pow(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i++) ans*=x;
    return ans;
}
int infixEvaluation(){
    int a=popNum();
    int b=popNum();
    char ch=popChar();
    if(ch=='+') return a+b;
    else if(ch=='-') return b-a;
    else if(ch=='*') return a*b;
    else if(ch=='/') return b/a;
    else if(ch=='^') return pow(b,a);
}
int eval(char exp[]){
    for(int i=0;exp[i]!='\0';i++){
        char ch=exp[i];
        int val;
        if(isdigit(ch)!=0){
            val=0;
            while(isdigit(ch)){
                val=val*10+(ch-'0');
                i++;
                if(i<strlen(exp)) ch=exp[i];
                else break;
            }
            i--;
            pushNum(val);
        }
        else if(ch=='(') pushChar(ch);
        else if(ch==')'){
            while(op[topOp]!='('){
                int ans=infixEvaluation();
                pushNum(ans);
            }
            popChar();
        }
        else if(isOperator(ch)){
            while(topOp!=-1 && precedence(ch)<=precedence(op[topOp])){
                int output=infixEvaluation();
                pushNum(output);
            }
            pushChar(ch);
        }
    }
    while(topOp!=-1){
        int ans=infixEvaluation();
        pushNum(ans);
    }
    return popNum();
}
int main(){
    char exp[100];
    gets(exp);
    printf("%d",eval(exp));
}
