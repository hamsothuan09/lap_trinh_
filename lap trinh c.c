#include <stdio.h>
 
 int main(){
 	int a,b,c;
 	scanf("%d %d %d", &a,&b,&c);
 	if((a+b >c )  && (a+c >b)  && (b+c >a )){
 	printf("la mot tam giac");
 }  
	else {
	    printf ("khong la tam giac");
	}
   return 0;
}
 