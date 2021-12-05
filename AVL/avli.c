#include <stdlib.h>
#include<stdio.h>
typedef struct node NODE;
struct node 
{
    NODE* left;
    int data;
    int height;
    NODE* right;
};NODE *root=NULL;

int NodeHeight(NODE* p)
{
    int hl,hr;
    hl= p && p->left? p->left->height : 0;
    hr= p && p->right? p->right->height : 0;

    return hl>hr? hl+1: hr+1;
}
int BalanceFactor(NODE* p)
{
    int hl,hr;
    hl= p && p->left? p->left->height : 0;
    hr= p && p->right? p->right->height : 0;
    return hl-hr;
}
NODE* LLRotation(NODE* p)
{
    NODE* pl=p->left;
    NODE* plr=pl->right;

    pl->right=p;
    p->left=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root==p)
    {
        root=pl;
    }
    return pl;
}
NODE* RRRotation(NODE *p)
{
    NODE* pr=p->right;
    NODE* prl=pr->left;

    pr->left=p;
    p->right=prl;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    if(root==p)
    {
        root=pr;
    }
    return pr;
}

NODE* LRRotation(NODE *p)
{
    NODE* pl=p->left;
    NODE* plr=pl->right;

    pl->right=plr->left;
    p->left=plr->right;

    plr->left=pl;
    plr->right=p;

    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);

    if(root==p)
    {
        root=plr;
    }
    return plr;
    
}
NODE* RLRotation(NODE *p)
{
    NODE* pr=p->right;
    NODE* prl=pr->left;

    pr->left=prl->right;
    p->right=prl->left;

    prl->right=pr;
    prl->left=p;

    pr->height=NodeHeight(pr);
    p->height=NodeHeight(p);
    prl->height=NodeHeight(prl);

    if(root==p)
    {
        root=prl;
    }
    return prl;
}

NODE* insert(NODE *p,int key)
{
    NODE* t=NULL;

    if(!p)
    {
        t=(NODE*)malloc(sizeof(NODE));
        t->data=key;
        t->height=1;
        t->left=t->right=NULL;
        return t;
    }
    if(key< p->data)
    {
        p->left=insert(p->left,key);
    }
    else if(key>p->data)
    {
        p->right=insert(p->right,key);
    }

    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1)
    {
        return LLRotation(p);
    } 
    else  if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
    {
        return LRRotation(p);
    }
    else  if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1)
    {
        return RRRotation(p);
    }
    else  if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)
    {
        return RLRotation(p);
    }

    return p;
}
void inorderTraversal(NODE* root)
{
    if (root == NULL) return;     
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
void delete_tree(NODE *roo)
{
    if (roo )
    {
        delete_tree(roo->left);
        delete_tree(roo->right);
        free(roo);
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
            p->height=NodeHeight(p);
            p->left=Delete(p->left,q->data);
        }
    else
    {
        q=InSucc(p->right);
        p->data=q->data;
        p->height=NodeHeight(p);
        p->right=Delete(p->right,q->data);
    }
    }
        p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 && (BalanceFactor(p->left)==1 || BalanceFactor(p->left)==0 ))
    {
        return LLRotation(p);
    } 
    else  if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
    {
        return LRRotation(p);
    }
    else  if(BalanceFactor(p)==-2 && (BalanceFactor(p->right)==-1 || BalanceFactor(p->right)==0 ))
    {
        return RRRotation(p);
    }
    else  if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)
    {
        return RLRotation(p);
    }
    return p;
}
int main()
{
    root=insert(root,10000);
    root=insert(root,20);
    root=insert(root,30);   
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,60);
    root=insert(root,700);
    root=insert(root,80);
    root=insert(root,9000);
    root=insert(root,1000);
    root=Delete(root,50);
    root=Delete(root,9000);
    inorderTraversal(root);

    delete_tree(root);
    return 0;

}