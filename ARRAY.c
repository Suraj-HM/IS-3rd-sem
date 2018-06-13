#include<stdio.h>
#include<conio.h>
int a[],pos,elem,i,n;
void create()
{
 printf("enter size\n");
 scanf("%d",&n);
 printf("enter elements\n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
}
void insert()
{
 printf("enter pos\n");
 scanf("%d",&pos);
 if(pos<0||pos>n)
 {
  printf("invalid\n");
  return;
 }
 printf("enter elem\n");
 scanf("%d",&elem);
 for(i=n-1;i>=pos;i--)
 a[i+1]=a[i];
 a[pos]=elem;
 n=n+1;
}
void del()
{
 printf("enter pos\n");
 scanf("%d",&pos);
  if(pos<0||pos>=n)
 {
  printf("invalid\n");
  return;
 }
elem=a[pos];
printf("deleted item is %d\n",elem);
for(i=pos;i<n-1;i++)
a[i]=a[i+1];
n=n-1;
}
void display()
{int i;
 printf("the elem are\n");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
}
void main()
{
 int ch;
 clrscr();
 while(1)
 {
 printf("1.create2.inset3del\n");
 printf("enter choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:create();
  break;
  case 2:insert();
  break;
  case 3:del();
  break;
  case 4:display();
  break;
  default:exit(0);
 }

}
}
