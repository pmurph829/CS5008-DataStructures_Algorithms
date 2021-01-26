#include <stdio.h>

int main(){
	int accountId = 5;
	double accountBalance = 100.53;
	char accountType = 'C';
	
	printf("Accound ID: %d\n", accountId);
	printf("Account Balance: %f\n", accountBalance);
	printf("Account Type: %c\n", accountType);

	printf("sizeof(int): %lu\n", sizeof(accountId));
	printf("sizeof(double): %lu\n", sizeof(accountBalance));
	printf("sizeof(char): %lu\n", sizeof(accountType));

	return 0;
}
