// WAP to sort an array of n dates in an ascending order using Bubble sort. 
// Date structure is {day, month, year }
#include<stdio.h>
#include<stdlib.h>
struct date
{
    int day;
    int month;
    int year;
};
struct date* make(int n)
{
    struct date *ar;
    // int n;
    // printf("\nEnter number of dates:");
    // scanf("%d",&n);
    ar=(struct date*)malloc(n*sizeof(struct date));
    for(int i=0;i<n;++i)
    {
        printf("\nEnter date dd mm yyyy %d:",i+1);
        scanf("%d %d %d",&ar[i].day,&ar[i].month,&ar[i].year);
    }
    return ar;
}
void disp(struct date *ar,int n)
{

    for(int i=0;i<n;++i)
    {
        printf("\ndate%d:",i+1);
        printf("%d/%d/%d",ar[i].day,ar[i].month,ar[i].year);
    }
}
void bubble_sort(struct date *ar,int n)
{
    int i,j;
    i=j=0;
    float fj=0.0,fj1=0.0;
    for(i=0;i<n-1;++i)
    {
        for(j=0;j<n-i-1;++j)
        {
            fj1=ar[j+1].year+(ar[j+1].month/12)+(ar[j+1].day/365);
            fj=ar[j].year+(ar[j].month/12)+(ar[j].day/365);
            if(fj>fj1)
            {
                struct date t=ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=t;
            }
        }
    }
}
int main()
{
    int n;
    printf("\nEnter number of dates:");
    scanf("%d",&n);
    struct date *ar=make(n);
    bubble_sort(ar,n);
    disp(ar,n);
    return 0;
}