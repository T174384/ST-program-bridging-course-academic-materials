#include <stdio.h>
#include <stdlib.h>
#define N 100005
#define seed 37
int a[105], st[N];
int min(int a, int b) {
    return a<b?a:b;
}
int main() {
    srand(seed);
    int i,j,minn=1e9;
    for (i=0;i<100;i++) {
        int s=(rand()+rand()%567)*3;
        if (st[s]==1) {
            i--;
            continue;
        }
        st[s] = 1;
        a[i] = s;
    }
    for (i=0;i<100;i++) {
        for (j=i+1;j<100;j++) {
            minn=min(minn,abs(a[i]-a[j]));
        }
    }
    printf("%d\n",minn);
    return 0;
}