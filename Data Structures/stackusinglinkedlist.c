#include<stdio.h>
#include<stdlib.h>

typedef struct node1{
    int data;
    struct node1*link;
}node;

node* TOP=NULL,*header;

void CreateNode(){
    header = (node*) malloc(sizeof(node));
    header->link = NULL;
}

void TraverseNode(){
    if(TOP==NULL){
        printf("Empty set");
    }
    else{
        node* ptr = TOP;
        printf("The element are: \n");
        while(ptr!=NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
    }
    printf("\n");
}

void POP(){
    if(TOP==NULL){
        printf("The stack is empty!\n");
    }else{
        node* ptr = TOP->link;
        printf("%d\n",TOP->data);
        header->link = ptr;
        free(TOP);
        TOP = ptr;
    }
}

void PUSH(int data){
    node* ptr = (node*) malloc(sizeof(node));
    ptr->data = data;
    ptr->link = TOP;
    TOP = ptr;
    header->link = TOP;
}





int main()
{
    CreateNode();
    int y;
    char c;
    int option;
    printf("Operations\n1 - POP\n2 - PUSH\n3 - Display\n");
    do
    {
        printf("Enter(1 2 3) :");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            POP();
            break;
        case 2:
            printf("Enter data :");
            scanf("%d", &y);
            PUSH(y);
            break;
        case 3:
            TraverseNode();
            break;
        default:
            printf("Wrong option\n");
            break;
        }

        printf("Do want to perform more operations ?(y/n) :");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
    return 0;
}