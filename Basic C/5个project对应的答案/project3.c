#include<stdio.h>
#include<string.h>
#define max 100
char next[max][max];
void read_soc(char soc[][max],int size)
{
	int i,j;
	char a;
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			while((a=getchar())==' '||a=='\n');
			soc[i][j]=a;
		}
	}
}
void prt_soc(char soc[][max],int size)
{
	int i,j;
	printf("/");
	for(i=1;i<=2*size+1;i++)
	printf("o");
	printf("\\\n");
	for(i=1;i<=size;i++)
	{
		printf("|");
		for(j=1;j<=size;j++)
		{
			printf(" %c",soc[i][j]);
		}
		printf(" |\n");
	}
	printf("\\");
	for(i=1;i<=2*size+1;i++)
	printf("o");
	printf("/");
	printf("\n");
}
void population(char soc[][max],int size)
{
	int i,j,sum=0;
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			if(soc[i][j]=='*')
			sum++;
		}
	}
	printf("The number of inhabitants is: %d\n",sum);
}
int generate(char soc[][max])
{
	if(memcmp(soc,next,sizeof(char)*max*max)==0)
	return 0;
	return 1;
}
void destiny(char soc[][max],int row,int col)
{
	int i,j,sum=0;
	for(i=row-1;i<=row+1;i++)
	{
		for(j=col-1;j<=col+1;j++)
		{
			if(i==row&&j==col)
			continue;
			if(soc[i][j]=='*')
			sum++;
		}
	}
	if(soc[row][col]=='*'&&sum<2)
	next[row][col]='-';
	else if(soc[row][col]=='*'&&sum>3)
	next[row][col]='-';
	else if(soc[row][col]=='-'&&sum==3)
	next[row][col]='*';
}
int evolve_soc(char soc[][max],int size,int r)
{ 
    int i,j;
    memcpy(next,soc,sizeof(char)*max*max);
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		destiny(soc,i,j);
	}
	if(r==1&&generate(soc)==0)
	return 0;
	memcpy(soc,next,sizeof(char)*max*max);
	return 1;
}
void census(char soc[][max],int size,int pop[])
{
	int i,j;
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			if(soc[i][j]=='*')
			pop[i]++;
		}
	}
}
void migrate(int pop[],int a[][max],int size,char soc[][max])
{
	int i,j,m;
	for(i=1;i<=size;i++)
	a[pop[i]][i]++;
	printf("After migration:\n");
	for(i=1;i<=16;i++)
	printf("+");
	printf("\n");
	printf("/");
	for(i=1;i<=2*size+1;i++)
	printf("o");
	printf("\\\n");
	for(i=size;i>=0;i--)
	{
		for(j=1;j<=size;j++)
		{
			if(a[i][j]==0)
			{
				printf("|");
				for(m=1;m<=size;m++)
				printf(" %c",soc[j][m]);
				printf(" |\n");
			}
		}
	}
	printf("\\");
	for(i=1;i<=2*size+1;i++)
	printf("o");
	printf("/");
	printf("\n");
}
int main()
{
	int n,i,j,m,s=1,pop[max]={0},a[max][max];
	char soc[max][max];
	memset(soc,'-',sizeof(soc));
	memset(a,-1,sizeof(a));
	printf("Read the boundary size:");
	scanf("%d",&n);
	printf("Bulid the society.\n");
	read_soc(soc,n);
	printf("\nNew life:\n\n");
	prt_soc(soc,n);
	population(soc,n);
	printf("\n\nAfter One Evolution:\n");
	for(i=1;i<=20;i++)
	printf("+");
	printf("\n");
	evolve_soc(soc,n,0);
	prt_soc(soc,n);
	population(soc,n);
	printf("\n\n");
	scanf("%d",&m);
	printf("\nEvolution begins:\n");
	for(i=1;i<=17;i++)
	printf("+");
	printf("\n");
	for(i=1;i<=m;i++)
	{
		if(evolve_soc(soc,n,1)==0)
		{
			prt_soc(soc,n);
			population(soc,n);
			printf("society stabilizes at %d evolutions",i-1);
			s=0;
			break;
		}
	}
	if(s)
	{
		prt_soc(soc,n);
		population(soc,n);
		printf("Evolution continues after %d evolutions.\n",m);
	}
	printf("\n\n\nCensus Result:\n");
	for(i=1;i<=14;i++)
	printf("+");
	printf("\n[");
	census(soc,n,pop);
	for(i=1;i<=n;i++)
	printf(" %d",pop[i]);
	printf(" ]\n\n\n");
	migrate(pop,a,n,soc);
	population(soc,n);
}