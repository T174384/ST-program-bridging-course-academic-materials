//A
#include <stdbool.h>
bool can_reach(int forest[N][M],int row, int col){
    if(row==1&&col==1) return 1;
    int i,x=row,y=col;
    int a[]={0,-1};
    int b[]={-1,0};
    for(i=0;i<2;i++){
        int xx=row+a[i];
        int yy=col+b[i];
        if(forest[xx][yy]==0) continue;
        if(can_reach(forest,xx,yy))  return 1;
    }
    return 0;
}

//B
#include <stdbool.h>
bool can_reach(int forest[N][M],int row, int col){
    if(row==1&&col==1) return 1;
    int i,x=row,y=col;
    forest[x][y]=0;
    int a[]={0,-1,0,1};
    int b[]={-1,0,1,0};
    for(i=0;i<4;i++){
        int xx=row+a[i];
        int yy=col+b[i];
        if(forest[xx][yy]==0) continue;
        if(can_reach(forest,xx,yy))  return 1;
    }
    return 0;
}