/* Peter Murphy
 * CS5008
 * Lab 1
 */
#include <stdio.h>

/* Function that calculates a base raised to a number.
 */

double power(double base, double n){

	double result = base;
	
	// If n is 0, the result will always be 1.
	if(n == 0){ 
		return 1;
	}
	
	n--; // Correct for off by one error.
	for(;n>0; n--){
		result = result * base;
	}
	return result;
}

/* Calculate 2^n for 1 <= n <= 10.
 */

int main(){
	for(int n = 0; n <= 10; n++){
		double twoPower = power(2, n);
		printf("2^%d = %.2f\n", n, twoPower);
	}
	
	return 0;
}
