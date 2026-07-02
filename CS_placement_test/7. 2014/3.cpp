//A
int count_pairs(int arr[],int size,int key){
    int i,j,cnt=0;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(arr[i]+arr[j]==key) cnt++;
        }
    }
    return cnt;
}

//B 
int count_pairs(int arr[],int size,int key){
    int i,j,cnt=0;
    for(i=0;i<size-1;i++){
        if(arr[i]+a[i+1]>key) break;
        for(j=i+1;j<size;j++){
            if(arr[i]+arr[j]==key) cnt++;
            if(arr[i]+arr[j]>=key) break;
        }
    }
    return cnt;
}