(a)
int pow(int x,int n){
    if(n==0) return 1;
    return x*pow(x,n-1);
}

(b)
int newPow(int x,int n){
    if(n==0) return 1;
    int h=n&1,s=newPow(x,n/2);
    if(h==1) return x*s*s;
    return s*s;
}

(c)
newPow(4,3)->4*newPow(4,1)*newPow(4,1)->4*4*newPow(4,0)*4*newPow(4,0)->4*4*4=64