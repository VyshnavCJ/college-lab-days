vb#include<stdio.h>

int main()
{
	int arr[1000],i;
        printf("Enter the number of the elements you want: ");
        int n;
        scanf("%d", &n);
	printf("Enter the elements: ");
        for( i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
        printf("Enter the element you want to find: ");
      	int find =0;
	scanf("%d",&find);
        int flag=-1;
	int upbound=n;
	int lowbound=0;
	int middle;
	while(flag==-1)
	{
		if(lowbound>upbound){
			break;
		}
		middle = (upbound+lowbound)/2;
        	if(arr[middle]<find)
			lowbound=middle+1;
		if(arr[middle]>find)
			upbound=middle-1;
		if(arr[middle]==find){
			flag=middle;
			break;
		}

	}
	if(flag==-1)
		printf("The element is not present in the array \n");
	else
		printf("The element %d was found in the position %d \n", find,flag+1);




}


