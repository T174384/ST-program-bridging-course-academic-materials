#include<stdio.h>
char str[105];
void reverse(char str[],int start, int end){
    if(start>end) return;
    int temp=str[start];
    str[start]=str[end];
    str[end]=temp;
    reverse(str,start+1,end-1);
    return;
}
void swapSubstrings(char str[], int len_a, int len_b){
    reverse(str,0,len_a-1);
    reverse(str,len_a,len_a+len_b-1);
    reverse(str, 0, len_a+len_b-1);
}
int main(){
    scanf("%s",str);
    int len_a,len_b;
    scanf("%d%d",&len_a,&len_b);
    swapSubstrings(str,len_a,len_b);
    printf("%s",str);
    return 0;
}