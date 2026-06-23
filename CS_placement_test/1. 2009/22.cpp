#include<stdio.h>
int a[15][15];
int mag(int a[][15],int n){
    int sum=(1+n*n)*n/2;
    int i,j,u=0,v=0;
    for(i=1;i<=n;i++){
        int s=0,h=0;
        for(j=1;j<=n;j++){
            s+=a[i][j];
            h+=a[j][i];
        }
        if(s!=sum||h!=sum) return 0;
        u+=a[i][i];
        v+=a[i][n-i+1];
    }
    if(u!=sum||v!=sum) return 0;
    return 1;
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    if(mag(a,n)) printf("yes\n");
    else printf("no\n");
    return 0;
}