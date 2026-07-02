#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 20
#define NUM_FUNCTIONS 5
void convert(char s[]){
    s[strcspn(s,"\n")] = '\0';//重要，如果长度不满20'\n'会被读进去
    int i, len=strlen(s);
    for(i=0;i<len;i++){
        if(s[i]==' ') s[i]='_';
    }
}
int search(char functions[][MAX_LENGTH+1],int num,char fname[]){
    int i;
    for(i=0;i<num;i++){
        if(strcmp(fname,functions[i])==0) return i+1;
    }
    return -1;
}
int main(){
    char functions[NUM_FUNCTIONS][MAX_LENGTH+1]=
        {"main","abc","d_e_f","pqr__st","kkkkkmmmmmrrrrrsssss"};
    char fname[MAX_LENGTH+1];
    printf("Enter function name:");
    fgets(fname,MAX_LENGTH+1,stdin);
    convert(fname);
    printf("fname found at position %d\n",search(functions,NUM_FUNCTIONS,fname));
    return 0;
}