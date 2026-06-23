样例点1:
4 0
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
输出：
  4  3  2  1
  8  6  7  5
 12 10 11  9
 16 15 14 13


样例点2:
4 1
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
输出：
  1  2  3  4
  5  7  6  8
  9 11 10 12
 13 14 15 16


样例点3:
3 0
1 2 3
4 5 6 
7 8 9
输出：
  3  2  1
  6  5  4
  9  8  7


#include<stdio.h>
int square[10][10];
void print(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3d",square[i][j]);
        }
        printf("\n");
    }
}
法一: 直接交换
// void flipLeftRight(int square[][10],int size, int index){
//     int i,j;
//     int len=size-2*index;
//     for(i=index;i<=index+len-1;i++){
//         if(i==index||i==index+len-1){
//             for(j=index;j<=index+len/2-1;j++){
//                 int temp=square[i][j];
//                 square[i][j]=square[i][2*index+len-j-1];
//                 square[i][2*index+len-j-1]=temp;
//             }
//         }
//         else{
//             int temp=square[i][index];
//             square[i][index]=square[i][index+len-1];
//             square[i][index+len-1]=temp;
//         }
//     }
// }
法二: 这个验证的想法很有趣，不是直接交换而是判断是否需要交换
void flipLeftRight(int square[][10],int size,int index)
{
    int temp[10][10];
    int i,j;
    //复制原矩阵
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            temp[i][j]=square[i][j];
        }
    }
    int l=index;
    int r=size-1-index;
    for(i=l;i<=r;i++)
        for(j=l;j<=r;j++)
            // 判断(i,j)是否在第index圈
            if(i==l||i==r||j==l||j==r)
                square[i][j]=temp[i][size-1-j];
}
int main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&square[i][j]);
        }
    }
    flipLeftRight(square,n,k);
    print(n);
    return 0;
}