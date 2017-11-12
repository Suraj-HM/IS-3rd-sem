#include<stdio.h>
#include<conio.h>
#include<string.h>
#define HASH_SIZE 100
typedef struct employee
{
 int id;
 char name[20];
}EMPLOYEE;
void initialize(EMPLOYEE a[])
{
 int i;
 for(i=0;i<HASH_SIZE;i++)
 {
  a[i].id=0;
  strcpy(a[i].name,'\0');
 }
}
int H(int k)
{
 return k%HASH_SIZE;
}
void insert(int id,char name[],EMPLOYEE a[])
{
 int h_value,index,i;
 h_value=H(id);
 for(i=0;i<HASH_SIZE;i++)
 {
  index=(h_value+i)%HASH_SIZE;
  if(a[index].id==0)
  {
   a[index].id=id;
   strcpy(a[index].name,name);
   break;
  }
 }
 if(i==HASH_SIZE)printf("hash table full\n");
}
void display(EMPLOYEE a[],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  if(a[i].id!=0)
  printf("a[%d]=%d\t%s\n",i,a[i].id,a[i].name);
 }
}
void main()
{
 int ch,id;
 char name[20];
 EMPLOYEE a[100];
 clrscr();
 initialize(a);
 while(1)
 {
 printf("1 insert 2 display\n");
 printf("enter choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:printf("enter id\n");
  scanf("%d",&id);
  printf("enter name\n");
  scanf("%s",name);
  insert(id,name,a);
  break;
  case 2:display(a,HASH_SIZE);
  break;
  default:exit(0);
 }
}
}
