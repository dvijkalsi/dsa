/*Q3. WAP to swap all the elements in the 1st column with all the corresponding elements in the last 
column, and 2nd column with the second last column and 3rd with 3rd last etc. of a 2-D dynamic array.
Display the matrix.*/
#include<stdlib.h>
#include<stdio.h>
void swap(int **ar,int r,int c)
{
    int i,j;
    for(i=0;i<r;++i)
    {
        for(j=0;j<c/2;++j)
        {
            int t=ar[i][j];
            ar[i][j]=ar[i][c-1-j];
            ar[i][c-1-j]=t;
        }
    }
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
    swap(s,m,n);
    printf("\narray after swapping:\n");
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
        
    }
    free(s);
    s=NULL;
    return 0;
}