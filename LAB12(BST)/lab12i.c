// WAP Write the following menu driven program for the binary search tree
// ----------------------------------------
// Binary Search Tree Menu
// ----------------------------------------
// 0. Quit
// 1. Create
// 2. In-Order Traversal
// 3. Pre-Order Traversal
// 4. Post-Order traversal
// 5. Search
// 6. Find Smallest Element
// 7. Find Largest Element
// ----------------------------------------
// Enter your choice:
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    NODE *left;
    int data;
    NODE *right;
};NODE *root;
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
void preorderTraversal(NODE *root)
{
    if(root == NULL) return;
    printf("%d ->",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(NODE *root)
{
    if(root == NULL) return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->",root->data);
}
void insert(NODE **tree, int value) 
{
    NODE *temp = NULL;
    if(!(*tree))
    {
        temp = (NODE *)malloc(sizeof(NODE));
        temp->left = temp->right = NULL;
        temp->data = value;
        *tree = temp;
        return;
    }
    if(value < (*tree)->data) 
    {
        insert(&(*tree)->left, value);
    } else if(value > (*tree)->data) 
    {
        insert(&(*tree)->right, value);
    }
}
NODE *search(NODE **tree, int key) 
{
    if(!(*tree))
    {
        return NULL;
    }
    if(key == (*tree)->data) 
    {
        return *tree;
    } else if(key < (*tree)->data) 
    {
        search(&((*tree)->left), key);
    } else if(key > (*tree)->data)
    {
        search(&((*tree)->right),key);
    }
}
int largest(NODE *tree)
{
    if((tree)->right == NULL)
    {
        return (tree)->data;
    }
    else
    {
        largest(tree->right);
    }
}
int smallest(NODE *tree)
{
    if(tree->left==NULL)
    {
        return tree->data;
    }
    else 
    {
        smallest(tree->left);
    }
}
int main()
{
    int c;
    do
    {
        printf("\n----------------------------------------");
        printf("\nBinary Search Tree Menu");
        printf("\n----------------------------------------");
        printf("\n0. Quit\n1. Enter a node\n2. In-Order Traversal\n3. Pre-Order Traversal\n4. Post-Order traversal\n5. Search\n6. Find Smallest Element\n7. Find Largest Element");
        printf("\n----------------------------------------");
        printf("\nEnter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 0:
                break;
            case 1:
                printf("");
                int d;
                printf("\nEnter a number:");
                scanf("%d",&d);
                insert(&root,d);
                break;
            case 2:
                inorderTraversal(root);
                break;
            case 3:
                preorderTraversal(root);
                break;
            case 4:
                postorderTraversal(root);
                break;
            case 5:
                printf("");
                int d1;
                printf("\nEnter number to be searched:");
                scanf("%d",&d1);
                   if(search(&root,d1))
                    {
                        printf("\nsearch successfull");
                    }
                    else 
                    {
                        printf("\nsearch unsuccessful");
                    }
                break;
            case 6:
                printf("\nSmallest:%d",smallest(root));
                break;
            case 7:
                printf("\nLargest:%d",largest(root));
                break;
            default:
                printf("\nInvalid choice");
        }
    } while (c);
    
    // insert(&root,5);
    // insert(&root,7);
    // insert(&root,3);
    // insert(&root,90);
    // insert(&root,50);
    // inorderTraversal(root);
    // if(search(&root,3))
    // {
    //     printf("\nsearch successfull");
    // }
    // else 
    // {
    //     printf("\nsearch unsuccessful");
    // }
    // printf("\nLargest:%d",largest(root));
    // printf("\nSmallest:%d",smallest(root));
    delete_tree(root);
    return 0;
}