#include<stdio.h>
#include<string.h>
#define SIZE 100
int top=-1,stack[SIZE];
void push(double x)
{
  if(top==SIZE-1)
    printf("Stack overflow\n");
  else 
    stack[++top]=x;
}
double pop()
{
  if(top==-1)
       {
         printf("Stack underflow\n");
        return 0;
       }

 else{
       return  stack[top--];
     }
  }
double operator(char c,double x,double y)
{
double result;
switch(c)
{
  case '+':result= x+y; 
  break;
  case '*':result= x*y;
  break;
  case '/':result= x/y;
  break;
  case '-':result= x-y;
  break;
 default:printf("Wrong input");
}
return result;
}
int check(char c)
{
  switch(c)
  {
    case '+':return 0;
    break;
    case '*':return 0;
   break;
   case '/':return 0;
   break;
   case '-':return 0;
   break;
   default: return 1;
  }
}
int main()
{ 
printf("Enter the postfix expression: ");
char postfix[100];
scanf("%s",postfix);
int n=strlen(postfix);
postfix[n]='#';
int i=0;
char item=postfix[0];
char op;
double result;
double x,y;
while(item!='#')
{
  if(check(item)){
   push(item-'0');
}
else
{
op=item;
y=pop();
x=pop();
result=operator(op,x,y);
push(result);
}
item=postfix[++i];
}
double value=pop();
printf("The result of postfix expression is %f\n",value);
return 0;
}
