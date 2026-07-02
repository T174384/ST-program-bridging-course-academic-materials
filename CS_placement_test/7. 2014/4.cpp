void reverse_print(int n){
    if(n==0) return;
    int a;
    scanf("%d",&a);
    reverse_print(n-1);
    printf("%d",a);
}