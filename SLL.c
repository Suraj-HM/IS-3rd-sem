#include<stdio.h>
#include<conio.h>
int count=0;
struct node
{
 int sem;
 long int phno;
 char name[20],branch[20],usn[20];
 struct node *link;
};
typedef struct node *NODE;
NODE create(NODE first)
{
 NODE temp;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter usn name branch sem phno\n");
 scanf("%s%s%s%d%lu",temp->usn,temp->name,temp->branch,&temp->sem,&temp->phno);
 temp->link=first;
 count++;
 return temp;
}
NODE insertf(NODE first)
{
 NODE temp;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter usn name branch sem phno\n");
 scanf("%s%s%s%d%lu",temp->usn,temp->name,temp->branch,&temp->sem,&temp->phno);
 temp->link=first;
 count++;
 return temp;
}
NODE delf(NODE first)
{
 NODE temp;
 if(first==NULL)
 {
  printf("list empty\n");
  return first;
 }
 temp=first;
 temp=temp->link;
 printf("deleted details are\n");
 printf("%s\t%s\t%s\t%d\t%lu\n",first->usn,first->name,first->branch,first->sem,first->phno);
 free(first);
 count--;
 return temp;
}
NODE insertr(NODE first)
{
 NODE temp,cur;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter usn name branch sem phno\n");
 scanf("%s%s%s%d%lu",temp->usn,temp->name,temp->branch,&temp->sem,&temp->phno);
 temp->link=NULL;
 if(first==NULL)
 {
  count++;
  return temp;
 }
 cur=first;
 while(cur->link!=NULL)
 cur=cur->link;
 cur->link=temp;
 count++;
 return first;
}
NODE delr(NODE first)
{
 NODE temp,prev,cur;
 if(first==NULL)
 {
  printf("list empty\n");
  return first;
 }
 if(first->link==NULL)
 {
  printf("deleted student details are\n");
  printf("%s\t%s\t%s\t%d\t%lu\n",first->usn,first->name,first->branch,first->sem,first->phno);
  free(first);
  count--;
  return NULL;
 }
 prev=NULL;cur=first;
 while(cur->link!=NULL)
 {
  prev=cur;

  cur=cur->link;
 }
 prev->link=NULL;
 printf("deleted student details are\n");
 printf("%s\t%s\t%s\t%d\t%lu\n",cur->usn,cur->name,cur->branch,cur->sem,cur->phno);
 free(cur);
 count--;
 return first;
}
void display(NODE first)
{
 NODE cur;
 if(first==NULL)
 {
  printf("list empty\n");
  return;
 }
 cur=first;
 while(cur!=NULL)
 {
  printf("%s\t%s\t%s\t%d\t%lu\n",cur->usn,cur->name,cur->branch,cur->sem,cur->phno);
  cur=cur->link;
 }
 printf("no of students=%d\n",count);
}
void main()
{
 NODE first=NULL;
 int ch;
 clrscr();
 while(1)
 {
  printf("1 create 2 insert front 3 del front 4 insert rear 5 del rear 6 display\n");
  printf("enter choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:first=create(first);
   break;
   case 2:first=insertf(first);
   break;
   case 3:first=delf(first);
   break;
   case 4:first=insertr(first);
   break;
   case 5:first=delr(first);
   break;
   case 6:display(first);
   break;
   default:exit(0);
  }

 }
}
