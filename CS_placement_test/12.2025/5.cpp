int match(char *s1,char *s2)
{
    int i;
    int len1=strlen(s1);
    int len2=strlen(s2);
    if(len1>len2) return 0;   // 你原代码漏掉的边界
    char s3[len1+1];
    for(i=0;i<len1;i++)
    {
        if(s1[i]=='A') s3[i]='T';
        else if(s1[i]=='T') s3[i]='A';
        else if(s1[i]=='C') s3[i]='G';
        else if(s1[i]=='G') s3[i]='C';
    }
    s3[len1]='\0';
    if(strstr(s2,s3)!=NULL) return 1;//看是否包含可以用strstr
    return 0;
}