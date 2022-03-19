#include<stdio.h>
void toh(int n, int a,int b,int c)
{
    if(n>0)
    {
        toh(n-1,a,c,b);
        printf("\nMove tower%d to tower%d",a,c);
        toh(n-1,b,a,c);
    }
}
int main()
{
    toh(5,1,2,3);

}