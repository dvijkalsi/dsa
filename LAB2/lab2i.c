/*Q1. Write a program using C to allocate memory dynamically for 2D array ,read the values and
 display them using 3 functions separately
I.Keeping no columns fixed and using variable no of rows
II.Keeping no rows fixed and using variable no of columns
III.Using both variable no of rows and columns(use double pointer)*/
#include<stdio.h>
#include<stdlib.h>
void ptr_to_ar()
{
    printf("Ptr_to_ar\nEnter number of rows");
    int r,i,j;
    scanf("%d",&r);
    int (*q)[5];
    q=(int*)malloc(r*5*sizeof(int));
    printf("\nEnter the %d*5 array\n",r);
    for(i=0;i<r;++i)
    {
        for(j=0;j<5;++j)
        {
            scanf("%d",&q[i][j]);
        }
    }
    printf("\nmemory allocated successfully, printing array:-\n");
    for(i=0;i<r;++i)
    {
        for(j=0;j<5;++j)
        {
            printf("%d ",q[i][j]);
        }
        printf("\n");
    }
    free(q);
    q=NULL;
}
void arr_of_ptr()
{
    printf("\narr_of_ptr\n");
    int *r[3];
    int i,j; int c[3];
    for(i=0;i<3;++i)
    {
       
        printf("\nEnter size of row-%d:",i+1);
        scanf("%d",&c[i]);
        r[i]=(int*)malloc(c[i]*sizeof(int));
        printf("\nEnter row:");
        for(j=0;j<c[i];++j)
        {
            scanf("%d",&r[i][j]);
        }
    }
    printf("\nmemory allocated successfully, printing array:-\n");
    for(i=0;i<3;++i)
    {
        for(j=0;j<c[i];++j)
        {
            printf("%d ",r[i][j]);
        }
        printf("\n");free(r[i]);
        r[i]=NULL;
    } 
}
void dbl_ptr()
{
    int **s;int r,c,i,j;
    printf("\ndbl_ptr\nEnter rows and columns:");
    scanf("%d%d",&r,&c);
    printf("\nEnter the array\n");
    s=(int**)malloc(r*sizeof(int));
    for(i=0;i<r;++i)
    {
        s[i]=(int*)malloc(c*sizeof(int));
        for(j=0;j<c;++j)
        {
            scanf("%d",&s[i][j]);
        }
    }
        printf("\nmemory allocated successfully, printing array:-\n");
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
        
    }
    free(s);
    s=NULL;
}
int main()
{
    ptr_to_ar();
    arr_of_ptr();
    dbl_ptr();
    return 0;
}