1. recursion:
void reverse(char str[], int left, int right){
    if(left>=right) return;
    char temp=str[left];
    str[left]=str[right];
    str[right]=temp;
    reverse(str,left+1,right-1);
}

2. iteration
void reverse(char str[], int left, int right){
    while(left<right){
        char temp=str[left];
        str[left]=str[right];
        str[right]=temp;
        left++;
        right--;
    }
}