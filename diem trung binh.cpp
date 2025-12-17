#include<stdio.h>
int main (){
    float n;
	scanf("%f",&n);
	if(n>= 8){
	printf ("hoc sinh gioi");
 }
    else if(n>= 6.5){
    printf("hoc sinh kha");
 }
	else if(n>=5){
	printf("hoc sinh trung binh");
 }
    else {
    	printf("yeu");
 }
	return 0;
}