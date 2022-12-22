
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
    stack[top] = root;
    printf("\nstack data %p",stack[top]);
}
struct tree *pop()
{
    return(stack[top--]);
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
            inorder(root->left);
        }
        printf("%c",root->data);
        inorder(root->right);
    }
}
void operand(char b)
{
    struct tree*root;
    root= (struct tree *)malloc(sizeof(struct tree));
    root->data = b;
    root->left = NULL;
    root->right = NULL;
    printf("\n%c",root->data);
    printf("\nOperand address :%p",root);
    push(root);
    
}
void operator(char a)
{
    struct tree*root;
    root= (struct tree *)malloc(sizeof(struct tree));
    root->data = a;
    printf("Operator data :%c",root->data);
    root->right =pop(); 
    root->left =pop();
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
