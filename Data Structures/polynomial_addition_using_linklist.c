#include<stdio.h>
#include<stdlib.h>


typedef struct poly1
{
    int coeff;
    int exp;
    struct poly1 *next;
}poly;

void display(poly* header);
poly* Qheader, *Pheader, *Rheader;

poly* getnode(){
    poly* temp = (poly*)malloc(sizeof(poly));
    temp->coeff = 0;
    temp->exp = 0;
    temp->next = NULL;
    return temp;
}

poly* Createpolynomial(){
    printf("Enter the degree of the poynomial: ");
    int n;
    scanf("%d",&n);
    poly* header = getnode();
    poly* ptr1 = header;
    for(int i=n;i>=0;i--){
        printf("Enter the value: ");
        int x;
        scanf("%d",&x);
        if (x==0)
            continue;
        poly* temp = getnode();
        temp->coeff = x;
        temp->exp = i;
        ptr1->next = temp;
        ptr1 = ptr1->next;
    }
    return header;
}

void polyadd(){
    Rheader= getnode();
    poly* Rptr = Rheader;
    poly* Pptr = Pheader->next;
    poly* Qptr = Qheader->next;
    while (Pptr!=NULL && Qptr!=NULL)
    {
        if(Pptr->exp==Qptr->exp){
            poly* new = getnode();
            new->exp = Pptr->exp;
            new->coeff = Pptr->coeff +  Qptr->coeff;
            Pptr = Pptr->next; Qptr = Qptr->next;
            Rptr->next = new;
            Rptr = Rptr->next;
        }
        else if(Pptr->exp > Qptr->exp){
            poly* new = getnode();
            new->exp = Pptr->exp;
            new->coeff = Pptr->coeff;
            Pptr = Pptr->next;
            Rptr->next = new;
            Rptr = Rptr->next;
        }
        else if(Pptr->exp < Qptr->exp){
            poly* new = getnode();
            new->exp = Qptr->exp;
            new->coeff = Qptr->coeff;
            Qptr = Qptr->next;
            Rptr->next = new;
            Rptr = Rptr->next;
        }
    }
    while(Pptr!=NULL){
        poly* new = getnode();
        new->exp = Pptr->exp;
        new->coeff = Pptr->coeff;
        Pptr = Pptr->next;
        Rptr->next = new;
        Rptr = Rptr->next;
    }
    while(Qptr!=NULL){
        poly* new = getnode();
        new->exp = Qptr->exp;
        new->coeff = Qptr->coeff;
        Qptr = Qptr->next;
        Rptr->next = new;
        Rptr = Rptr->next;
    }
}

void display(poly* header){
    printf("\n");
    poly* ptr = header->next;
    while(ptr!=NULL){
            if(ptr->next!=NULL){
                    printf("%dX^%d + ", ptr->coeff,ptr->exp);
            }
            else {
                printf("%dX^%d ", ptr->coeff,ptr->exp);
            }
        ptr = ptr->next;
    }
}

int main(){
    printf("First polynomial!\n");
    Pheader = Createpolynomial();
    display(Pheader);
    printf("\n");
    printf("Second polynomial!\n");
    Qheader = Createpolynomial();
    printf("\n");
    display(Qheader);
    printf("\n");
    polyadd();
    display(Rheader);
}