void print(int n){
    int i=2,j=5;
    while(i<=n||j<=n){
        while(i<j&&i<=n){
            printf("%d ",i);
            i*=2;
        }
        while(j<i&&j<=n){
            printf("%d ",j);
            j*=5;
        }
    }
}