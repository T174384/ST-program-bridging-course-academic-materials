//A
int zombie(double r0,int day){//类型不要传错了
    int sum=1;
    while(day--){
        sum+=ceil(sum*r0);
    }
    return sum;
}

//B
int zombie(double r0,int day){//类型不要传错了
    if(day==0) return 1;
    return ceil(zombie(r0, day-1)*(1+r0));
}