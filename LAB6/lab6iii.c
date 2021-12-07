//WAP to represent a sparse matrix using linked list.
//WAP to find out the transpose of a sparse matrix.
//WAP to multiply two sparse matrices
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row;
    int col;
    int val;
    struct node *next;
};

struct node *CreateSparedMatrix(struct node *head)
{
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number of rows in the matrix\n");
    scanf("%d", &head->row);
    printf("Enter the number of columns of the matrix\n");
    scanf("%d", &head->col);
    printf("Enter the number of non-zero elements\n");
    scanf("%d", &head->val);
    struct node *temp = head;
    for (int i = 0; i < (head->val); i++)
    {
        temp->next = (struct node *)malloc(sizeof(struct node));
        temp = temp->next;
        temp->next = NULL;
        printf("Enter the row,col and then value\n");
        scanf("%d%d%d", &temp->row, &temp->col, &temp->val);
    }
    return head;
}
struct node *transpose(struct node *head)
{
    int r = head->row, c = head->col;
    int arr[r][c], a[c][r];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = 0;
        }
    }
    struct node *temp = head->next;
    while (temp != NULL)
    {
        arr[temp->row][temp->col] = temp->val;
        temp = temp->next;
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            a[i][j] = arr[j][i];
        }
    }
    temp = head->next;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (a[i][j] != 0)
            {
                temp->row = i;
                temp->col = j;
                temp->val = a[i][j];
                temp = temp->next;
            }
        }
    }
    int t = head->row;
    head->row = head->col;
    head->col = t;
    return head;
}

struct node *pro(struct node *head1, struct node *head2)
{
    int l = head1->col, r = head2->row;
    if (l == r)
    {
        int arr1[head1->row][head1->col];
        int arr2[head2->row][head2->col];
        for (int i = 0; i < head1->row; i++)
        {
            for (int j = 0; j < head1->col; j++)
            {
                arr1[i][j] = 0;
            }
        }
        struct node *temp1 = head1->next;
        while (temp1 != NULL)
        {
            arr1[temp1->row][temp1->col] = temp1->val;
            temp1 = temp1->next;
        }
        for (int i = 0; i < head2->row; i++)
        {
            for (int j = 0; j < head2->col; j++)
            {
                arr2[i][j] = 0;
            }
        }
        struct node *temp2 = head2->next;
        while (temp2 != NULL)
        {
            arr2[temp2->row][temp2->col] = temp2->val;
            temp2 = temp2->next;
        }
        int arr3[head1->row][head2->col];
        for (int i = 0; i < head1->row; i++)
        {
            for (int j = 0; j < head2->col; j++)
            {
                arr3[i][j] = 0;
            }
        }
        int r1 = head1->row, r2 = head2->row, c1 = head1->col, c2 = head2->col;
        int c = 0;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < r2; k++)
                {
                    arr3[i][j] += arr1[i][k] * arr2[k][j];
                }
                if (arr3[i][j] != 0)
                {
                    c++;
                }
            }
        }
        struct node *head = (struct node *)malloc(sizeof(struct node));
        head->row = head1->row;
        head->col = head2->col;
        head->val = c;
        struct node *temp = head;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                if (arr3[i][j] != 0)
                {
                    temp->next = (struct node *)malloc(sizeof(struct node));
                    temp = temp->next;
                    temp->row = i;
                    temp->col = j;
                    temp->val = arr3[i][j];
                }
            }
        }
        return head;
    }
    else
    {
        printf("Multiplication not possible\n");
        return NULL;
    }
}

void display(struct node *head)
{
    struct node *temp = head->next;
    int n = head->val;
    printf("\nRow \t\t Column \t Value\n");
    printf("%d\t\t %d\t\t %d\n", head->row, head->col, head->val);
    printf("\n\nRow \t\t Column \t Value\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t %d\t\t %d\n", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void multiplication()
{
    printf("\n");
    for (int i = 0; i < 50; i++)
        printf("*");
    printf("\n");
}

int main()
{
    int n;
    struct node *head1, *head2, *added, *product;
    do
    {
        multiplication();
        printf("\n");
        printf("----------Matrix Operations--------- \n\n");
        printf("1 - Create First sparsed matrix\n");
        printf("2 - Create Second sparsed matrix\n");
        printf("3 - Multiply two sparsed matrix\n");
        printf("4 - Transpose of a matrix\n");
        printf("5 - Display the sparsed matrices\n");
        printf("6 - Exit\n");
        multiplication();
        printf("\nEnter your choice : ");
        scanf("%d", &n);
        if (n == 1)
        {
            head1 = CreateSparedMatrix(head1);
        }
        else if (n == 2)
        {
            head2 = CreateSparedMatrix(head2);
        }
        else if (n == 3)
        {
            product = pro(head1, head2);
            printf("The Product is : \n");
            display(product);
        }
        else if (n == 4)
        {
            int m;
            printf("1.Transpose first sparsed matrix\n");
            printf("2.Transpose Second sparsed matrix\n");
            scanf("%d", &m);
            if (m == 1)
            {
                head1 = transpose(head1);
                display(head1);
            }
            else if (m == 2)
            {
                head2 = transpose(head2);
                display(head2);
            }
            else
            {
                printf("Invalid\n");
            }
        }
        else if (n == 5)
        {
            printf("The first sparsed matrix is : \n");
            display(head1);
            printf("\n");
            printf("The Second sparsed matrix is : \n");
            display(head2);
        }
        else if (n == 6)
        {
            printf("Thank You !!");
            multiplication();
            exit;
        }
        else
        {
            printf("Invalid input Enter again !!\n\n");
        }
    } while (n != 7);
}