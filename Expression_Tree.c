#include <stdio.h>
#include <stdlib.h>
struct node {
    char data;
    struct node* left;
    struct node* right;
};
struct node* create_node(char data) 
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
struct node* construct_tree(char postfix[]) {
    struct node* stack[100];
    int top = -1;
    int i = 0;
    while (postfix[i] != '\0') 
    {
        char ch = postfix[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            struct node* new_node = create_node(ch);
            stack[++top] = new_node;
          
        }
        else if (ch >= '0' && ch <= '9')
        {
            struct node* new_node = create_node(ch);
            stack[++top] = new_node;
            
        }
        else
        {
            struct node* new_node = create_node(ch);
            new_node->right = stack[top--];
            new_node->left = stack[top--];
            stack[++top] = new_node;
            
            printf("operator stack = %p \n",stack[top]);
        }
        i++;
    }
    printf("stack = %p \n",stack[top]);
   
    return stack[top];
   // printf("stack = %p \n",stack[top]);
}
void inorder(struct node* root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
int main(void) {
    char postfix[] = "423^^34*+";
    struct node* root = construct_tree(postfix);
    printf("root = %p \n",root);
    printf("Inorder traversal of expression tree:\n");
    inorder(root);
    return 0;
}
