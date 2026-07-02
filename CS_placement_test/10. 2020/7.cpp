#include<stdio.h>
#include<string.h>
char a[51];
int st[128];
void modify(){
    int len=strlen(a),i,j=0;
    for(i=0;i<len;i++){
        if(st[a[i]]) continue;
        st[a[i]]=1;
        a[j]=a[i];
        j++;
    }
    a[j]=0;
}
int main(){
    printf("Enter string:");
    scanf("%s",a);
    modify();
    printf("Modified string: %s",a);
    return 0;
}