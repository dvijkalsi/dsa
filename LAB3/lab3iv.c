//Write a program in C to find the LCM ,HCF,GCD of two numbers using recursion by using menu driven 
//switch case and functions.
#include<stdio.h>
int gcd(int a,  int b)
{
    if(a%b==0)
    {
        return b;

    }
    else{
        return gcd(b,a%b);
    }
}
int lcm(int a, int b)
{
    return ((a*b)/gcd(a,b));
}
int main()
{
    printf("\n\t\t1.LCM\n\t\t2.HCF\nEnter a choice:");
    int n;
    scanf("%d",&n);
    printf("\nEnter two numbers:");
    int a,b;
    scanf("%d%d",&a,&b);
    switch (n)
    {
    case 1:
        printf("\nlcm:%d",lcm(a,b));
        break;
    case 2:
        
        printf("\nhcf:%d",gcd(a,b));
        break;
    
    default:
        printf("Invalid choice");
        break;
    }
    return 0;
}