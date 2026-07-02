#include<stdio.h>
int a[1002];
int main(){
    int n,i;
    printf("Enter the number of pages:");
    scanf("%d",&n);
    printf("Enter the pages: ");
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    // printf("Condensed list: %d",a[1]);
    // for(i=2;i<=n;i++){
    //     if(a[i]==a[i-1]+1){
    //         if(a[i]+1==a[i+1]) continue;
    //         else printf("-%d ",a[i]);
    //     } 
    //     else printf(" %d",a[i]);
    // }
    printf("Condensed list:");
    i = 1;
    while(i <= n)
    {
        int start = a[i];
        while(i < n && a[i + 1] == a[i] + 1)
            i++;
        if(start == a[i])
            printf(" %d", start);
        else
            printf(" %d-%d", start, a[i]);
        i++;
    }
    return 0;
}