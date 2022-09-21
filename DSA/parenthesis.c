

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define MAX 100

int top = -1;
char stack[MAX];

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

 
int isFull() {
   if(top == MAX)
      return 1;
   else
      return 0;
}

int pop() {
    int data;

    if(!isEmpty()) {
        data = stack[top];
        top = top - 1;   
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
        return 0;
    }
}

void push(char* a){
    if(!isFull()) {
        top = top + 1;   
        stack[top] = *a;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}

int match_char(char a, char b){
    if(a == '[' && b == ']'){
        return 1;
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '(' && b == ')'){
        return 1;
    }
    return 0;
}

int check_balanced(char* s){
    int i, temp;
    for(i =0; i < strlen(s); i++){
        if(s[i] == '[' || s[i] == '{' || s[i] == '('){
            push(&s[i]);
        }
        if(s[i] == ']' || s[i] == '}' || s[i] == ')'){
            if(isEmpty()){
                printf("Invalid expression: right brackets are more than left brackets");
                return 0;
            }else{
                temp = pop();
                if(!match_char(temp, s[i])) {
                    printf("Invalid expression: mismatched brackets");
                    return 0;
                }
            }
        }   
    }
    if(isEmpty()){
        printf("Brackets are well balanced.");
        return 1;
    }else{
        printf("Left brackets are more than the right brackets");
        return 0;
    }
}

int main() {
    char exprn[MAX];
    int balanced;
    printf("Enter the expression: ");
    gets(exprn);
    balanced = check_balanced(exprn);

    if(balanced == 1){
        printf("\nThe expression is valid.");
    }else{
        printf("\nThe expression is invalid.");
    }

    return 0;
}
