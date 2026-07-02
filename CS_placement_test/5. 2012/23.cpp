#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int st[11];
int main(){
    srand(time(0));
    int i,maxx=-1,ret;
    for(i=0;i<100;i++){
        int x=rand()%9+2;
        st[x]++;
    }
    for(i=2;i<=10;i++){
        if(st[i]>maxx){
            maxx=st[i];
            ret=i;
        }
    }
    printf("%d\n",ret);
    return 0;
}