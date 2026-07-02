int is_palindromic(int n){
    if(n<0) return 0;
    if(n<10) return 1;
    int s=1;
    while(s*10<=n){
        s*=10;
    }//写法很妙，不用再开一个变量复制粘贴过去
    int a=n/s;
    int b=n%10;
    if(a!=b) return 0;
    return is_palindromic((n%s)/10);
}