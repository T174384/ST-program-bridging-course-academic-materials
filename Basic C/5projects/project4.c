#include<stdio.h>
#include<string.h>
#define max 250
typedef struct{int x;
int y;
}can;
typedef struct{
	char a,b;
	int count;
}sort;
can cishu[26][26];
void readWords(char bank[][max],int *wordCount,int *k)
{
	int j;
	while(1)
	{
		scanf("%s",bank[*wordCount]);
		if(strlen(bank[*wordCount])>(*k))
		(*k)=strlen(bank[*wordCount]);
	  for(j=0;j<strlen(bank[*wordCount]);j++)
	  {
	  	if(bank[*wordCount][j]>='A'&&bank[*wordCount][j]<='Z')
	  	bank[*wordCount][j]=bank[*wordCount][j]+32;
	  	if(bank[*wordCount][j]=='.')
	  	{
	  	bank[*wordCount][j]='\0';
	  	if(j==0)
	  	(*wordCount)--;
	  	return;
	    }
	  }
	  (*wordCount)++;
    }
}
void bigram(char bank[][max],int table[][26],int *s,int *kind,int wordCount)
{
	int i,j,n,o,p;
	for(o=0;o<=25;o++)
	{
		for(p=0;p<=25;p++)
		{
			cishu[o][p].x=0;
		}
	}
	for(i=0;i<=wordCount;i++)
	{
		j=1;
		for(o=0;o<=25;o++)
	{
		for(p=0;p<=25;p++)
		{
			cishu[o][p].y=0;
		}
	}
		while(bank[i][j]!='\0')
		{
			(cishu[bank[i][j-1]-'a'][bank[i][j]-'a'].y)++;
			if(cishu[bank[i][j-1]-'a'][bank[i][j]-'a'].y==2)
			{
			cishu[bank[i][j-1]-'a'][bank[i][j]-'a'].x=cishu[bank[i][j-1]-'a'][bank[i][j]-'a'].x+1;
			}
			table[bank[i][j-1]-'a'][bank[i][j]-'a']++;                                    
			j++;
		}
	}
			
	for(i=0;i<=25;i++)
	{
		for(j=0;j<=25;j++)
		{
			if(table[i][j]!=0)
			(*kind)++;
			(*s)+=table[i][j];
		}
	}
}
int main()
{
	char bank[max][max];
	int wordCount=0,i,j,k=0,m,s=0,kind=0,o=0,p;
	int table[26][26]={};
	sort u[676];
	printf("Read in words:\n");
	readWords(bank,&wordCount,&k);
	printf("\n\nWord Bank:\n");
	for(i=0;i<k+2;i++)
	printf("+");
	printf("\n");
	for(i=0;i<=wordCount;i++)
	{
		printf("%s",bank[i]);
		printf("\n");
	}
	printf("\nNumber of words read:%d\n",wordCount+1);
	printf("The length of the longest word:%d",k);
	bigram(bank,table,&s,&kind,wordCount);
	printf("\n\n\nBigram statistics:\n");
	for(i=1;i<=18;i++)
	printf("+");
	printf("\n");
	printf("Total number of bigrams: %d\n",kind);
	printf("Total count of bigram occurrences: %d\n\n\n",s);
	printf("Repeated Bigrams Statistics:\n");
	for(i=1;i<=28;i++)
	printf("+");
	printf("\n");
	for(i=0;i<=25;i++)
	{
		for(j=0;j<=25;j++)
		{
			if(cishu[i][j].x>0)
			{
				u[o].a=i+'a';
				u[o].b=j+'a';
				u[o].count=cishu[i][j].x;
				o++; 
			}
		}
	}
	o--;
	sort temp;
	for(i=o-1;;i--)
	{
		j=0;
	for(p=0;p<=i;p++)
	{
		if(u[p].count<u[p+1].count)
		{
			temp=u[p+1];
			u[p+1]=u[p];
			u[p]=temp;
			j=1;
		}
	}
	if(j==0)
	break;
    }
    for(i=0;i<=o;i++)
	printf("Number of words for which \"%c%c\" is founded repeated: %d\n",u[i].a,u[i].b,u[i].count);
}