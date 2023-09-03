
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include"functions.h"



//     typedef struct stack{

//     node* *arr;

//     int size;



//    int top; 



// // } stack;

// typedef struct node{
//     int data;
//     struct node*next;
// }node;

// typedef struct stack{

//     node* *arr;

//     int size;



//    int top; 



// } stack;








void init_stack(stack *s, int size){

    s->arr = (node**)malloc(sizeof(node*) * size);
    // since each ele is of type node* we use node** before malloc acc. to syntax of malloc
    s->size = size;
    
    s->top = -1;
}

int isEmpty(stack s){

   return (s.top == -1); 
}

int isFull(stack s){

    return (s.top == (s.size - 1));
}

void push(stack *s,node*head){

    if (isFull(*s)) return;

        // Push char LL in stack
    s->top++;
    s->arr[s->top] = head;
    // stores the complete LL at the top index



    return;
        
}



node* pop(stack *s){

    if (isEmpty(*s)) return NULL;

   node*head = s->arr[s->top];

   s->arr[s->top] = NULL; 

 
   s->top--;



   return head;


    
}


// int isOperator(char ch){

//     return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
// }

// int isOperand(char ch){
//     return ('0'<=ch && ch<='9');
// }


// evaluate the postfix expression
// if the character is operand, create a node,create a temp LL, while the char is an operand
// push the node it into temp LL, and finally  push the temp LL into the stack
// and if the character is operator, pop 2 nodes from the stack and call appropriate function

node* evaluate(char postfix[], stack s){


    node*temp = NULL;
    int i = 0;
    while(i<strlen(postfix)){
    
    
        char ch  = postfix[i];

        if (isOperator(ch)){

            node* second_op = pop(&s);
      

            node* first_op = pop(&s);
    

            switch(ch){

                case('+'):


                    temp = addTwoLists(first_op,second_op);
                    

                    
                    break;


                case('-'):


                    temp = subtract_LL(first_op,second_op);
                    
                    break;


                case('/'):

       

                    temp = divide(first_op,second_op);

                    // printf("Printing temp\n");

                    // while(temp){
                    //     printf("%d ",temp->data);
                    //     printf("->");
                    //     temp=temp->next;
                    // }
                    // printf("\n");

                    break;


                case('*'):



                    temp = multiplyLL(first_op,second_op);
               
                    break;



                default:

                    
                    break;

                
            }

            push(&s,temp);


          

            



        i++;

        }


        else if (isOperand(ch)){
            int val = 0;
   
            node*temphead = NULL;
            node*temptail = NULL;

            do{

            val =  postfix[i]-'0';
            node*newnode = (node*)malloc(sizeof(node));
            newnode->data = val;
            newnode->next = NULL;
            if (!temphead){
                temphead = newnode;
                temptail = newnode;
            }
            else{
                temptail->next = newnode;
                temptail = newnode;
            }

            i++;

  
            }

            while(isOperand(postfix[i]));


            push(&s,temphead);

        }
        else i++;

        

        /* code */
    }

    return pop(&s);

    
}

