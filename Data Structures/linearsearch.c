#include<stdio.h>
int main()
{
int a[10],i,n,search,flag=0;
printf("Enter the array limit");
scanf("%d",&n);
printf("enter array elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the element to be searched:");
scanf("%d",&search);
for(i=0;i<n;i++)
{
if(a[i]==search)
{
flag=flag+1;
printf("%d is found at posiion %d",search,i+1);
break;
}
}
if(flag==0)
printf("not found");
return 0;
}
