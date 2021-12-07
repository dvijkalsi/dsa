/*WAP to create a linked list that represents a polynomial expression with single variable (i.e. 5x7-3x5+x2+9)
 and display the polynomial by using user defined functions for creation and display.Write a program to add 
 and multiply two polynomials with single variable with a new function for addition and multiplication operations.*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff_006, exp_006;
    struct node *next;
};

struct node *add(struct node *poly1, struct node *poly2)
{
    struct node *head = NULL;
    if (poly1 != NULL && poly2 != NULL)
    {
        struct node *head2 = NULL;
        int m = 0;
        if (poly1->exp_006 >= poly2->exp_006)
            m = poly1->exp_006;
        else
            m = poly2->exp_006;
        for (int i = m; i >= 0; i--)
        {
            struct node *Temp = (struct node *)malloc(sizeof(struct node));
            Temp->exp_006 = i;
            Temp->coeff_006 = 0;
            Temp->next = NULL;
            if (poly1->exp_006 == Temp->exp_006)
            {
                Temp->coeff_006 += poly1->coeff_006;
                poly1 = poly1->next;
            }
            if (poly2->exp_006 == Temp->exp_006)
            {
                Temp->coeff_006 += poly2->coeff_006;
                poly2 = poly2->next;
            }
            if (head != NULL)
            {
                head2->next = Temp;
                head2 = head2->next;
            }
            else
            {
                head = Temp;
                head2 = Temp;
            }
        }
    }
    return head;
}
struct node *multi(struct node *poly1, struct node *poly2)
{
    struct node *head = NULL;
    if (poly1 != NULL && poly2 != NULL)
    {
        struct node *head2 = NULL;
    }
    return head;
}
struct node *input()
{
    int n;
    struct node *head = NULL;
    struct node *head2 = NULL;
    printf("Enter the highest expree of polynomial : ");
    scanf("%d", &n);
    for (int i = n; i >= 0; i--)
    {
        printf("Enter the coefficient of x^%d : ", i);
        int temp = 0;
        scanf(" %d", &temp);
        struct node *Temp = (struct node *)malloc(sizeof(struct node));
        Temp->coeff_006 = temp;
        Temp->exp_006 = i;
        Temp->next = NULL;
        if (head != NULL)
        {
            head2->next = Temp;
            head2 = head2->next;
        }
        else
        {
            head = Temp;
            head2 = Temp;
        }
    }
    return head;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("\n");
        printf("Polynomial is empty.");
    }
    else
    {
        printf("\n");
        printf("Polynomial : \n");
    }
    while (head != NULL)
    {
        if (head->coeff_006 != 0)
        {
            if (head->coeff_006 > 0)
                printf("%dx^%d +", head->coeff_006, head->exp_006);
            else
                printf("%dx^%d ", head->coeff_006, head->exp_006);
        }
        head = head->next;
    }
    printf("\n");
}

void exponent()
{
    for (int i = 0; i < 80; i++)
        printf("_");
    printf("\n");
}

int main()
{
    struct node *poly1;
    struct node *poly2;
    struct node *polyadd;
    struct node *polysub;
    struct node *polyprod;
    int c = 0, k = 1;
    while (k)
    {
        printf("1.Create and display first polynomial\n");
        printf("2.Create and display second polynomial\n");
        printf("3.Add both polynomials and display the result\n");
        printf("4.Multiply both polynomials and display the result\n");
        printf("5.Exit\n");
        exponent();
        printf("Enter your choice : ");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
        case 1:
            poly1 = input();
            display(poly1);
            exponent();
            break;
        case 2:
            poly2 = input();
            display(poly2);
            exponent();
            break;
        case 3:
            polyadd = add(poly1, poly2);
            printf("added.\n");
            display(polyadd);
            exponent();
            break;
        case 4:
            polyprod = multi(poly1, poly2);
            printf("multiplied.\n");
            display(polyprod);
            exponent();
            break;
        case 5:
            k = 0;
            exponent();
            break;
        default:
            printf("Incorrect choice\n");
            exponent();
        }
    }
    return 0;
}