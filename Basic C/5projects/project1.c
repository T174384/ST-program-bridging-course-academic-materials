#include<stdio.h>
void geshi(int n)
{
	int i;
	for(i=1;i<=n-1;i++)
	printf("---");
	printf("\n   |");
	for(i=1;i<=n-1;i++)
	printf("%3d",i);
	printf("\n---+");
	for(i=1;i<=n-1;i++)
	printf("---");
	printf("\n");
}
int main()
{
	int n,i,j,a[500][500]={0},b[500]={0},k;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Out Multiplication Table\n---+");
	geshi(n);
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if(j==0)
			printf("%3d|",i);
			else
			printf("%3d",i*j%n);
		}
		printf("\n");
	}
	printf("---+");
	for(i=1;i<=n-1;i++)
	printf("---");
	printf("\nOut Inverse Table\n---+");
	geshi(n);
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if(j==0)
			printf("%3d|",i);
			else if(i*j%n==1)
			printf("  *");
			else
			printf("   ");
		}
		printf("\n");
	}
	printf("---+");
	for(i=1;i<=n-1;i++)
	printf("---");
	printf("\nOutput Quadratic Residue\n---+");
	for(i=1;i<=n-1;i++)
	printf("---");
	printf("\n");
	for(i=1;i<=n-1;i++)
	{
		a[i*i%n][b[i*i%n]]=i;
		b[i*i%n]++;
	}
	for(i=1,k=1;i<=n-1;i++,k++)
	{
		if(a[i][0]==0)
		continue;
		else
		printf("%3d|",i);
		for(j=0;;j++)
		{
			if(a[i][j]==0)
			break;
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	printf("---+");
	for(i=1;i<=n-1;i++)
	printf("---");
	printf("\nOutput Fractal\n   ");
	for(i=1;i<=n;i++)
	printf("%d",i/10);
	printf("\n   ");
	for(i=1;i<=n;i++)
	printf("%d",i%10);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%3d",n+1-i);
		for(j=1;j<=n;j++)
		{
			if(j<=n+1-i)
			{
				printf(" ");
				continue;
			}
			for(k=1;k<=j-1;k++)
			{
				if(k*k%j==n+1-i)
				{
				printf("@");
				break;
			}
			   if(k==j-1)
			   printf(".");
			}
		}
		printf("\n");
	}
}