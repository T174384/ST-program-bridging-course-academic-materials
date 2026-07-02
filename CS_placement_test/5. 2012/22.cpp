int sumDigits(int n){
    if(n==0) return 0;
    int a=n%10;
    if(a%2==0) return 1+a+sumDigits(n/10);
    else return a+sumDigits(n/10);
}