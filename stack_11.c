#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"stack_11.h"
#include"functions.h"
#include <math.h>

// stack to convert infix to postfix
 
int stackTop(struct Stack* sp){
    return sp->arr[sp->top];
}
 
int isEMPTY(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFULL(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void PUSH(struct Stack* ptr, char val){
    if(isFULL(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char POP(struct Stack* ptr){
    if(isEMPTY(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

// int isOperator(char ch){

//     return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
// }

// int isOperand(char ch){
//     return ('0'<=ch && ch<='9');
// }


char* infixToPostfix(char* infix){

    struct Stack * sp = (struct Stack *) malloc(sizeof(struct Stack));
    sp->size = 10; 
    sp->top = -1;

    // since each element of array is a char hence during malloc we write
    // (char *)

    sp->arr = (char *) malloc(sp->size * sizeof(char));

    // +1 is done to include null character

    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));

    int i=0; // Track infix traversal

    int j = 0; // Track postfix addition 

    while (infix[i]!='\0')
    {
        if (infix[i] == '('){
            PUSH(sp,infix[i]);
            i++;
        }
        else if (infix[i] == ')'){

            while((stackTop(sp))!='('){

                postfix[j] = POP(sp);
                j++;

            }

            POP(sp); // to remove ')'

            i++;
        }
        if(isOperand(infix[i])){
            
            /*to differentiate between say 354 and 459
            use a while loop and insert 354 in postfix then insert a space
            and now insert 459 into the array
            */ 

            

            do{

            

            postfix[j] = infix[i];
            j++;
            i++;
            }
            while(isOperand(infix[i])); 
            postfix[j]=' ';
            j++;
           
        }
        else if(isOperator(infix[i])){

            
            if(precedence(infix[i])> precedence(stackTop(sp))){
                PUSH(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = POP(sp);
                j++;
            }
        }

        else i++; // simply ignore others chars like special symbols
    }
    while (!isEMPTY(sp))    
    {
        postfix[j] = POP(sp);
        j++;
    }
    postfix[j] = '\0'; // character arrays in C are always terminated by null char
    return postfix;
}

