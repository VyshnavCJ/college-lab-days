#include<stdio.h>
#define SIZE 5
typedef struct
{
    int element;
    int priority;
}priorq;

priorq pq[SIZE];
int F=-1, R=-1;
void insertpq(int,int);
void display(void);
int get_highest_priority(void);
void delete_highest_priority(void);

int main()
{
    char ch;
    int item, prior, max;
    printf("Press 'a' to insert an element.\n");
    printf("Press 'b' to get highest priority element\n");
    printf("Press 'c' to delete highest priority element.\n");
    printf("Press 'd' to display elements.\n");
    printf("Press 'e' to exit.\n");
    printf("Enter the choice (a/b/c/d/e) : ");
    do
    {
        scanf("%c",&ch);
        switch (ch)
        {
            case 'a': printf("Enter the element to be inserted : ");
                scanf("%d",&item);
                printf("Enter its priority : ");
                scanf("%d",&prior);
                insertpq(item,prior);
                break;
            case 'b' : max= get_highest_priority();
                printf("The highest priority item is : %d\n",max);
                break;
            case 'c' : delete_highest_priority();
                break;
            case 'd' : display();
                break;
            case 'e': break;
                default: printf("Enter your choice (a/b/c/d/e) :");
                break;
        }
    }while (ch!='e');
    return 0;
}
void insertpq(int item,int prior)
{
    if (R>=SIZE-1)
    {
        printf("Queue full!\n");
    }
    else
        {
            if (F==-1&&R==-1)
            {
                F=0;
            }
            R++;
            pq[R].element=item;
            pq[R].priority=prior;
        }
}

int get_highest_priority(void)
    {
    int maxp=0,maxi,i;
    for ( i = F; i <= R; i++)
    {
        if (pq[i].priority>maxp)
        {
            maxp=pq[i].priority;
            maxi=pq[i].element;
        }
    }
    return maxi;
}

void delete_highest_priority(void)
{
    int m,i,j;
    m=get_highest_priority();
    if (R==-1)
    {
        printf("Queue empty\n");
    }
    else
    {
        for ( i = F; pq[i].element!=m;i++);
            for (j = i; j < R; j++)
            {
                pq[j].element=pq[j+1].element;
                pq[j].priority=pq[j+1].priority;
            }
        R--;
    }
}

void display(void)
{
    int i;
    if (R==-1)
    {
        printf("Queue empty\n");
    }
    else
    {
        for ( i = F; i <= R; i++)
        {
            printf("Element : %d\tPriority :%d\n",pq[i].element,pq[i].priority);
        }
    }
}