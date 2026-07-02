#include<stdio.h>
typedef struct{
    float height;
    float mass;
    float bmi;
    int riskType;
}record;
int main(){
    record x;
    float s;
    int h;
    scanf("%f%f",&x.height,&x.mass);
    s=x.mass/(x.height*x.height);
    h=s*100;
    if(h%10>=5) x.bmi=(h/10+1)/10.0;
    else x.bmi=h/10/10.0;
    printf("%.1f ",x.bmi);
    if(x.bmi>=27.5) x.riskType=2;
    else if(x.bmi>=23.0) x.riskType=1;
    else if(x.bmi>=18.5) x.riskType=0;
    else x.riskType=-1;
    printf("%d\n",x.riskType);
    return 0;
}