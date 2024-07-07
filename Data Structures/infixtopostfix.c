#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 100
int top=-1;
char stack[SIZE];
void push(char x)
{
if(top==SIZE-1)
   printf("Stack overflow");
else 
   stack[++top]=x;
}
char pop()
{
if(top==-1)
{
printf("Stack underflow");
return '0';
}
else 
return stack[top--];
}
int check(char c)
{
switch(c)
{
case'+':
case'*':
case'/':
case'-':
case'^':
case'(':
case')':return 0;
       break;
default:return 1;
}
}
int isp(char x)
{
switch(x)
{
case'+':
case'-':
        return 2;
       break;
case'/':
case'*':return 4;
        break;
case'^':return 5;
        break;
case'(':return 0;
        break;
default:printf("invalid expression");
}
}
int icp(char x)
{ 
switch(x)
{
case'+':
case'-':
        return 1;
       break; 
case'/':
case'*':return 3; 
        break;
case'^':return 6; 
        break;
case'(':return 7;
        break;
case ')':return 0;
       break;
default:printf("invalid expression");
} 
}
void infixtopostfix(char a[])
{
char item,x;
int i=1;
push('(');
int n= strlen(a);
while(top>-1)
{
x=pop();
item=a[i];
if(check(item))
{
printf("%c",item);
push(x);
}
else if(item==')')
{
while(x!='(')
{
printf("%c",x);
x=pop();
}
}
else if(isp(x)>=icp(item))
{
	while(isp(x)>=icp(item))
	{
	printf("%c",x);
	x=pop();
	}
push(x);
push(item);
}

else if(isp(x)<icp(item))
{
push(x);
push(item);
}
i++;
}
}

int main()
{
printf("Enter the infix expression ");
char infix[100];
scanf("%s",infix);
infixtopostfix(infix);
printf("\n");
}
