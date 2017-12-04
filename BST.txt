#include<stdio.h>
#include<conio.h>
struct node
{
 char info;
 struct node *llink,*rlink;
};
typedef struct node *NODE;
NODE insert(int item,NODE root)
{
 NODE temp,cur,prev;
 temp=(struct node*)malloc(sizeof(struct node));
 temp->llink=temp->rlink=NULL;
 temp->info=item;
 if(root==NULL)
 {
  return temp;
 }
 prev=NULL;
 cur=root;
 while(cur!=NULL)
 {prev=cur;
  if(item<cur->info)
  cur=cur->llink;
  else
  cur=cur->rlink;
 }
 if(item<prev->info)
 prev->llink=temp;
 else
 prev->rlink=temp;
 return root;
}
NODE search(int item,NODE root)
{
 NODE cur;
 cur=root;
 while(cur!=NULL)
 {
  if(item==cur->info)
  {
   printf("key found\n");
   return root;
  }
  if(item<cur->info)
  cur=cur->llink;
  else
  cur=cur->rlink;
 }
 if(cur==NULL)
 printf("key not found\n");
 return root;
}
void preorder(NODE root)
{
 if(root==NULL)return;
 printf("%d\t",root->info);
 preorder(root->llink);
 preorder(root->rlink);
}
void inorder(NODE root)
{
 if(root==NULL)return;
 inorder(root->llink);
 printf("%d\t",root->info);

 inorder(root->rlink);
}
void postorder(NODE root)
{
 if(root==NULL)return;

 postorder(root->llink);
 postorder(root->rlink);
 printf("%d\t",root->info);
}
NODE dele(int item,NODE root)
{
	NODE cur,p,suc,q;
	
	if(root == NULL)
	{
		printf("tree is empty");
		return root;
	}	
	p=NULL;
	cur=root;
		while(cur != NULL)
		{
				if(item == cur->info)
				break;
				p=cur;
				//cur = (item < cur->info) ? cur->llink : cur->rlink ;
				if (item < cur->info)
				cur=cur->llink;
				else
				cur=cur->rlink;
		}
		if (cur==NULL)
		{
			printf("item not found");
			return root;
		}	
		if (cur->llink==NULL)
		q = cur->rlink;
		else if (cur->rlink == NULL)
		q= cur->llink;		
		else
		{
			suc = cur->rlink;
		}
	while( suc->llink != NULL)
	{
		suc = suc->llink;
	}
		suc->llink=cur->llink;
		q=cur->rlink;
			if(p==NULL)
			return q;
			if(cur == p->llink)
			p->llink=q;
			else
			p->rlink=q;
			
	free(cur);
	printf("deleted ele is %d",item);
	return root;	
}
void main()
{
 int ch,item;
 NODE root=NULL;
 clrscr();
 while(1)
 {
  printf("1 insert 2 search 3 preoerdr 4 inorder 5 postorder\n");
  printf("enter choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("enter item\n");
   scanf("%d",&item);
   root=insert(item,root);
   break;
   case 2:printf("enter item\n");
   scanf("%d",&item);
   root=search(item,root);
   break;
   case 3:if(root==NULL)
   printf("tree empty\n");
   else
   {
    printf("preorder traversal\n");
    preorder(root);
   }
   break;
    case 4:if(root==NULL)
   printf("tree empty\n");
   else
   {
    printf("inorder traversal\n");
    inorder(root);
   }
   break;
    case 5:if(root==NULL)
   printf("tree empty\n");
   else
   {
    printf("postorder traversal\n");
    postorder(root);
   }
   break;
   default:exit(0);
  }
 }
}
