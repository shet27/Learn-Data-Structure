#include<stdio.h>
#include<math.h>
#define MAX 20

int a[20][20],s[20], n,i,j,visited[20],reach[10],top=-1,count=0;

/*********Reachability using DFS**********/

void Reachability(int v)
{
	for(i=1;i<=n;i++)
		if(a[v][i] && !visited[i])
			s[++top]=i;
		if(top>=0)
		{
			visited[s[top]]=1;
			Reachability(s[top--]);
		}
}

/********Connectivity using DFS***********/
// to insert the verices which are visited

void Connectivity(int v)
{
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++)
	{
		if(a[v][i] && !reach[i])
		{
			printf("\n %d->%d",v,i);
			count++;
			Connectivity(i);
		}
	}
}

void main()
{
	int v, choice;
	printf("\n Enter the number of cities: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s[i]=0;
		visited[i]=0;
		reach[i]=0;
	}	
	printf("\n Enter graph data in matrix form:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	while(1)
	{
	 printf("\n----------------------------Menu------------------------------------------------");
	 printf("\n1.Test for reachability") ;
	 printf("\n2.Test for connectivity") ;
printf("\n3.Exit");
	 printf("\nEnter Your Choice: ");
	scanf("%d",&choice);
	 switch(choice)
	 {
		  case 1:printf("Enter the source vertex: ");
			 scanf("%d",&v);
			 if((v<1)||(v>n))
			 {
				printf("\nEnter a valid source vertex");
			 }
			 else
			{
				for(i=1;i<=n;i++)
				{
					s[i]=0;
					visited[i]=0;
					reach[i]=0;
				}
				visited[v]=1;
				Reachability(v);
			           printf("The reachable nodes from node %d:\n",v);
			for(i=1;i<=n;i++)
					if(visited[i] &&  i !=v)
						printf("node %d\n",i);
			}
			break;
		case 2: for(i=1;i<=n;i++)
				reach[i]=0;
				Connectivity(1);
				if(count==n-1)
				printf("\nGraph is connected\n");
				else
				printf("\n Graph is not connected");
			break;
		case 3:return;
		  default:printf("\nEnter proper Choice");
		 }
	}
}






