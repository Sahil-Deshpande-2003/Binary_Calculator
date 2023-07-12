#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>

#include"functions.h"



#include"stack_11.h"

int main(){

    while(1){

    char infix[250]={'\0'};

    char arr[250]={'\0'};

    printf("Enter e to escape\n");



    gets(infix);





     int i = 0;
    int j = 0;
    while(i<strlen(infix)){

        if (infix[i]!=' '){

          arr[j++] = infix[i];  
        }

        i++;
    }



    if (arr[0] == 'e' && strlen(arr) == 1) exit(0);
    

    
  

   

    
    char *postfix = infixToPostfix(arr);



    stack s;

    init_stack(&s,100);

    node*head = evaluate(postfix,s);

    printf("Result:");

    print_LL(head);

    printf("\n");

    }




















    return 0;
}
