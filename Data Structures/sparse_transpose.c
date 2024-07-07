
#include<stdio.h>

#define MAX_VAL 101

struct triple{
        int row;
        int col;
        int val;
}sparse[MAX_VAL],sparsetrans[MAX_VAL];

void print(int n){
        int i,j;
        for(i=0;i<=n;i++){
                printf("%d %d %d \n",sparsetrans[i].row,sparsetrans[i].col,sparsetrans[i].val);
        }
}


void trans(int n){
        sparsetrans[0].row=sparse[0].col;
        sparsetrans[0].col=sparse[0].row;
        sparsetrans[0].val=sparse[0].val;
        int q=1;
        int i=0;
        for(i=0;i<sparse[0].col;i++){
        	int j;
                for(j=1;j<=n;j++){
                	if(sparse[j].col==i){
				sparsetrans[q].row=sparse[j].col;
				sparsetrans[q].col=sparse[j].row;
				sparsetrans[q].val=sparse[j].val;
				q++;
                	}
                }
        }
	printf("\n The transpose sparse triplet representaion is: \n");
	print(n);


}


int main()
{
        printf("Enter the number of non negative terms in the sparse matrix: ");
        int n;
        scanf("%d", &n);
        printf("Enter the triple representaion of the  sparse matrix: ");
        int i;
        for(i=0;i<=n;i++){
                scanf("%d %d %d",&sparse[i].row,&sparse[i].col,&sparse[i].val);
        }
        trans(n);

	return 0;
}
