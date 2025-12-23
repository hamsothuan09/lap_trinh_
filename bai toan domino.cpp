#include <stdio.h>
  int main ( ){
    long long   n , m;
  	scanf ("%lld %lld", &n, &m);
  	if ( n % 2 == 0){
  		printf ("%lld", 1ll *  n / 2 * m );
	  }
	  else {
	  	printf ( "%lld", 1ll *  n /2 *m + m / 2);
		  }
		  return 0;
	  }