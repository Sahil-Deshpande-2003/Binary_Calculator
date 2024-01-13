typedef struct node{
    int data;
    struct node*next;
}node;

// all functions of functions.c are defined here


void print_LL(node *head);
node* ReverseLL(node*head);
int length(node *head);
node* add(node* first, node* second);
node* addTwoLists(node* first, node* second);
node* subtract_LL(node *head1,node*head2);
node* multiplyLL(node *head1, node *head2);
node*copy_LL(node *head);
char* check(node*head1,node*head2);
node* divide(node*head1, node*head2);





typedef struct stack{

    // implement stack using array and size should be provided during
    // initialization

    node* *arr; // each element of array is a pointer to a node

    int size;



   int top; // plays the role of indexing for the array



} stack;




void init_stack(stack *s, int size);
int isEmpty(stack s);
int isFull(stack s);
void push(stack *s,node*head);
node* pop(stack *s);
int isOperator(char ch);
char* infixToPostfix(char* infix);
int isOperand(char ch);
node* evaluate(char postfix[], stack s);


// typedef struct stack{

//     node* *arr;

//     int size;



//    int top; 



// } stack;

// struct Stack
// {
//     int size;
//     int top;
//     char *arr;
// };
