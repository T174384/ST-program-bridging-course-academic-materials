#include<stdio.h>
#include<string.h>
char str[105];
int period(char str[]){
    int len=strlen(str);
    int i,j,s;
    for(i=1;i<=len;i++){
        if(len%i!=0) continue;
        s=1;
        for(j=i;j<len;j+=i){
            if(strncmp(str,str+j,i)!=0){
                s=0;
                break;
            }
        }
        if(s) return i;
    }
}
int main(){
    scanf("%s",str);
    printf("%d",period(str));
    return 0;
}