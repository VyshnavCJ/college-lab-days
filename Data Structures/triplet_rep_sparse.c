#include<stdio.h>

#define MAX_VAL 101

struct triple{
	int row;
	int col;
	int val;
}sparse[MAX_VAL];



void tripletrep(int arr[1000][1000], int n, int m);
void print(int k){
	printf("The Triplet representation is/n" ):
	int i,j;
	for(i=0;i<k;i++){
		printf("%d %d %d \n",sparse[i].row,sparse[i].col,sparse[i].val);
	}
}

int main()
{
        int i,j;
        printf("Enter the Order  of the Sparse array: ");
        int n,m;
        scanf("%d %d",&n,&m);
	int arr[1000][1000];
        printf("Enter the elements: ");
        for( i=0;i<n;i++){
		for(j=0;j<m;j++)
                	scanf("%d",&arr[i][j]);
        }
        tripletrep(arr,n,m);

}






void tripletrep(int arr[1000][1000], int n , int m)
{
	int i,j,k=1;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
	               	if(arr[i][j]!=0){
			sparse[k].row=i;
			sparse[k].col=j;
			sparse[k].val=arr[i][j];
			k++;
			}
		}
	sparse[0].row=i;
	sparse[0].col=j;
	sparse[0].val=k-1;
        print(k);
}
