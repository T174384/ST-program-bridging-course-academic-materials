#include<stdio.h>
int main()
{
	int n,i,s=0,m;
	scanf("%d",&n);
	m=n;
	do{
		i=n%10;
		s=s+i*i*i;
		n=n/10;
	}
	while(n!=0);
	if(s==m)
	printf("armstrong");
	else
	printf("not");
}