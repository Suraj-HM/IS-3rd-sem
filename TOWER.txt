#include<conio.h>
#include<stdio.h>
#include<math.h>
void tower(int n,int source,int temp,int dest)
{
 if(n==0)return;
 tower(n-1,source,dest,temp);
 printf("move disc %d from %c to %c \n",n,source,dest);
 tower(n-1,temp,source,dest);
}
void main()
{int n;
 clrscr();
 printf("enter no of discs\n");
 scanf("%d",&n);
 tower(n,'A','B','C');
 printf("no of moves=%d\n",(int)(pow(2,n)-1));
 getch();
}
