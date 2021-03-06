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
typedef struct queue Q;
struct queue
{
    NODE *data;
    Q *next;
};
void enque(Q **st,NODE *t)
{
    Q *new=(Q*)malloc(sizeof(Q));
    new->next=NULL;
    new->data=t;
    if(*st==NULL)
    {
        *st=new;
    }
    else
    {
        Q *t=*st;
        while(t->next) t=t->next;
        t->next=new;
    }
}
NODE* deque(Q **st)
{
    NODE *x=(*st)->data;
    Q *y=*st;
    *st=(*st)->next;
    free(y);
    return x;
}

void levelOrder(NODE *p) //level order travesal using queue
{
    Q *q=NULL;
    printf("%d ",p->data);
    enque(&q,p);
    while(q)
    {
        p=deque(&q);
        if(p->left)
        {
            printf("%d ",p->left->data);
            enque(&q,p->left);
        }
        if(p->right)
        {
            printf("%d ",p->right->data);
            enque(&q,p->right);
        }

    }
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
void inorderTraversal(NODE* root)
{
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
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
int Height(NODE *p)
{
    int x,y;
    if(p==NULL)return 0;
    x=Height(p->left);
    y=Height(p->right);
    return x>y?x+1:y+1;
}
NODE* InPre(NODE *p)
{
    while(p && p->right!=NULL)
    p=p->right;

    return p;
}
NODE *InSucc(NODE *p)
{
    while(p && p->left!=NULL)
    p=p->left;

    return p;
}
NODE *Delete(NODE *p,int key)
{
    NODE *q;

    if(p==NULL)
        return NULL;
    if(p->left==NULL && p->right==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }

    if(key < p->data)
        p->left=Delete(p->left,key);
    else if(key > p->data)
        p->right=Delete(p->right,key);
    else
    {
        if(Height(p->left)>Height(p->right))
        {
            q=InPre(p->left);
            p->data=q->data;
            p->left=Delete(p->left,q->data);
        }
    else
    {
        q=InSucc(p->right);
        p->data=q->data;
        p->right=Delete(p->right,q->data);
    }
    }
    return p;
}
// NODE* deleteLeaf(NODE* root, int x)
// {
//     if (root == NULL)   return NULL;
//     root->left = deleteLeaf(root->left, x);
//     root->right = deleteLeaf(root->right, x);
//     if (root->data == x && root->left == NULL && root->right == NULL) 
//     {
//         printf("\nDeleted leaf:%d",root->data);
//         free(root);
//         return NULL;
//     }
//     return root;
// }

// NODE* minValueNode(NODE* node)
// {
//     struct node* current = node;
 
//     /* loop down to find the leftmost leaf */
//     while (current && current->left != NULL)
//         current = current->left;
 
//     return current;
// }
 
// NODE* deleteNode(NODE* root, int key)
// {
//     // base case
//     if (root == NULL)
//         return root;
//     // If the key to be deleted
//     // is smaller than the root's
//     // key, then it lies in left subtree
//     if (key < root->data)
//         root->left = deleteNode(root->left, key);
 
//     // If the key to be deleted
//     // is greater than the root's
//     // key, then it lies in right subtree
//     else if (key > root->data)
//         root->right = deleteNode(root->right, key);
//     // if key is same as root's key,
//     // then This is the node
//     // to be deleted
//     else {
//         // node with only one child or no child
//         if (root->left == NULL)
//         {
//             NODE* temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL) 
//         {
//             NODE* temp = root->left;
//             free(root);
//             return temp;
//         }
 
//         // node with two children:
//         // Get the inorder successor
//         // (smallest in the right subtree)
//         NODE* temp = minValueNode(root->right);

//         // Copy the inorder
//         // successor's content to this node
//         root->data = temp->data;
 
//         // Delete the inorder successor
//         root->right = deleteNode(root->right, temp->data);
//     }
//     return root;
// }
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
    printf("\nBefore deletion:");
    levelOrder(root);
    printf("\ninorder traversal:");
    inorderTraversal(root);
    Delete(root,170);

    // deleteNode(root, 60);
    // deleteNode(root, 200);
    // deleteLeaf(root, 170);
        printf("\nAfter deletion:");
    levelOrder(root);
    delete_tree(root);
    return 0;
}