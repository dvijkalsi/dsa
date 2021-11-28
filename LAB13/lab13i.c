// 1.WAP using C
// I.To create a BST 
// II. Display the elements using Level order Traversal 
// III.Delete the leaf node and print it .
// IV.Delete a node which has only one child and readjust the BST
// V.Delete the node whose degree is 2 and display the deleted node,it’s inorder predecessor and inorder
//  successor and display all nodes in Inorder traversal after readjustment of BST 
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    NODE *left;
    int data;
    NODE *right;
};NODE *root;
// typedef struct queue Q;
// struct queue
// {
//     NODE *data;
//     Q *next;
// };
// void enque(Q **st,NODE *t)
// {
//     Q *new=(Q*)malloc(sizeof(Q));
//     new->next=NULL;
//     new->data=t;
//     if(*st==NULL)
//     {
//         *st=new;
//     }
//     else
//     {
//         new->next=*st;
//         *st=new;
//     }
// }
// NODE* deque(Q **st)
// {
//     Q *a=*st;
//     Q *b=NULL;
//     while(a->next)
//     {
//         b=a;
//         a=a->next;
//     }
//     b->next=NULL;
//     NODE *c=a->data;
//     free(a);
//     return c;
// }

// void levelOrder(NODE *root) //level order travesal using queue
// {
//     if (root == NULL) return;
//     Q *q;
//     NODE *curr;
//     // Enqueue Root and NULL node.
//     enque(&q,root);
//     enque(&q,NULL);
//     while (q)
//     {
//         curr = deque(&q);
//         // condition to check occurrence of next level.
//         if (curr == NULL)
//         {
//            enque(&q,NULL);
//            printf("\n");
//         }
//         else
//         {
//             // pushing left child of current node.
//             if(curr->left)
//             enque(&q,curr->left);
//             // pushing right child of current node.
//             if(curr->right)
//             enque(&q,curr->right);
//             printf("%d ",curr->data);
//         }
//     }
// }


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
void insert(NODE **tree, int value) 
{
    NODE *temp = NULL;
    if(!(*tree))
    {
        temp =(NODE*)malloc(sizeof(NODE));
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
NODE* deleteLeaf(NODE* root, int x)
{
    if (root == NULL)   return NULL;
    root->left = deleteLeaf(root->left, x);
    root->right = deleteLeaf(root->right, x);
    if (root->data == x && root->left == NULL && root->right == NULL) 
    {
        printf("\nDeleted leaf:%d",root->data);
        free(root);
        return NULL;
    }
    return root;
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
int depth(NODE *root)
{
    if(root==NULL)
    {
        return -1;
    }
    else 
    {
        int leftD=depth(root->left);
        int rightD=depth(root->right);
        return max(leftD,rightD)+1;
    }
}

void print_kth_level(NODE *root , int k)   
{
   if(root == NULL|| k < 0 )  return;
   if( k == 0 )
   {
        printf( "%d ", root->data );
        return ;
   }  
    print_kth_level( root->left, k-1 ) ;
    print_kth_level( root->right, k-1 ) ;
}
void printLevelOrder(NODE *root)
{        
    int d = depth(root);
    int i;
    for(i=0;i<=d;i++) 
    {
        printf("\n");
         print_kth_level(root,i);
    }
   
}
NODE* minValueNode(NODE* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
NODE* deleteNode(NODE* root, int key)
{
    // base case
    if (root == NULL)
        return root;
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL)
        {
            NODE* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            NODE* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        NODE* temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main()
{
    insert(&root,100);
    insert(&root,50);
    insert(&root,200);
    insert(&root,10);
    insert(&root,60);
    insert(&root,90);
    insert(&root,150);
    insert(&root,300);
    insert(&root,170);
    insert(&root,210);
    printf("\nBefore deletion");
    printLevelOrder(root);
    printf("\nAfter deletion");
    deleteNode(root, 60);
    deleteNode(root, 200);
    deleteLeaf(root, 210);
    printLevelOrder(root);
    printf("\n");
    inorderTraversal(root);
    delete_tree(root);
    return 0;
}