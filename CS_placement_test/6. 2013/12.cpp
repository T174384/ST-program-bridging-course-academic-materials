# include<ctype.h>
void convert(char*str){
    int i,j=0;
    for(i=0;str[i]!=0;i++){
        char h=toupper(str[i]);
        if(h=='A'||h=='E'||h=='I'||h=='O'||h=='U') continue;
        str[j++]=h;
    }
    str[j]=0;
}