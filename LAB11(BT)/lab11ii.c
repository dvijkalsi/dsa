// Write the following menu driven program for the binary tree
// ----------------------------------------
// 1. Create_BinaryTree_Array (using sequential representation)
// 2.Create_BinaryTree_Linked (using linked representation)
// 3. In-Order Traversal
// 4. Pre-Order Traversal
// 5. Post-Order traversal
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    NODE *left;
    int data;
    NODE *right;
};NODE *root;
struct tree
{
    int n;
    int *arr;
};
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
void inorderTraversal(NODE* root)
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
int get_left_child(struct tree t,int i)
{
    if(t.arr[i]!='\0'&&(2*i)<t.n+1)
    {
        return 2*i;
    }
    else 
    {
        return -1;
    }
}
int get_right_child(struct tree t,int i)
{
    if(t.arr[i]!='\0'&&(2*i+1)<t.n+1)
    {
        return 2*i+1;
    }
    else 
    {
        return -1;
    }
}
void preorder_arr(struct tree t,int i)
{
    // checking for valid i and null node
    if(i>0 && t.arr[i]!='\0')
    {
        printf(" %d ",t.arr[i]); // visiting root
        preorder_arr(t,get_left_child(t,i)); //visiting left subtree
        preorder_arr(t,get_right_child(t,i)); //visiting right subtree
    }
}

void postorder_arr(struct tree t,int i)
{
    // checking for valid i and null node
    if(i>0 && t.arr[i]!='\0')
    {
        postorder_arr(t,get_left_child(t,i)); //visiting left subtree
        postorder_arr(t,get_right_child(t,i)); //visiting right subtree
        printf(" %d ",t.arr[i]); //visiting root
    }
}

void inorder_arr(struct tree t,int i)
{
    // checking for valid i and null node
    if(i>0 && t.arr[i]!='\0')
    {
        inorder_arr(t,get_left_child(t,i)); //visiting left subtree
        printf(" %d ",t.arr[i]); //visiting root
        inorder_arr(t,get_right_child(t,i)); // visiting right subtree
    }
}
struct tree create_arr()
{
    struct tree t;
    printf("\nEnter max nodes:");
    scanf("%d",&(t.n));
    t.arr=(int*)malloc((t.n+1)*sizeof(int));
    printf("\nEnter all elements:");
    for(int i=1;i<=t.n;++i)
    {
        scanf("%d",&(t.arr[i]));
    }
    t.arr[0]='\0';
    return t;
}
int main()
{
    int c1,c2;
    printf("\n1.Linked list implementation\n2.Array implementation\nEnter your choice:");
    scanf("%d",&c1);
    switch(c1)
    {
        case 1:
            root=create();
            do
            {
                printf("\n0.exit\n1.Inorder\n2.preorder\n3.postorder\nEnter your choice:");
                scanf("%d",&c2);
                switch(c2)
                {
                    case 1:
                        printf("\ninoreder:");
                        inorderTraversal(root);
                        break;
                    case 2:
                        printf("\npreorder:");
                        preorderTraversal(root);
                        break;
                    case 3:
                        printf("\npostorder:");
                        postorderTraversal(root);
                        break;
                    case 0:break;
                    default:
                        printf("\ninvalid choice");
                }
            }while (c2);
            delete_tree(root);
            break;
        case 2:
            printf("");
            struct tree t=create_arr();
            do
            {
                printf("\n0.exit\n1.Inorder\n2.preorder\n3.postorder\nEnter your choice:");
                scanf("%d",&c2);
                switch(c2)
                {
                    case 1:
                        printf("\ninoreder:");
                        inorder_arr(t,1);
                        break;
                    case 2:
                        printf("\npreorder:");
                        preorder_arr(t,1);
                        break;
                    case 3:
                        printf("\npostorder:");
                        postorder_arr(t,1);
                        break;
                    case 0:break;
                    default:
                        printf("\ninvalid choice");
                }
            }while(c2);
            free(t.arr);
            break;
        default:
            printf("\nInvalid choice");

    }
    
    // root=create();
    // printf("\ninoreder:");
    // inorderTraversal(root);
    // printf("\npreorder:");
    // preorderTraversal(root);
    // printf("\npostorder:");
    // postorderTraversal(root);
    // printf("\ncount:%d",count);
    // printf("\nheight:%d",height(root));
    // delete_tree(root);
    // struct tree t=create_arr();
    // printf("\ninorder:");
    // inorder_arr(t,1);
    // printf("\npreorder:");
    // preorder_arr(t,1);
    // printf("\npostorder:");
    // postorder_arr(t,1);
    return 0;
}