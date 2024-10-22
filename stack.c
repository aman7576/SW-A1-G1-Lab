#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int top;
    char* arr;
    int capacity;
}Stack;

int isEmpty(Stack* s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
void initStack(Stack* s,int n){
    s->top=-1;
    s->arr=(char*)malloc(n*sizeof(char));
    s->capacity=n;
}

void pushStack(Stack* s,char x){
    if(s->top==s->capacity-1){
        printf("overflow!\n");
        return;
    }
    s->top++;
    s->arr[s->top]=x;       
}

char popStack(Stack* s){
    if(isEmpty(s)){
        printf("underflow!\n");
        return -1;
    }

    int ans=s->arr[s->top];
    s->top--;
    return ans;

}
char topStack(Stack* s){
    if(isEmpty(s)){
        printf("underflow!\n");
        return -1;
    }

    return s->arr[s->top];
}

int matchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int paranthesisChecker(Stack* s, char* str, int n) {
    
    if (n % 2 != 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        char elem = str[i];
      
        if (elem == '(' || elem == '{' || elem == '[') {
            pushStack(s, elem);
        }
       
        else if (elem == ')' || elem == '}' || elem == ']') {
            if (isEmpty(s)) {
                return 0; 
            }
            char topElem = popStack(s);
            if (!matchingPair(topElem, elem)) {
                return 0; 
            }
        }
    }

   
    return isEmpty(s);
}


int main(){

    Stack* s1 = (Stack*)malloc(sizeof(Stack));  
    int n1;
    printf("Enter size of stack: ");
    scanf("%d", &n1);
    initStack(s1, n1);

    char ch;
    char ch1;
    for (int i = 0; i < n1; i++) {
        printf("Enter character: ");
        getchar();  
        scanf("%c", &ch);
        pushStack(s1, ch);
        
        printf("If you want to add more, press 'y', else 'n': ");
        getchar();  
        scanf("%c", &ch1);
        if (ch1 == 'y') {
            continue;
        } else {
            break;
        }
    }
    
    printf("top of the stack is %c\n",topStack(s1));
    free(s1->arr);


    Stack* s;
    s = (Stack*)malloc(sizeof(Stack));
    char* str;
    int n;
    printf("enter size of string:");
    scanf("%d",&n);
    str=(char*)malloc((n+1)*sizeof(char));
    printf("enter string to check:");
    getchar();
    gets(str);
    initStack(s,n);
    if (paranthesisChecker(s, str, n)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    free(s->arr);
    free(str);
}