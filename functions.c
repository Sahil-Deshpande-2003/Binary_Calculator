#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>

#include"functions.h"


#include"stack_11.h"

int isOperator(char ch){

    return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
}

int isOperand(char ch){
    return ('0'<=ch && ch<='9');
}

void print_LL(node *head){

    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

node* ReverseLL(node*head){
    if (!head || !head->next) return head;
    node*temp = head->next;
    node*smallhead = ReverseLL(head->next);
    temp->next = head;
    head->next = NULL;
    return smallhead;

}

int length(node *head){
    if (!head) return 0;
    return 1+length(head->next);
}






    node* add(node* first, node* second) {
        int carry = 0;
        
        node* ansHead = NULL;
        node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
    

                node*newnode = (node*)malloc(sizeof(node));
                newnode->data = digit;
                newnode->next = NULL;

                if (!ansHead){

                    ansHead = newnode;
                    ansTail = newnode;
                }
                else{
                    ansTail->next = newnode;
                    ansTail = newnode;
                }


          

            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;
    }



    node* addTwoLists(node* first, node* second)
    {
        
        if (!first) return second;
        if (!second) return first;
        
        

        if (first->data<0){

            node*temp1 = first;
            node*temp2 = second;
         
            temp1->data*=-1;
           node*ans = subtract_LL(temp1,temp2);
           ans->data*=-1;
           return ans;
        }
      



        
        first = ReverseLL(first);

        second = ReverseLL(second);


        node* ans = add(first, second);

        ans = ReverseLL(ans);

        first = ReverseLL(first);        

        second = ReverseLL(second);        
        
        return ans;
    }


node* subtract_LL(node *head1,node*head2){

  if (!head1 && !head2) return NULL;
  if (!head2) return head1;
  if (!head1){
    head2->data*=-1;
    return head2;
  }

   

    while(!head1->data && head1->next) head1 = head1->next;
    while(!head2->data && head2->next) head2 = head2->next;
	

	
    node *anshead = NULL;
    node *anstail = NULL;
	
	if (head1->data<0){
	
	node*temp1 = head1;
	node*temp2 = head2;
	temp1->data*=-1;
	anshead = addTwoLists(temp1,temp2);
	anshead->data*=-1;
	return anshead;
	}

     int len1 = length(head1);
    int len2 = length(head2);

    int flag = 1;

    if (len1<len2) flag = 0;

    else if (len1 == len2){

         node*a=head1;
         node*b=head2;

         while(a && b){
            if (a->data < b->data){
            flag = 0;
            break;
             }
             
             else if(a->data>b->data){
             		break;
             	}

        a = a->next;
        b = b->next;
    }
    }


    while(len1!=len2){

        node*newnode = (node*)malloc(sizeof(node));
        newnode->data = 0;


        if (len1<len2){

            newnode->next = head1;
            head1 = newnode;
            len1++;

        }

        else{

            newnode->next = head2;
            head2 = newnode;
            len2++;

        }
    }



   

    
    if (!flag){

        node*c = head1;
        head1 = head2;
        head2  = c;
    }





    head1 = ReverseLL(head1);

    head2 = ReverseLL(head2);





    




    node*temp1 = head1;
    node*temp2 = head2;
    int ans = 0;


    while(temp1 || temp2){

 

        if (temp1->data<temp2->data){

            if (temp1){

                temp1->data+=10;
                node*temp = temp1->next;
    

                //while(temp && temp->data==0){
                  //  temp = temp->next;
                //}
                //if (temp){
                  //  temp->data--;
                //}
                //node *store = temp1->next;
                //while(store!=temp){

                    //store->data+=9;
                    
                  //  store = store->next;
                //}
                
                 while(temp && temp->data==0){
                    temp = temp->next;
                    temp->data+=9;
                }
                if (temp){
                    temp->data--;
                }
                



            }

        }


  
        ans=(temp1->data - temp2->data);
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = ans;
        newnode->next = NULL;
  
        if (!anshead){
            anshead = newnode;
            anstail = newnode;
        }
        else{
            anstail->next = newnode;
            anstail = newnode;
        }
  

        

        temp1 = temp1->next;    
        temp2 = temp2->next;    



    }

    


    node*s = ReverseLL(anshead);

    while(s->data == 0 && s->next) s = s->next;

    // && s->next to handle the case 22-22 so that it gives 0

    if (!flag && s){

        s->data*=-1;

        flag = 1;

    }

    return s;



}


// multiply LL

node* multiplyLL(node *head1, node *head2){

   

    int flag = 1;

    if (!head1 || !head2) return NULL;





    node*head = NULL;
    node*tail = NULL;

    node*newhead1 = ReverseLL(head1);
    node*newhead2 = ReverseLL(head2);

    int ct = 0; // this is for that cross

    int multiply_by = 0;
    int carry = 0;

    while(newhead2){

        multiply_by = newhead2->data;
        carry = 0;


    

    node*temp = newhead1;
    node*temphead = NULL;

    node*temptail = NULL;

    while(temp){


int val = (temp->data)*(multiply_by) + carry;
        int data = val%10;
        carry = val/10;

        node*newnode = (node*)malloc(sizeof(node));
        newnode->data = data;
        newnode->next = NULL;

        if (!temphead){
            temphead = newnode;
            temptail = newnode;
        }
        else{
            temptail->next = newnode;
            temptail = newnode;
        }

        if (!(temp->next) && carry){

        node*ansnode = (node*)malloc(sizeof(node));
        ansnode->data = carry;
        ansnode->next = NULL;

        if (!temphead){
            temphead = ansnode;
            temptail = ansnode;
        }
        else{
            temptail->next = ansnode;
            temptail = ansnode;
        }

        }

        temp = temp->next;
    }


    int store = ct;

    while(store){

        node*nn = (node*)malloc(sizeof(node));
        nn->data = 0;
        nn->next = temphead;
        temphead = nn;
        

        store--;
    }




   

    temphead = ReverseLL(temphead);

	

    head = addTwoLists(head,temphead);




	
    newhead2 = newhead2->next;
    

    

    ct++;
    
    }    

    if (!flag) head->data*=-1;

    return head;

}


// divide LL




node*copy_LL(node *head){

    node*h = NULL;
    node*t = NULL;
    node*temp = head;

    while(temp){

      node*newnode = (node*)malloc(sizeof(node));
      newnode->data = temp->data;
      newnode->next = NULL;

        if (!h){
            h = newnode;
            t = newnode;
        }
        else{
            t->next = newnode;
            t = newnode;
        }

        temp = temp->next;
        
    }

    return h;

}



char* check(node*head1,node*head2){


    int len2 = length(head2);
    int len1 = length(head1);




    if (len2 > len1){


        return "LL2";
    }

    else if (len1>len2){


        return "LL1";
    }




        node*a = head1;
        node*b = head2;

        char* val = NULL;

        while(a && b){

            if (a->data < b->data){
           
                
                return "LL2";
                
            }

            else if (a->data > b->data){
      

                return "LL1";
            
            }
            a = a->next;
            b = b->next;
        }    



     return "Equal";
       

   

    


}


node* divide(node*head1, node*head2){

  



    if (!head1 || !head2) return NULL;

    if (!(head2->data)){
        printf("Zero Division Error\n");
        exit(0);
        return NULL;
    }
    

    char *str = check(head1,head2);




    node*anshead = NULL;

    node*counthead = NULL;

    node*dummy = copy_LL(head2);




    if (str == "LL2"){



        node*newnode = (node*)malloc(sizeof(node));
        newnode->data = 0;
        newnode->next = NULL;
        return newnode;
    }

    else if (str == "Equal"){



         node*newnode = (node*)malloc(sizeof(node));
        newnode->data = 1;
        newnode->next = NULL;
        return newnode;

    }
    

    else {


      




        do{
            



            head2 = addTwoLists(head2,dummy);


            node*tp=(node*)malloc(sizeof(node));
            tp->data=1;
            tp->next=NULL;

            counthead=addTwoLists(counthead,tp);



            if (!anshead){


                node*newnode = (node*)malloc(sizeof(node));
                newnode->data = 1;
                newnode->next = NULL;
                anshead = newnode;
       
            }

            else{

             

                anshead->data++;


            }

        


        
        }

    while(check(head1,head2)!="LL2");

    }

    
        


           
    return counthead;

        
    }
    

  




