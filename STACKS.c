#include<stdio.h>
#include<conio.h>
#define MAX 4
int stack[MAX],top=-1,status=0,item;
void push()
{
 if(top==(MAX-1))
 printf("overflow\n");
 else
 {
 stack[++top]=item;
 status++;
 }
}
int pop()
{
 int ret;
 if(top==-1)
 printf("underflow\n");
 else
 {

  ret=stack[top--];
  printf("deleted ele is %d\n",ret);
  status--;
 }
 return ret;
}
void palindrome()
{
 int temp,count=0,i;
 temp=status;
 for(i=0;i<temp;i++)
 {
  if(stack[i]==pop())
  count++;
 }
  if(temp==count)
  printf("palindrome\n");
  else
  printf("not pali\n");
}
void display()
{
 int i;
 printf("stack ele are\n");
 for(i=top;i>=0;i--)
 printf("%d\n",stack[i]);
}
void main()
{
 int ch;
 clrscr();
 while(1)
 {
  printf("1 push 2 pop 3 pali 4 display\n");
  printf("enter choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("enter item\n");
   scanf("%d",&item);
   push();
   break;
   case 2:item=pop();
   break;
   case 3:palindrome();
   break;
   case 4:display();
   break;
   default:exit(0);
  }
  getch();
 }
}
