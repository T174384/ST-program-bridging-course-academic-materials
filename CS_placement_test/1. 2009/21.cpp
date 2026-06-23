#include <stdio.h> 
// int months(double loan, double mon_pay){
// 	int cnt=0;
// 	while(loan>0){
// 		cnt++;
// 		loan=loan*1.01-mon_pay;
// 	}
// 	return cnt;
// } 
int months(double loan, double mon_pay){
    if(loan<=0) return 0;
    return 1+months(loan*1.01-mon_pay,mon_pay);
}
int main(){
	printf("%d\n",months(100,40));
}