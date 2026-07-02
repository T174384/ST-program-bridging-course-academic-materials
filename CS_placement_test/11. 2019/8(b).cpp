void reverse_string(char str[]){
    int len=strlen(str);
    reverse(str,0,len - 1);
    int start=0;
    for(int i=0;i<=len;i++){
        if(str[i]==' '||str[i]=='\0'){
            reverse(str,start,i-1);
            start=i+1;//start不要放错地方了
        }
    }
}