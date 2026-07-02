//法一：前缀和
int max_subarray_sum(int a[]){
    for(int i = 1; i <= 7; i++)
    {
        a[i] = a[i - 1] + a[i];
    }
    int ret = -1e9;
    int prevmin = 0;
    for(int i = 0; i <= 7; i++)
    {
        ret = max(ret, a[i] - prevmin);
        prevmin = min(prevmin, a[i]);
    }
    return ret;
}
//法二：贪心
int max_subarray_sum(int a[]){
    int cur=0,maxx=0;
    int i;
    for(i=0;i<8;i++){
        cur+=a[i];
        if(cur<0) cur=0;
        if(cur>maxx) maxx=cur;
    }
    return maxx;
}