#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;

typedef struct node1{
    int data;
    struct node1*link;
}node;


node* CreateNode(int n){
    node* header = (node*) malloc(sizeof(node));
    node* ptr1;
    ptr1 = header;
    header->data = 0;
    header->link = NULL;
    for(int i=0; i<n;i++){
        node* ptr2 = (node*) malloc(sizeof(node));
        printf("Enter the element: ");
        scanf("%d", &ptr2->data);
        ptr2->link = NULL;
        ptr1->link  = ptr2;
        ptr1=ptr1->link;
    }
    return header;
}

void TraverseNode(node* header){
    if(header->link==NULL){
        printf("Empty set");
    }
    else{
        node* ptr = header->link;
        printf("The element are: \n");
        while(ptr!=NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
    }
    printf("\n");
}

void DeleteNodeFirst(node* header){
    node* ptr1 = header->link;
    header->link = ptr1->link;
    free(ptr1);
}

void InsertNodeFirst(node* header, int data){
    node* ptr1 = header->link;
    node* ptr2 = (node*) malloc(sizeof(node));
    ptr2->data = data;
    header->link = ptr2;
    ptr2->link = ptr1;
}


void DeleteNodeEnd(node* header){
    node* ptr1 = header;
    while(ptr1->link->link!=NULL)
        ptr1=ptr1->link;
    node* ptr2 = ptr1->link;
    ptr1->link = NULL;
    free(ptr2);
}

void InsertNodeEnd(node* header, int data){
    node* ptr1 = header;
    while(ptr1->link!=NULL)
        ptr1=ptr1->link;
    node* ptr2 = (node*) malloc(sizeof(node));
    ptr2->link = NULL;
    ptr2->data = data;
    ptr1->link = ptr2;
}



void DeleteNode(node* header, int key){
    node* ptr1 = header;
    node* ptr2;
    int postion=0;
    while(ptr1->link->data!=key && ptr1->link!=NULL){
        ptr1=ptr1->link;
        postion++;
    }
    if(ptr1->link->data==key){
        if(ptr1->link->link==NULL){
            DeleteNodeEnd(header);
        }
        else if(postion==0){
            DeleteNodeFirst(header);
        }
        else{
            ptr2=ptr1->link;
            ptr1->link = ptr1->link->link;
            free(ptr2);
        }
    }
    else{
        printf("Element not present in the list\n");
    }
}

void InsertNode(node* header, int pos, int data){
    node* ptr1 = header;
    node* ptr2 = (node*) malloc(sizeof(node));
    int postion=0;
    while(postion!=(pos-1) && ptr1->link!=NULL){
        ptr1=ptr1->link;
        postion++;
    }
    if(postion==pos-1){
        if(postion==1){
            InsertNodeFirst(header,data);
        }
        else{
            ptr2->data = data;
            ptr2->link = ptr1->link;
            ptr1->link = ptr2;
        }
    }
    else{
        printf("Invalid postion\n");
    }
}

void ReverseNode(node* header){
    node* current,*prev,*next;
    current = header->link;
    prev = NULL;
    while(current!=NULL){
        next = current->link;
        current->link =prev;
        prev = current;
        current = next;
    }
    header->link=prev;
}

node* reverserec(node* header){
    if(header->link==NULL || header==NULL){
        return header;
    }
    node* temp = reverserec(header->link);
    header->link->link=header;
    header->link=NULL;
    return temp;

}

void reverseusingstack(node* header){
    if(header->link == NULL) return;
    stack<node*> S;
    node* temp = header->link;
    while(temp!=NULL){
        S.push(temp);
        temp = temp->link;
    }
    header->link = S.top();
    temp = header->link;
    S.pop();
    while(!S.empty()){
        temp->link = S.top();
        S.pop();
        temp = temp->link;
    }
    temp->link = NULL;
}



int main()
{
    printf("Enter the number of nodes you want in the linked list: ");
    int x;
    scanf("%d",&x);
    node* header = CreateNode(x);
    TraverseNode(header);
    int y;
    char c;
    int option;
    printf("Operations\n1 - Deletion from the front\n2 - Deletion from the end\n3 - Deletion from any position\n4 - Insertion from the front\n5 - Insetion from the end\n6 - Insertion from any position\n7 - Display\n8 - Reverse the list\n9 - Reverse the list through recursion\n10 - Reverse list using stack\n");
    do
    {
        printf("Enter(1 2 3 4 5 6 7 8 9 10) :");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            DeleteNodeFirst(header);
            break;
        case 2:
            DeleteNodeEnd(header);
            break;
        case 3:
            printf("Enter key :");
            scanf("%d", &y);
            DeleteNode(header,y);
            break;
        case 4:
            printf("Enter data :");
            scanf("%d", &y);
            InsertNodeFirst(header,y);
            break;
        case 5:
            printf("Enter data :");
            scanf("%d", &y);
            InsertNodeEnd(header,y);
            break;
        case 6:
            printf("Enter the position and data :");
            int pos;
            scanf("%d %d",&pos,&y);
            InsertNode(header,pos,y);
            break;
        case 7:
            TraverseNode(header);
            break;
        case 8:
            ReverseNode(header);
            break;
        case 9:
            header = reverserec(header);
            break;
        case 10:
            reverseusingstack(header);
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