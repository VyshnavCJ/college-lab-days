#include<stdio.h>
#include<stdlib.h>

typedef struct node1{
    int data;
    struct node1*link;
}node;

node* FRONT, *REAR, *header;

void CreateNode(){
    header = (node*) malloc(sizeof(node));
    header->link = NULL;
}

void TraverseNode(){
    if(FRONT==NULL){
        printf("Empty set");
    }
    else{
        node* ptr = FRONT;
        printf("The element are: \n");
        while(ptr!=NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
    }
    printf("\n");
}



void DeleteQ(){
    if(FRONT==NULL){
        printf("The Queue is empty!\n");
    }else{
        printf("%d\n",FRONT->data);
        header->link = FRONT->link;   
        free(FRONT);
        FRONT = header->link;
    }
}

void InsertQ(int data){
    node* new = (node*) malloc(sizeof(node));
    new->data = data;
    new->link = NULL;
    if(header->link==NULL){
        header->link  = new;
        FRONT = new;
        REAR = new;
    }
    else{
        REAR->link = new;
        REAR = new;
    }
}






int main()
{
    CreateNode();
    int y;
    char c;
    int option;
    printf("Operations\n1 - DeleteQ\n2 - InsertQ\n3 - Display\n");
    do
    {
        printf("Enter(1 2 3) :");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            DeleteQ();
            break;
        case 2:
            printf("Enter data :");
            scanf("%d", &y);
            InsertQ(y);
            break;
        case 3:
            TraverseNode();
            break;
        default:
            printf("Wrong option");
            break;
        }

        printf("Do want to perform more operations ?(y/n) :");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
    return 0;
}