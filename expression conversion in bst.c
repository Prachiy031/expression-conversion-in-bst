/*
o/p:
Enter postfix expression:
ab+cde*-*f*g/


Operand: a
Operand Address: 0x564692006ac0Stack top:0x564692006ac0

Operand: b
Operand Address: 0x564692006ae0Stack top:0x564692006ae0

Operator: +
Operator Address: 0x564692006b00
Stack top:0x564692006b00

Operand: c
Operand Address: 0x564692006b20Stack top:0x564692006b20

Operand: d
Operand Address: 0x564692006b40Stack top:0x564692006b40

Operand: e
Operand Address: 0x564692006b60Stack top:0x564692006b60

Operator: *
Operator Address: 0x564692006b80
Stack top:0x564692006b80

Operator: -
Operator Address: 0x564692006ba0
Stack top:0x564692006ba0

Operator: *
Operator Address: 0x564692006bc0
Stack top:0x564692006bc0

Operand: f
Operand Address: 0x564692006be0Stack top:0x564692006be0

Operator: *
Operator Address: 0x564692006c00
Stack top:0x564692006c00

Operand: g
Operand Address: 0x564692006c20Stack top:0x564692006c20

Operator: /
Operator Address: 0x564692006c40
Stack top:0x564692006c40
Inorder Traversal is :
a + b * c - d * e * f / g 
*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct tree
{
  char data;
  struct tree *left,*right;
};

int top= - 1;
struct tree *stack[20];
struct tree *root1;


void push(struct tree *root)
{
    top = top+1;
    stack[top] = root;                             //opearands are push in stack
    printf("\nstack data %p",stack[top]);
}
struct tree *pop()
{
    return(stack[top--]);                   //if there is any operator found then first top two operands get popped out
}
void inorder(struct tree *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        if(root!=NULL)
        {
            inorder(root->left);                    //first traversed left part of tree then on right
        }
        printf("%c",root->data);                  //as soon as left portion is traversed we print leftmost child then on we go to right part of it
        inorder(root->right);
    }
}
void operand(char b)
{
    struct tree*root;
    root= (struct tree *)malloc(sizeof(struct tree));             //new node is made for operand
    root->data = b;
    root->left = NULL;
    root->right = NULL;
    printf("\n%c",root->data);
    printf("\nOperand address :%p",root);
    push(root);                                   //as root node is prepared it get pushed in stack
    
}
void operator(char a)
{
    struct tree*root;
    root= (struct tree *)malloc(sizeof(struct tree));
    root->data = a;
    printf("Operator data :%c",root->data);
    root->right =pop();             //as this is postfix to infix so topmost in stack is right child so pop out top element and it is assigned as right child of root
    root->left =pop();            //then on left is pop out
    push(root);
}

int main(int argc,char **argv)
{
    int i=0,p,k,ans;
    char s[20];
    printf("Enter expression in postfix form:\n");
    scanf("%s",s);
    while(s[i]!='\0')
    {
        if(isalnum(s[i]))
        {
            printf("\nOperand : %c",s[i]);
            operand(s[i]);
        }
        else(isalnum(s[i]))
        {
             printf("\nOperator : %c",s[i]);
             operand(s[i]);
        }
        i++;
    }
    printf("The order traversal of tree is \n");
    inorder(stack[top]);
    return 0;
}
