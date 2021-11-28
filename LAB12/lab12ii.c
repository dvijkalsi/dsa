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
// Extend the above program by providing more options as follows:
// a) To count number of leaf nodes in the tree.
// b) To count number of non-leaf nodes in the tree.
// c) To find number of nodes in the tree.
// d) To find sum of all nodes of the tree.
// e) To print depth of the tree.
// f) To find nodes which are at maximum depth in the tree?
// g) To print all the elements of kth level in single line.
// h) To find the common ancestor and print the paths.
// i) To check whether a tree is a binary search tree or not.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node NODE;
struct node
{
    NODE *left;
    int data;
    NODE *right;
};NODE *root;

int check_not_bst(NODE* root)//return true if not bst else returns 1
{
    if(root->left==NULL && root->right==NULL) return 0;
    else if((root->left!=NULL && root->right!=NULL))
    {
        if(root->right->data<root->data||root->left->data>root->data)
        {
            return 1;
        }
        else
        {
            return check_not_bst(root->left)+check_not_bst(root->right);
        }
    }
    else if(root->right==NULL)
    {
        if(root->left==NULL)
        {
            return 0;
        }
        else if(root->left->data>root->data)
        {
            return 1;
        }
        else 
        {
            return check_not_bst(root->left);
        }
    }
    else if(root->left==NULL)
    {
        if(root->right==NULL)
        {
            return 0;
        }
        else if(root->right->data<root->data)
        {
            return 1;
        }
        else
        {
            return check_not_bst(root->right);
        }
    }
}
// Utility function to find the LCA of two given values 
// n1 and n2. 
NODE* findLCA(NODE* root, int n1, int n2) 
{ 
    // Base case 
    if (root == NULL) 
        return NULL; 
  
    // If either n1 or n2 matches with root's key, 
    // report the presence by returning root (Note 
    // that if a key is ancestor of other, then the 
    // ancestor key becomes LCA 
    if (root->data == n1 || root->data == n2) 
        return root; 
  
    // Look for keys in left and right subtrees 
    NODE* left_lca = findLCA(root->left, n1, n2); 
    NODE* right_lca = findLCA(root->right, n1, n2); 
  
    // If both of the above calls return Non-NULL, then 
    // one key  is present in once subtree and other is 
    // present in other, So this node is the LCA 
    if (left_lca && right_lca) 
        return root; 
  
    // Otherwise check if left subtree or right 
    // subtree is LCA 
    return (left_lca != NULL) ? left_lca : right_lca; 
} 
  
// Utility Function to print all ancestors of LCA 
int printAncestors(NODE* root, int target) 
{ 
    /* base cases */
    if (root == NULL) 
        return 0; 
  
    if (root->data == target) { 
        printf("%d ",root->data); 
        return 1; 
    } 
  
    /* If target is present in either left or right 
      subtree of this node, then print this node */
    if (printAncestors(root->left, target) || 
        printAncestors(root->right, target)) { 
        printf("%d ",root->data); 
        return 1; 
    } 
  
    /* Else return false */
    return 0; 
} 
  
// Function to find nodes common to given two nodes 
int findCommonNodes(NODE* root, int first,int second) 
{ 
    NODE* LCA = findLCA(root, first, second); 
    if (LCA == NULL) 
        return 0; 
  
    printAncestors(root, LCA->data); 
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
void nodes_at_max_depth(NODE *root)
{    
    if(root==NULL) return;
    if(depth(root)==0)
    {   
        printf("%d ",root->data);
        return;
    }
    
    if(depth(root->left)>depth(root->right))
    {
        nodes_at_max_depth(root->left);
    }
    else if(depth(root->left)<depth(root->right))
    {
        nodes_at_max_depth(root->right);
    }
    else 
    {
        nodes_at_max_depth(root->left);
        nodes_at_max_depth(root->right);
    }
}
int count_leaf(NODE *tree)
{
    if(tree==NULL) return 0;
    if(tree->left==NULL && tree->right==NULL) return 1;
    else return 0+count_leaf(tree->left)+count_leaf(tree->right);
}
int count_non_leaf(NODE *tree)
{
    if(tree==NULL) return 0;
    if(tree->left==NULL && tree->right==NULL) return 0;
    else return 1+count_non_leaf(tree->left)+count_non_leaf(tree->right);
}
int count_nodes(NODE *tree)
{
    if(tree==NULL) return 0;
    else return 1+count_nodes(tree->left)+count_nodes(tree->right);
}
int sum_nodes(NODE *tree)
{
    if(tree==NULL) return 0;
    else return tree->data+sum_nodes(tree->left)+sum_nodes(tree->right);
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
    int c,n1,n2,k;
    do
    {
        printf("\n----------------------------------------");
        printf("\nBinary Search Tree Menu");
        printf("\n----------------------------------------");
        printf("\n0. Quit\n1. Enter a node\n2. In-Order Traversal\n3. Pre-Order Traversal\n4. Post-Order traversal\n5. Search\n6. Find Smallest Element\n7. Find Largest Element\n8. Count the number of leaf nodes\n9. To count number of non-leaf nodes in the tree\n10. To find number of nodes in the tree.\n11. To find sum of all nodes of the tree.\n12. To print depth of the tree.\n13. To find nodes which are at maximum depth in the tree?\n14. To print all the elements of kth level in single line.\n15.Print common ancestors of two node\n16.Check if bst or not");
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
            case 8:
                printf("\nCount_leaf:%d",(count_leaf(root)));
                break;
            case 9:
                printf("\nCount_non_leaf:%d",(count_non_leaf(root)));
                break;
            case 10:
                printf("\nCount_nodes:%d",(count_nodes(root)));
                break;
            case 11:
                printf("\nsum_nodes:%d",(sum_nodes(root)));
                break;
            case 12:
                printf("\ndepth:%d",(depth(root)));
                break;
            case 13:
                printf("\nNode at max depth:");
                nodes_at_max_depth(root);
                break;
            case 14:
                printf("\nEnter K:");
                scanf("%d",&k);
                printf("\nNode_at_kth_line:");
                print_kth_level(root,k);
                break;
            case 15:
                printf("\nEnter data of two nodes to be checked:");
                scanf("%d%d",&n1,&n2);
                if(findCommonNodes(root,n1,n2 ) == 0) 
                 printf("No Common nodes"); 
                 break;
            case 16:
                    if (check_not_bst(root))
                    {
                        printf("\nNot a bst");
                    }
                    else
                    {
                        printf("\nIt is a bst");
                    }
                    break;
            default:
                printf("\nInvalid choice");
        }
    } while (c);
    
    // insert(&root,100);
    // insert(&root,50);
    // insert(&root,200);
    // insert(&root,10);
    // insert(&root,60);
    // insert(&root,90);
    // insert(&root,150);
    // insert(&root,300);
    // insert(&root,170);
    // insert(&root,210);
    // root->left->left->data=55;
    // if (check_not_bst(root))
    // {
    //     printf("\nNot a bst");
    // }
    // else
    // {
    //     printf("\nIt is a bst");
    // }
    // if(findCommonNodes(root, 150,300 ) == 0) 
    //     printf("No Common nodes"); 
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
    // printf("\nCount_leaf:%d",(count_leaf(root)));
    // printf("\nCount_non_leaf:%d",(count_non_leaf(root)));
    // printf("\nCount_nodes:%d",(count_nodes(root)));
    // printf("\nsum_nodes:%d",(sum_nodes(root)));
    // printf("\ndepth:%d",(depth(root)));
    // printf("\nNode at max depth:");
    // nodes_at_max_depth(root);
    // printf("\nNode_at_kth_line:");
    // print_kth_level(root,2);
    delete_tree(root);
    return 0;
}