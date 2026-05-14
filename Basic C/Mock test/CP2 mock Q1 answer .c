#include<stdio.h>
int n;
int function(int m)
{
	int s=0;
	if(m==0)
	return 0;
	s=s+function(m/n)*10+m%n;
	return s;
}
int main()
{
	int m;
	printf("number(base 10):");
	scanf("%d",&m);
	printf("base to be converted:");
	scanf("%d",&n);
	printf("%d",function(m));
}