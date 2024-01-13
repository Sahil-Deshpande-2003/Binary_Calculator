
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

    // s is a stack of node pointers

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

    // delete LL kept at top index, you can access it using head pointer

    if (isEmpty(*s)) return NULL;

   node*head = s->arr[s->top];

   s->arr[s->top] = NULL; // head pointer which was initially pointing to

// the 1st node of LL, now starts pointing to NULL, it means that LL

// is not present at top index

        
         
    // Eg [1,2,3] top was pointing to 3 now it should point to 2

   s->top--;



   return head; // return deleted element


    
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


            // Eg 3-5 =>(postfix)=> [35-] -> 
            /*
                Stack
                5
                3

            second_op = 5
            first_op = 3
            subtract_LL(first_op,second_op) means

            subtract_LL(3,5) = -2

            */
            

            node* second_op = pop(&s); // since stack is LIFO
      

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

            /*I need to use while loop since if no. = 354 I dont want
            stack to be

                4
                5
                3

            I want stack to be 354

            hence while char is operand keep addiing it to LL

            so LL is 3 -> 5 -> 4 and push this LL in the stack

            temphead points to the node with data 3
            

            */ 
            

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
        else i++; // neither operator nor operand, Eg its a special symbol like $ then ignore it and just increment i

        

        /* code */
    }

    return pop(&s); // final ans after evaluation of expression is kept
    // at the top of LL

    
}

