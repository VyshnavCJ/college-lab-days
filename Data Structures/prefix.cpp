#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
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
double operation(char c,double x,double y)
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
printf("Enter the prefix expression: ");
char prefix[100];
scanf("%s",prefix);
int n=strlen(prefix)-1;
char item;
char op;
double result;
double x,y;
while(n!=-1)
{
    item=prefix[n];
  if(check(item)){
   push(item-'0');
  }
else
{
op=item;
x=pop();
y=pop();
result=operation(op,x,y);
push(result);
}
n--;
}
double value=pop();
printf("The result of prefix expression is %f\n",value);
return 0;
}
