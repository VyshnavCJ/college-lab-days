#include<stdio.h>

#define SIZE 5

int CQ[SIZE], F=-1, R=-1;
void insertcq(int);
void deletecq(void);
void displaycq(void);

int main()
{
    char ch;
    int n;
    printf("Press 'a' to perform insert cqueue.\n");
    printf("Press 'b' to perform delete cqueue.\n");
    printf("Press 'c' to display cqueue.\n");
    printf("Press 'd' to exit.\n");
    printf("Enter an option (a/b/c/d) : ");
    do
    {
        scanf("%c",&ch);
        switch (ch)
        {
            case 'a': printf("Enter the no. to be inserted : ");
            scanf("%d",&n);
            insertcq(n);
            break;
            case 'b' : deletecq();
            break;
            case 'c' : displaycq();
            break;
            case 'd': break;
            default : printf("Enter an option (a/b/c/d) : ");
            break;
        }
    } while (ch!='d');
    return 0;
}
void insertcq(int item)
{
    int next;
    if (F==-1)
    {
        F=0;
        R=0;
        CQ[R]=item;
    }
    else
    {
        next = (R+1)%SIZE;
        if (next!=F&&next!=SIZE)
        {
            R=next;
            CQ[R]=item;
        }
        else
        {
            printf("Queue full\n");
        }
    }
}
void deletecq(void)
{
    int item;
    if (F==-1)
    {
        printf("Queue empty\n");
    }
    else
    {
        item=CQ[F];
        if (F==R)
        {
            F=-1;
            R=-1;
        }
        else
        {
            F=(F+1)%SIZE;
        }
        printf("The deleted item is : %d\n",item);
    }
}
void displaycq(void)
{
    int i;
    if (F==-1)
    {
        printf("Queue empty!\n");
    }
    else
    {
        printf("FRONT : %d\n",F);
        printf("REAR : %d\n",R);
        printf("Elements are : ");
        for ( i = F; i <= R; i = (i+1)%SIZE)
        {
            printf("%d\t",CQ[i]);
        }
        printf("\n");
    }
}