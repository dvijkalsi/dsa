#include<stdio.h>
int total()
{
 for(int i=0;i<10;++i)
 {
     if(i==5)
     {
         return 0;
     }
     if(i==6)
     {
         return 1;
     }
 }

}
int main()
{
    int x=total();
    printf("%d\n",x);
    return 0;
}