
// Infix expression to postfix expression conversion

#include<stdio.h>
#include<conio.h>
#include<string.h>
int F(char symbol)
{
 switch(symbol)
 {
  case '+':
  case '-':return 2;
  case '*':
  case '/':return 4;
  case '^':
  case '$':return 5;
  case '(':return 0;
  case '#':return -1;
  default:return 8;
 }
}
int G(char symbol)
{
 switch(symbol)
 {
  case '+':
  case '-':return 1;
  case '*':
  case '/':return 3;
  case '^':
  case '$':return 6;
  case '(':return 9;
  case ')':return 0;
  default:return 7;
 }
}
void infixpostfix(char infix[],char postfix[])
{
 int top=-1,i,j=0;
 char s[50],symbol;
 s[++top]='#';
 for(i=0;i<strlen(infix);i++)
 {
  symbol=infix[i];
  while(F(s[top])>G(symbol))
  postfix[j++]=s[top--];
  if(F(s[top])!=G(symbol))
  s[++top]=symbol;
  else
  top--;
 }
 while(s[top]!='#')
 postfix[j++]=s[top--];
 postfix[j]='\0';
}
void main()
{char infix[40],postfix[40];
 clrscr();
 printf("enter infix\n");
 gets(infix);
 infixpostfix(infix,postfix);
 printf("infix is\n");
 puts(infix);
 printf("postfix is \n");
 puts(postfix);
 getch();
}
