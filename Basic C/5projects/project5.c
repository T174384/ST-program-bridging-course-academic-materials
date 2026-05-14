#include <stdio.h>
#include <stdbool.h>
#define M 50
#define N 50
typedef struct {
   int x;
   int y;
} coord_t; 
int a,b,c,d,na,bi[M][N]={};
void readMap(int map[][N], int *rows_p, int *cols_p);
void prtMap(int map[][N], int rows, int cols);
void read2Corners(coord_t *c1, coord_t *c2);
void findCorners(coord_t c1, coord_t c2, coord_t corners[4]);
void fillSpace(int map[][N], int rows, int cols);
void drawBorders(int map[][N], int rows, int cols);
void touch(int map[][N], int rows, int cols);
int min(int a,int b)
{
	if(a>b) return b;
	return a;
}
int max(int a,int b)
{
	if(a>b) return a;
	return b;
}
/* DO NOT MODIFY FROM HERE ON */
int main(void) {
   int rows, cols;
   int map[M][N];
   coord_t corners[4], c1, c2;
   int op;
   bool inLoop = true;

   readMap(map, &rows, &cols);
   prtMap(map, rows, cols);

   while (inLoop) {
      printf("Enter operation number [0 to 4]; other integer to get out: ");
      scanf("%d", &op);

      if (op == 0) {
         /* print out the existing map */
         printf("Print the current map:\n");
         printf("++++++++++++++++++++++\n");
         prtMap(map, rows, cols);

      } else if (op == 1) {
         /* find four corners from two opposite corners */
         printf("Find corners.\n");
         printf("+++++++++++++\n");
         read2Corners(&c1, &c2);
         findCorners(c1, c2, corners);

      } else if (op == 2) {
         /* fill in the boxed region with a number */
         printf("Map Filling Operation.\n");
         printf("++++++++++++++++++++++\n");
         fillSpace(map, rows, cols);

      } else if (op == 3) {
         /* Draw borders enclosing the occurrences of specific */
         /* value in the map.                                  */
         printf("Display map borders.\n");
         printf("++++++++++++++++++++\n");
         drawBorders(map, rows, cols);

      } else if (op == 4) {
         /* touch a point in a rectangular region with a number,       */
         /* that will reset all cells connected this point and having  */
         /* the same original number changed to hold the new number    */
         /* two cells are connected if they are adjacent to each other,*/
         /* separated by an edge (NOT a corner).                       */
         printf("Map Touching Operation.\n");
         printf("+++++++++++++++++++++++\n");
         touch(map, rows, cols);

      } else {
         /* Exit the game                                       */
         printf("The End.\n");
         inLoop = false;
      }
   }  
   return 0;
}
/* DO NOT MODIFY UNTIL HERE */

/* readMap function */
void readMap(int map[][N], int *rows_p, int *cols_p) {
	int i,j;
	printf("Read in number of rows: ");
	scanf("%d",rows_p);
	printf("Read in number of columns: ");
	scanf("%d",cols_p);
	printf("Read in the map of size %dX%d",*rows_p,*cols_p);
	for(i=0;i<*rows_p;i++)
	{
		for(j=0;j<*cols_p;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
   return;
}

/* prtMap function */
void prtMap(int map[][N], int rows, int cols) {
   int i,j;
   printf("   ");
   for(i=0;i<cols;i++) printf("  %d",i);
   printf("*\n  +");
   for(i=0;i<cols;i++) printf("---");
   printf("*\n");
   for(i=0;i<rows;i++)
   {
   	    printf(" %d|",i);
   		for(j=0;j<cols;j++)
   		{
   			printf("  %d",map[i][j]);
		}
		printf("*\n");
   }			
    return;
}

/* Read two corners of a rectangular region */
void read2Corners(coord_t *c1, coord_t *c2) {
    printf("Please enter the first corner:");
    scanf("%d %d",&c1->x,&c1->y);
    printf("Please enter the corresponding diagonal corner:"); 
    scanf("%d %d",&c2->x,&c2->y);
    return;
}

/* findCorners function */
void findCorners(coord_t c1, coord_t c2, coord_t corners[4]) {
	int a=min(c1.x,c2.x),b=max(c1.x,c2.x),c=min(c1.y,c2.y),d=max(c1.y,c2.y);
	printf("Top-left Corner: %d, %d.\n",a,c);
	printf("Top-right Corner: %d, %d.\n",a,d);
	printf("Bottom-left Corner: %d, %d.\n",b,c);
	printf("Bottom-right Corner: %d, %d.\n",b,d);
    return;
}

/* fillSpace function  */
void fillSpace(int map[][N], int rows, int cols) {
	int n,i,j;
	coord_t c1,c2,corners[4];
	read2Corners(&c1,&c2);
	findCorners(c1, c2, corners);
	int a=min(c1.x,c2.x),b=max(c1.x,c2.x),c=min(c1.y,c2.y),d=max(c1.y,c2.y);
	printf("Enter number to be filled in:");
	scanf("%d",&n);
	for(i=a;i<=b;i++)
    {
   	 	for(j=c;j<=d;j++)
   	 	{
   			map[i][j]=n;
		}
    }
   return;
}

/* drawBorders function */
void drawBorders(int map[][N], int rows, int cols) {
	int m=2*rows+1,n=3*cols+2;
   char a[m][n];
   int i,j,p,r,s,dx[2]={-1,1},dy[2]={-2,1},u;
   for(i=0;i<m;i++)
   {
   	for(j=0;j<n;j++)
   	{
   		a[i][j]=' ';
	}
   }
   printf("Read in a number:");
   scanf("%d",&p);
   for(i=0;i<rows;i++)
   {
   	for(j=0;j<=cols;j++)
   	{
   		if(j==cols)
   		{
   			a[2*i][n-1]=a[2*i+1][n-1]='*';
   		    continue;
		}
		   r=2*i+1;s=3*j+2;
		   a[r][s]=map[i][j]+48;
   		if(map[i][j]==p)
   		{
   			for(u=0;u<=1;u++)
   			{
   			if(a[r][s+dy[u]]=='|')
   			a[r][s+dy[u]]=' ';
   			else
   			a[r][s+dy[u]]='|';
   		    }
   		    for(u=0;u<=1;u++)
   			{
   			if(a[r+dx[u]][s]=='-')
   			a[r+dx[u]][s-1]=a[r+dx[u]][s]=' ';
   			else
   			a[r+dx[u]][s-1]=a[r+dx[u]][s]='-';
   		    }
		}
	}
   }
   for(i=0;i<m;i++)
   {
   	
   	for(j=0;j<n;j++)
   	{
   		printf("%c",a[i][j]);
	}
	printf("\n");
   }
   return;
}

/* touch function */
void dfs(int e,int f,int map[][N],int o)
{
	int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},i;
	map[e][f]=na;
	bi[e][f]=1;
	for(i=0;i<=3;i++)
	{
		int m=e+dx[i],n=f+dy[i];
		if(m<a||m>b||n<c||n>d||map[m][n]!=o||bi[m][n]==1)
		continue;
		dfs(m,n,map,o);
	}
	return;
}
void touch(int map[][N], int rows, int cols) {
	coord_t c1,c2,corners[4],c3;
	int i,j;
	read2Corners(&c1,&c2);
	findCorners(c1, c2, corners);
    a=min(c1.x,c2.x);b=max(c1.x,c2.x);c=min(c1.y,c2.y);d=max(c1.y,c2.y);
	printf("Enter the cordinate of a location to touch:");
	scanf("%d%d",&c3.x,&c3.y);
	printf("Choose a number to spread: ");
	scanf("%d",&na);
	dfs(c3.x,c3.y,map,map[c3.x][c3.y]);
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		bi[i][j]=0;
	}
   return;
}
