#include<stdio.h>

void push(char stack[], char ch, int* top){
   if(*top==100) printf("Array Full\n");
   else{
       stack[*top]=ch;
       *top+=1;
   }
}

void pop(char stack[], int* top){
   if(*top==0) printf("Array Empty\n");
   else{
       *top-=1;
   }
}

void parenthesisChecker(char expr[]){
   char stack[100];
   int top=0;

   for(int i=0;i<100;i++){
       if(expr[i]=='('||expr[i]=='['||expr[i]=='{'){
           push(stack, expr[i], &top);
       }
       else if(expr[i]==')'){
           if(top!=0){
               if(stack[top-1]=='('){
                   pop(stack, &top);
               }
               else{
                  push(stack, expr[i], &top);
               }
           }
       }
       else if(expr[i]==']'){
           if(top!=0){
               if(stack[top-1]=='['){
                   pop(stack, &top);
               }
               else{
                  push(stack, expr[i], &top);
               }
           }
       }
       else if(expr[i]=='}'){
           if(top!=0){
               if(stack[top-1]=='{'){
                   pop(stack, &top);
               }
               else{
                  push(stack, expr[i], &top);
               }
           }
       }
       else{
           continue;
       }
   }
   if(top==0){
       printf("\nParenthesis in the Expression are balanced\n");
   }
   else{
       printf("\nParenthesis in the Expression are not balanced\n");
   }
}

int main(){
   char expr[]="[(A + B) - C * (D / E)] + F";
   printf("\n%s", expr);
   parenthesisChecker(expr);
   return 0;
}