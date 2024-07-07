#include<stdio.h>
#define SIZE 3

int Q[SIZE], FRONT = -1, REAR = -1;

void enqueue()
{
    int item;
    if (REAR>SIZE-1)
    {
        printf("Queue full!\n");
    }
    else
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&item);
        if (FRONT == -1 && REAR == -1)
        {
            FRONT=0;
        }
        REAR ++;
        Q[REAR]=item;
    }
}

void dequeue()
{
    int item;
    if (FRONT == -1)
    {
        printf("Queue empty!\n");
    }
    else
    {
        item = Q[FRONT];
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            FRONT++;
        }
        printf("The deleted element is : %d\n",item);
    }
}

void Display()
{
    int i;
    if (FRONT == -1)
    {
        printf("Queue empty!\n");
    }
    else
    {
        printf("Elements are : ");
        for ( i = FRONT; i <= REAR; i++)
        {
        printf("%d\t",Q[i]);
        }
        printf("\n");
    }
}

int main()
{
char ch;
do
{
    printf("Press 'a' to perform enqueue.\n");
    printf("Press 'b' to perform dequeue.\n");
    printf("Press 'c' to display the queue elements.\n");
    printf("Press 'd' to exit.\n");
    printf("Enter an option (a/b/c/d) : ");
    scanf("%c",&ch);
    getchar();
    switch (ch)
    {
        case 'a': enqueue();
        break;
        case 'b' : dequeue();
        break;
        case 'c': Display();
        break;
        case 'd': break;
        default : printf("Unknown option");
    }
    getchar();
    } while (ch!='d');
    return 0;
}