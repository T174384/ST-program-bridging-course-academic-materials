#include<stdio.h>
#include<stdlib.h>
#define N 10
void readFile(int a[][N], int *num){
    FILE *indata;
    int t,i;
    indata=fopen("calls.in","r");
    if(indata==NULL){
        printf("can't open");
        exit(1);
    }
    fscanf(indata,"%d%d",num,&t);

    // ★ 原来这里虽然大部分OJ能过，
    //   但是a没有初始化，里面全是垃圾值。
    //   后面判断a[i][j]==1会出错。
    for(i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a[i][j]=0;
        }
    }
    for(i=0;i<t;i++){
        int x,y;
        fscanf(indata,"%d%d",&x,&y);
        a[x][y]=1;
    }
    fclose(indata);
}
int countRecursive(int a[][N],int num){
    int i,sum=0;
    for(i=0;i<num;i++){
        if(a[i][i]==1)
            sum++;
    }
    return sum;
}
int countDirectCalls(int a[][N],int num,int x){
    int i,sum=0;
    for(i=0;i<num;i++){
        if(a[x][i]==1)
            sum++;
    }
    return sum;
}
int canReach(int a[][N],int num,int y,int z){
    if(a[y][z]==1) return 1;
    int i;
    for(i=0;i<num;i++){
        // ★ 原来这里只判断==1是可以的
        //   但是下面return写错了。
        if(a[y][i]==1){

            // √ 标记已经访问
            a[y][i]=-1;

            // ★★★ 原来这里最大的错误 ★★★
            //
            // 你写的是：
            //
            // return canReach(a,num,i,z);
            //
            // 这样如果第一个邻居不能到达，
            // 函数直接return 0，
            // 后面的邻居根本不会继续搜。
            //
            // DFS必须继续枚举所有邻居。

            if(canReach(a,num,i,z)) return 1;
        }
    }
    return 0;
}
int main(){
    int a[N][N];
    int num,x,y,z;
    readFile(a,&num);
    printf("(b) Number of recursive functions:%d\n",
            countRecursive(a,num));
    printf("(c) Enter function number (0-5):");
    scanf("%d",&x);
    printf("Function %d calls %d function(s) directly.\n",
            x,countDirectCalls(a,num,x));
    printf("(d) Enter 'source' and 'destination' functions:");
    scanf("%d%d",&y,&z);
    if(canReach(a,num,y,z))
        printf("Function %d calls function %d, directly or indirectly.\n",y,z);
    else
        printf("Function %d does not call function %d, directly or indirectly.\n",y,z);
    return 0;
}