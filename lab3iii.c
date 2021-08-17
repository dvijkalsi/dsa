/*Given an unsorted dynamic array arr and two numbers x and y, find the minimum distance between x and
 y in arr. The array might also contain duplicates. You may assume that both x and y are different
  and present in arr.
Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
Output: Minimum distance between 3 and 6 is 4.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    printf("\nEnter size:");
    int n,i,j;
    scanf("%d",&n);
    int *arr;
    arr=(int*)malloc(n*sizeof(int));
    printf("\nEnter array:");
    for(i=0;i<n;++i)
    { 
        scanf("%d",&arr[i]);
    }
    int x,y,min=n,dis=0;
    printf("\nEnter x and y:");
    scanf("%d%d",&x,&y);
    for(i=0;i<n;++i)
    {
        if(arr[i]==x)
        {
            for(j=i+i;j<n;++j)
            {
                if(arr[j]==y)
                {
                    dis=j-i;
                    break;
                }
            }
        }
        else if(arr[i]==y)
        {
             for(j=i+i;j<n;++j)
            {
                if(arr[j]==x)
                {
                    dis=j-i;
                    break;
                }
            }
        }
        if(dis<min)
        {
            min=dis;
        }
    }
    printf("Minimum distance between %d and %d is %d.",x,y,min);
    free(arr);
    arr=NULL;
    return 0;
}
       