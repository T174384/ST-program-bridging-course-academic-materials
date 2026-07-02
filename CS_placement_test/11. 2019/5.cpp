bool is_Armstrong(int n){
    if(n==0) return true;
    int cnt=0,sum=0;
    int s=n;
    while(s){
        cnt++;
        s/=10;
    }
    s=n;
    while(s){
        sum+=pow(s%10,cnt);
        s/=10;
    }
    return sum==n;
}