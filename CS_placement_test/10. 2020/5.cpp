boolean is_automorphic(int n){
    int s=n*n;
    while(n){
        if(n%10!=s%10) return false;
        n/=10;
        s/=10;
    }
    return true;
}