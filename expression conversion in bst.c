
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
