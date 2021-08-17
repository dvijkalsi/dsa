/*Q2. Let A be nXn square dynamic matrix. WAP by using appropriate user defined functions for the 
following:
a. Find the number of nonzero elements in A
B. Find the sum of the elements above the leading diagonal.
C. Display the elements below the minor diagonal.
D. Find the product of the diagonal elements.*/
#include<stdlib.h>
#include<stdio.h>
void nonzero(int **ar,int r,int c)
{
    int co=0,i,j;
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            if(ar[i][j]!=0)
            {
                co++;
            }
        }
    }
    printf("\nNon-zero elements:%d",co);
}
void sum(int **ar,int r,int c)
{
    int i,j,sum=0;
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            if(j>i)
            {
                sum+=ar[i][j];
            }
        }
    }
    printf("\nSum of elements above leading diagonal:%d",sum);
}
void display(int **ar,int r, int c)
{
    int i,j;
    printf("\nElements below minor diagonal:");
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            if(j>(c-i-1))
            {
                printf("%d ",ar[i][j]);
            }
        }
    }
}
void product(int **ar, int r, int c)
{
    int pro=1,i,j;
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            if((i==j)||(j==(c-i-1)))
            pro*=ar[i][j];
        }
    }
    printf("\nproduct of diagonal elements:%d",pro);
}
int main()
{
    int **s;int m,n,i,j;
    printf("Enter rows and columns:");
    scanf("%d%d",&m,&n);
    printf("\nEnter the array\n");
    s=(int**)malloc(m*sizeof(int));
    for(i=0;i<m;++i)
    {
        s[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;++j)
        {
            scanf("%d",&s[i][j]);
        }
    }
    nonzero(s,m,n);
    sum(s,m,n);
    display(s,m,n);
    product(s,m,n);
    free(s);
    s=NULL;
    return 0;
}