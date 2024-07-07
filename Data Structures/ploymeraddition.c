#include<stdio.h>
typedef struct{
        int coeff;
        int exp;
}poly;

void main()
{
        poly p[10],q[10],r[20];
        int i=0,j=0,k=0,m,n;
        printf("Enter number of term in poly A :");
        scanf("%d",&n);
        printf("Enter number of term in poly B :");
        scanf("%d",&m);
        printf("Enter the coeff and exp of poly A:\n");
        for(i=0;i<n;i++)
        {
                scanf("%d%d",&p[i].coeff,&p[i].exp);
        }
        printf("Enter the coeff and exp of poly B:\n");
        for(i=0;i<m;i++)
        {
                scanf("%d%d",&q[i].coeff,&q[i].exp);
        }
        i=0;

	while(i<n && j<m)
        {
               	if(p[i].exp==q[j].exp)
               	{
                       	r[k].coeff=p[i].coeff + q[j].coeff;
                       	r[k].exp=p[i].exp;
                       	i++,j++,k++;
               	}
               	else if(p[i].exp>q[j].exp)
               	{
                        r[k].coeff=p[i].coeff;
                       	r[k].exp=p[i].exp;
                       	i++,k++;
               	}
               	else
               	{
                       	r[k].coeff=q[j].coeff;
                       	r[k].exp=q[j].exp;
                       	j++,k++;
               	}

	}
        while(i<n)
        {
               	r[k].coeff=p[i].coeff;
               	r[k].exp=p[i].exp;
               	i++,k++;
       	}
        while(j<m)
       	{
               	r[k].coeff=q[j].coeff;
               	r[k].exp=q[j].exp;
               	j++,k++;
	}
	printf("The Resultant polynomial is\n");
       	for(i=0;i<k;i++)
        {
		printf("%dx^%d",r[i].coeff,r[i].exp);
		if(i!=(k-1))
			printf(" + ");
       	}
	printf("\n");

}
