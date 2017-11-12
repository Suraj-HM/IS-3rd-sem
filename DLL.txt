#include<stdio.h>
#include<conio.h>
struct node
{
 int info,ssn,sal;
 char name[20],dept[20],desig[20];
 long int phno;
 struct node *llink,*rlink;
};
typedef struct node *NODE;
NODE create(NODE head)
{
 NODE temp,cur;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter ssn name dept deignation salary phno\n");
 scanf("%d%s%s%s%d%lu",&temp->ssn,temp->name,temp->dept,temp->desig,&temp->sal,&temp->phno);
 cur=head;
 while(cur->rlink!=NULL)
 cur=cur->rlink;
 cur->rlink=temp;
 temp->llink=cur;
 temp->rlink=NULL;
 head->info++;
 return head;
}
NODE insertf(NODE head)
{
 NODE temp,cur;
  temp=(struct node*)malloc(sizeof(struct node));
 printf("enter ssn name dept deignation salary phno\n");
 scanf("%d%s%s%s%d%lu",&temp->ssn,temp->name,temp->dept,temp->desig,&temp->sal,&temp->phno);
 cur=head->rlink;
 head->rlink=temp;
 temp->llink=head;
 temp->rlink=cur;
 cur->llink=temp;
 head->info++;
 return head;
}
NODE insertr(NODE head)
{
 NODE temp,cur;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter ssn name dept deignation salary phno\n");
 scanf("%d%s%s%s%d%lu",&temp->ssn,temp->name,temp->dept,temp->desig,&temp->sal,&temp->phno);
 cur=head;
 while(cur->rlink!=NULL)
 cur=cur->rlink;
 cur->rlink=temp;
 temp->llink=cur;
 temp->rlink=NULL;
 head->info++;
 return head;
}
NODE delf(NODE head)
{
 NODE cur,next;
 if(head->rlink==NULL)
 {
  printf("list empty\n");
  return head;
 }
 cur=head->rlink;
 next=cur->rlink;
 head->rlink=next;
 next->llink=head;
 printf("deleted employee details are\n");
 printf("%d\t%s\t%s\t%s\t%d\t%lu\n",cur->ssn,cur->name,cur->dept,cur->desig,cur->sal,cur->phno);
 free(cur);
 head->info--;
 return head;
}
NODE delr(NODE head)
{
 NODE cur,prev;
 if(head->rlink==NULL)
 {
  printf("list empty\n");
  return head;
 }
 cur=head->rlink;
 while(cur->rlink!=NULL)
 cur=cur->rlink;

 prev=cur->llink;
 prev->rlink=NULL;
 printf("deleted employee details are\n");
 printf("%d\t%s\t%s\t%s\t%d\t%lu\n",cur->ssn,cur->name,cur->dept,cur->desig,cur->sal,cur->phno);
 free(cur);
 head->info--;
 return head;
}
void display(NODE head)
{
 NODE cur;
 if(head->rlink==NULL)
 {
  printf("list empty\n");
  return;
 }
 cur=head->rlink;
 while(cur!=NULL)
 {
  printf("%d\t%s\t%s\t%s\t%d\t%lu\n",cur->ssn,cur->name,cur->dept,cur->desig,cur->sal,cur->phno);
  cur=cur->rlink;
 }
 printf("no of emplyees=%d\n",head->info);
}
void main()
{
 NODE head;
 int ch;
 clrscr();
 head=(struct node*)malloc(sizeof(struct node));
 head->info=0;
 head->rlink=head->llink=NULL;
 while(1)
 {
  printf("1 create 2 insert front 3 insert rear 4 del front 5 del rear 6 display\n");
  printf("enter choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:head=create(head);
   break;
   case 2:head=insertf(head);
   break;
   case 3:head=insertr(head);
   break;
   case 4:head=delf(head);
   break;
   case 5:head=delr(head);
   break;
   case 6:display(head);
   break;
   default:exit(0);
  }
 }
}
