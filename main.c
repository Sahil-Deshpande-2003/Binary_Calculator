#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>

#include"functions.h"



#include"stack_11.h"

// User provides a infix expression, covert it to postfix and then evaluate postfix

int main(){

    while(1){

    char infix[250]={'\0'};

    char arr[250]={'\0'}; // remove spaces from infix and store them into arr

    printf("Enter e to escape\n");



    gets(infix); // accept a string with spaces





     int i = 0;
    int j = 0;
    while(i<strlen(infix)){

        // remove all spaces

        if (infix[i]!=' '){

          arr[j++] = infix[i];  
        }

        i++;
    }



    if (arr[0] == 'e' && strlen(arr) == 1) exit(0); // user entered 'e'
    

    
  

   

    
    char *postfix = infixToPostfix(arr); // convert infixToPostfix



    stack s;

    init_stack(&s,100);

    node*head = evaluate(postfix,s); // evaluate postifix expression, it returns the final ans in the form of LL

    printf("Result:"); // result obtained is in the form of a LL

    print_LL(head);

    printf("\n");

    }




















    return 0;
}
