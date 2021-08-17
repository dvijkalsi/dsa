/*WAP to read and print the details of 5 cs students(roll, age, cgpa, sub) using DMA*/
#include<stdlib.h>
#include<stdio.h>
struct student
{
    int roll,age;
    float cgpa;
    char sub[50];
};
int main()
{
    struct student *s;
    s=(struct student*)malloc(5*sizeof(struct student));
    for(int i=0;i<5;i++)
    {
        printf("\nEnter details");
        printf("\nEnter roll:");
        scanf("%d",&s[i].roll);
        printf("\nEnter age:");
        scanf("%d",&s[i].age);
        printf("\nEnter cgpa:");
        scanf("%f",&s[i].cgpa);
        printf("\nEnter subjects:");
        scanf("%s",&s[i].sub);
    }
 
    for(int i=0;i<5;i++)
    {
           printf("\nPrinting details:-\n");
        printf("\nroll:%d",s[i].roll);
        
        printf("\nage:%d",s[i].age);
     
        printf("\ncgpa:%.1f",s[i].cgpa);
       
        printf("\nsubjects:%s",s[i].sub);
        
    }
    free(s);
    s=NULL;
    return 0;
}
