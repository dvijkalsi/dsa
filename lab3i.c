//WAP to add two distances (in km-meter) by passing structure to a function.
#include<stdio.h>
struct distance
{
    int km;
    int m;
};
void add(struct distance s1, struct distance s2)
{
    int metres=(s1.m+s2.m)%1000;
    int kilometres=s1.km+s2.km+((s1.m+s2.m)/1000);
    printf("\ntotal distance is:%d km and %d m",kilometres,metres);
}
int main()
{
    struct distance d1,d2;
    printf("\nEnter distance1 km and m:");
    scanf("%d%d",&d1.km,&d1.m);
    printf("\nEnter distance2 km and m:");
    scanf("%d%d",&d2.km,&d2.m);
    add(d1,d2);
    return 0;
}
