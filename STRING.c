#include<conio.h>
#include<stdio.h>
int i,j,k,c,m,flag=0;
char str[100],pat[50],rep[50],ans[100];
void stringmatch()
{
 i=j=c=m=0;
 while(str[c]!='\0')
 {
  if(str[m]==pat[i])
  {
   m++;i++;
   if(pat[i]=='\0')
   {
    flag=1;
    for(k=0;rep[k]!='\0';k++,j++)
    ans[j]=rep[k];
    i=0;c=m;
   }
  }
  else
  {
   ans[j]=str[c];
   j++;c++;
   i=0;m=c;
  }
  ans[j]='\0';
 }
}
void main()
{
 int ch;
 clrscr();
 printf("enter source\n");
 gets(str);
 printf("enter pat\n");
 gets(pat);
 printf("enter rep\n");
 gets(rep);
 stringmatch();
 if(flag==1)
 printf("resultant is %s",ans);
 else
 printf("pat not found\n");
 getch();
}
