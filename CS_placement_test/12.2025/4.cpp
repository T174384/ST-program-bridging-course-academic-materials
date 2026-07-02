int present_on_day(int n){
    if(n==0) return 0;
    return present_on_day(n-1)+n;
}

int present_thru_days(int n){
    if(n==0) return 0;
    return present_thru_days(n-1)+present_on_day(n);
}