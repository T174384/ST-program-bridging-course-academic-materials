void randomize_matrix(int mat[][10],int n){
    int i,j,a[101]={0};//一定要记得没有开全局的时候要初始化,还有就是不要数组都搞忘建了
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            int s=rand()%100+1;
            if(a[s]){
                j--;
                continue;
            }
            mat[i][j]=s;
            a[s]=1;
        }
        for(j=0;j<=100;j++) a[j]=0;
    }
}

int max_total(int mat[][10],int n){
    int dp[n][n]={0};
    int i,j;
    for(i=1;i<n;i++) dp[0][i] = dp[0][i-1] + mat[0][i];
    for(i=1;i<n;i++) dp[i][0] = dp[i-1][0] + mat[i][0];//注意初始化的正确性
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            dp[i][j]=(dp[i][j-1]>dp[i-1][j]?dp[i][j-1]:dp[i-1][j])+mat[i][j];
        }
    }
    return dp[n-1][n-1];
}
