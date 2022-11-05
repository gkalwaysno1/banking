#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int balance = 0;
int ac3;
struct node
{
    int data;
    long acc;
    char w[10];
    struct node *next;
};
void init(int a[4], int z)
{
    if (z == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            a[i] = 0;
        }
    }
    else
    {
        printf("Enter the new password\n");
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &a[i]);
        }
    }
}

int check(int *p, int *q)
{
    int k = 0;
    printf("Enter password\n");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &q[i]);
    }
    printf("checking.....\n");
    for (int i = 0; i < 4; i++)
    {
        if (p[i] == q[i])
        {
            k++;
        }
    }
    if (k == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void changep(int *p, int *q)
{
    int m = check(p, q);
    if (m == 1)
    {
        init(p, 1);
    }
    else
    {
        printf("Incorrect password\n");
    }
}
void view(struct node *details)
{
    struct node *pres;
    pres = details;
    if (pres == NULL)
    {
        printf("No transactions are present\n");
    }
    else
    {
        printf("Amount\tAccount number\n");
        while (pres != NULL)
        {
            printf("%d\t%d\t%s\n", pres->data, pres->acc, pres->w);
            pres = pres->next;
        }
    }
    printf("Remaining balance : %d\n", balance);
}
void transact(int *p, int *q, struct node **details, char c)
{
    int x;
    long ac1, ac2;
    int m = check(p, q);
    if (m == 1)
    {
        printf("Enter the transaction amount\n");
        scanf("%d", &x);
        if (balance >= x && c == 'C')
        {
            printf("Enter the account no. : ");
            scanf("%d", &ac1);
            printf("Re-enter the account number\n");
            scanf("%d", &ac2);
            if (ac1 == ac2)
            {
                struct node *temp, *pres;
                temp = (struct node *)malloc(sizeof(struct node));
                temp->data = x;
                temp->acc = ac1;
                strcpy(temp->w, "Withdraw");
                balance = balance - x;

                temp->next = NULL;
                pres = (*details);
                if (pres == NULL)
                {
                    (*details) = temp;
                }
                else
                {
                    while (pres->next != NULL)
                    {
                        pres = pres->next;
                    }
                    pres->next = temp;
                    temp->next = NULL;
                }
            }

            else
            {
                printf("Invalid account number\n");
            }
        }
        else if (c == 'D')
        {
            struct node *temp, *pres;
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = x;
            temp->acc = ac3;
            strcpy(temp->w, "Deposit");
            balance = balance + x;
            temp->next = NULL;
            pres = (*details);
            if (pres == NULL)
            {
                (*details) = temp;
            }
            else
            {
                while (pres->next != NULL)
                {
                    pres = pres->next;
                }
                pres->next = temp;
                temp->next = NULL;
            }
        }
        else if (balance < x && c == 'C')
        {
            printf("Insufficient balance or invalid amount\n");
        }
    }
    else
    {
        printf("Incorrect password\n");
    }
}
int main()
{
    int p[4], q[4], r[4];
    int mr;
    struct node *details;
    details = NULL;
    init(p, 0);
    init(r, 0);
    int x, ch, dep, s;
    printf("Enter your account number\n");
    scanf("%d", &ac3);
    s = check(r, q);
    if (s == 1)
    {
        do
        {
            printf("\n0)Exit\n1)View Balance\n2)Deposit\n3)Change password\n4)Transact money\n5)View transaction details\nEnter your choice : ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                mr = check(p, q);
                if (mr == 1)
                {
                    printf("Reamaining Balance : %d\n", balance);
                    break;
                }
                else
                {
                    printf("Incorrect password\n");
                    break;
                }
            case 2:
                transact(p, q, &details, 'D');
                break;
            case 3:
                changep(p, q);
                break;
            case 4:
                transact(p, q, &details, 'C');
                break;
            case 5:
                mr = check(p, q);
                if (mr == 1)
                {
                    view(details);
                    break;
                }
                else
                {
                    printf("Wrong password\n");
                    break;
                }

            default:
                break;
            }
        } while (ch != 0);
    }
    else
    {
        printf("Invalid password, contact your bank\n");
    }

    return 0;
}