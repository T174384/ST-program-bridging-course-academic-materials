#include<stdio.h>
#include<string.h>
#define N 3
int main()
{
	FILE *input;
	input=fopen("bombs.inf","r");
	int i,j,k;
	char a[10][10],b[10][10];
	for(i=1;i<=N;i++)
	fscanf(input,"%s%s",&a[i][1],&b[i][1]);
	for(i=1;i<=N;i++)
	{
       for(j=1;j<=strlen(&b[i][1]);j++)
       for(k=j;k>=1;k--)
       {
       	if(b[i][j]=='0')
       	b[i][j]='9';
       	else
       	b[i][j]=b[i][j]-1;
	   }
    }
    for(i=1;i<=N;i++)
	printf("%7s%18s\n",&a[i][1],&b[i][1]);
	fclose(input);
}