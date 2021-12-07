//WAP to find the height of a binary tree and to display the total no of nodes in a binary tree using 
//recursion.
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    NODE *left;
    int data;
    NODE *right;
};NODE *root;
static int count=0;

NODE* create()
{
    NODE *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    if(x==-1)
    return NULL;
    p=(NODE*)malloc(sizeof(NODE));
    count++;
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}
void delete_tree(NODE *root)
{
    if (root) 
    {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }

}
void inorderTraversal(struct node* root)
{
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ->", root->data);
    inorderTraversal(root->right);
}
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int height(NODE *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else 
    {
        int leftH=height(root->left);
        int rightH=height(root->right);
        return max(leftH,rightH)+1;
    }
}
int main()
{
    root=create();
    inorderTraversal(root);
    printf("\ncount:%d",count);
    printf("\nheight:%d",height(root));
    delete_tree(root);
    return 0;
}