int find_kth(int arr[],int left, int right){
    int index=partition(arr,left,right);
    if(index==k-1) return arr[index];
    //这种更新位置的一定要想清楚判断条件写的什么，题目的需求是什么，到底应该如何去更新
    if(index>k-1) return find_kth(arr,left,index-1);
    if(index<k-1) return find_kth(arr,index+1,right);
}