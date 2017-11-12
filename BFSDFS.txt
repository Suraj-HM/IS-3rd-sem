#include<stdio.h>
#include<conio.h>
int a[10][10],visited[10],v,u,n;
void create()
{
 int i,j;
 printf("enter no nodes\n");
 scanf("%d",&n);
 printf("enter adjacency matrix\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 }
}
void bfs(int u)
{
 int q[10],f=0,r=-1;
 printf("nodes reachablr from %d are\n",u);
 printf("%d\t",u);
 visited[u]=1;
 q[++r]=u;
 while(f<=r)
 {
  u=q[f++];
  for(v=1;v<=n;v++)
  {
   if(a[u][v]==1&&visited[v]==0)
   {
    printf("%d\t",v);
    visited[v]=1;
    q[++r]=v;
   }
  }
 }
}
void dfs(int u)
{
 int v;
 printf("%d\t",u);
 visited[u]=1;
 for(v=1;v<=n;v++)
 {
  if(a[u][v]==1&&visited[v]==0)
  dfs(v);
 }
}
void main()
{
 int ch,source,i;
 clrscr();
 while(1)
 {
  printf("1 create 2 bfs 3 dfs\n");
  printf("enter choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:create();
   break;
   case 2:for(i=1;i<=n;i++)
   visited[i]=0;
   printf("enter source\n");
   scanf("%d",&u);
   bfs(u);
   break;
   case 3:for(i=1;i<=n;i++)
   visited[i]=0;
   printf("enter source\n");
   scanf("%d",&source);
   dfs(source);
   for(i=1;i<=n;i++)
   {
    if(visited[i]==0)
   {
     printf("Not connected");break;
    }
    else
    {
     printf(("connected");
    }
    }
    break;
   default:exit(0);
  }
 }
}

