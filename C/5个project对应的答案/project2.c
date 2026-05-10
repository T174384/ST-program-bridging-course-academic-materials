#include<stdio.h>
void prt_set(int set[],int size)
{
	int i;
	printf("{");
	for(i=0;i<=size-1;i++)
	{
	    printf("%d",set[i]);
	    if(i<size-1)
	    printf(",");
    }
    printf("}.");
}
void scan_set(int set[],int size)
{
    int i;
	for(i=0;i<=size-1;i++)
	scanf("%d",&set[i]);
}
int is_member(int item,int set[],int size)
{
	int i;
	for(i=0;i<=size-1;i++)
	{
		if(set[i]==item)
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
int intersect(int setA[],int sizeA,int setB[],int sizeB,int setC[])
	{
		int i,j,sizeC=0,a[1000]={0};
		for(i=0,j=0;i<sizeA||j<sizeB;i++,j++)
		{
			a[setA[i]]++;
			if(a[setA[i]]>1)
			{
				setC[sizeC]=setA[i];
				sizeC++;
			}
			a[setB[i]]++;
			if(a[setB[i]]>1)
			{
				setC[sizeC]=setB[i];
				sizeC++;
			}
		}
		sizeC--;
		printf("\n%d\n",sizeC);
		return 0;
	}
int main()
{
	int i,j,n,m,p,setC[1000],o,temp,sum=0;
	printf("Enter 1 or 2 or 3:");
	scanf("%d",&m);
	scanf("%d",&n);
	int setA[n];
	scan_set(setA,n);
	prt_set(setA,n);
	switch(m)
	{
		case 1:
			scanf("%d",&j);
			is_member(j,setA,n);
			break;
		case 2:
			{
			scanf("%d",&p);
			int setB[p];
			scan_set(setB,p);
			prt_set(setB,p);
			intersect(setA,n,setB,p,setC);
			break;
		}
		case 3:
			{
			scanf("%d",&o);
			if(o>n)
			{
				printf("small");
				break;
			}
			for(i=n-2;i>=n-1-o;i--)
			{
				for(j=0;j<=i;j++)
				{
					if(setA[j]>setA[j+1])
					{
						temp=setA[j];
						setA[j]=setA[j+1];
						setA[j+1]=temp;
					}
				}
			}
			for(j=n-o;j<=n-1;j++)
			sum+=setA[j];
			printf("%d",sum);
		}
	}
}
