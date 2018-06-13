#include<conio.h>
#include<stdio.h>
#define MAX 4
int q[MAX],count=0,f=0,r=-1,item;
void push()
{
 if(count==MAX)
 {
  printf("overflow\n");
  return;
 }
 else
 {
  r=(r+1)%MAX;
  q[r]=item;
  count++;
 }
}
void pop()
{
 if(count==0)
 {
  printf("underflow\n");
  return;
 }
 else
 {
  printf("deleted ele is %d\n",q[f]);
  f=(f+1)%MAX;
  count--;
 }
}
void display()
{
 int i,j;
 if(count==0)
 {
  printf("q empty\n");
  return;
 }
 else
 {
  j=f;
  for(i=1;i<=count;i++)
  {
   printf("%d\t",q[j]);
   j=(j+1)%MAX;
  }
 }
}
void main()
{
 int ch;
 clrscr();
 while(1)
 {
  printf("1 push 2 pop 3 display\n");
  printf("enter choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("enter item to isert\n");
   scanf("%d",&item);
   push();
   break;
   case 2:pop();
   break;
   case 3:display();
   break;
   default:exit(0);
  }
 }
}
