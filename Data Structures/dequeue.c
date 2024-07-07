#define SIZE 5
#include <stdio.h>
int dq[SIZE], F=-1, R=-1;
void insert_frontdq(int);
void delete_reardq(void);
void displaydq(void);

int main()
{
    char ch;
    int n;
    printf("Press 'a' to perform insert dqueue at front.\n");
    printf("Press 'b' to perform delete dqueue at rear.\n");
    printf("Press 'c' to display dqueue.\n");
    printf("Press 'd' to exit.\n");
    printf("Enter an option (a/b/c/d) : ");
    do
    {
        scanf("%c",&ch);
        switch (ch)
        {
            case 'a': printf("Enter the no: to be inserted : ");
            scanf("%d",&n);
            insert_frontdq(n);
            break;
            case 'b' : delete_reardq();
            break;
            case 'c': displaydq();
            break;
            case 'd': break;
            default : printf("Enter an option (a/b/c/d) : ");
            break;
        }
    } while (ch!='d');
    return 0;
}

void insert_frontdq(int item)
{
    int ahead;
    if (F==-1)
    {
        F=0;
        R=0;
        dq[F]=item;
    }
    else
    {
        if(F==0)
        {
            ahead=SIZE-1;
        }
        else
        {
            ahead=F-1;
        }
        if (ahead==R)
        {
            printf("Queue full\n");
        }
        else
        {
            F=ahead;
            dq[F]=item;
        }
    }
    }

void delete_reardq(void)
{
    int item;
    if (F==-1)
    {
        printf("Queue empty\n");
    }
    else
    {
        if (F==R)
        {
            item=dq[R];
            F=-1;
            R=-1;
        }
        else if (R==0)
        {
            item=dq[R];
            R=SIZE-1;
        }
        else
        {
            item=dq[R];
            R--;
        }
        printf("The deleted element is : %d\n",item);
    }
}

void displaydq(void)
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
        for ( i = F; i !=R ; i = (i+1)%SIZE )
        {
            printf("%d\t",dq[i]);
        }
        printf("%d\n",dq[R]);
    }
}
