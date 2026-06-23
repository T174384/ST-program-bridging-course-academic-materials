1.
typedef struct module{
    int modulecode;
    int modulecode[S];
    int grade[S];
    int count;
}modules[M];

2.
#include<stdio.h>
#define S 2
#define M 3
typedef struct student{
    int matrinumber;
    int modules[M];
    int count;
}students[S];
typedef struct module{
    int modulecode;
    int studentcode[S];
    int grade[S];
    int count;
}modules[M];
void print(students a, modules b){
    int i,j,k;
    for(i=0;i<S;i++){
        printf("%d ",a[i].matrinumber);
        double sum=0;
        for(j=0;j<M;j++){
            for(k=0;k<S;k++){
                if(b[j].studentcode[k]==a[i].matrinumber){
                    sum+=b[j].grade[k];
                }
            }
        }
        printf("%.1f\n",sum/a[i].count);
    }
}
int main(){
    int i,j;
    students a={
        {111111,{1101,1103},2},
        {222222,{1102,1103},2}
    };
    modules b={
        {1101,{111111},{3},1},
        {1102,{222222},{1},1},
        {1103,{111111,222222},{4,5},2}
    };
    print(a,b);
    return 0;
}