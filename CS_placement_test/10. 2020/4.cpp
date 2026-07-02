void pancake(int config[],int n){
    int i,j;
    for(i=n;i>=2;i--){
        for(j=0;j<i;j++){
            if(config[j]==i){
                printf("flip(%d)\n",j+1);
                printf("flip(%d)\n",i);
                flip(config,j+1);
                flip(config,i);
            }
        }
    }
}