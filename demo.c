# include <stdio.h>

// a function that takes an unsigned integer and returns the Hamming Weight (number of '1' bits it has)
int hamWeight(char biString[32]){
	int num = 0; 
	for (int i =0; i < 32; ++i){
		if (biString[i] == 1){
			++num;
		}
	}
	return num;
}

int main(void) {
	char ex1[32] = '00000000000000000000000000001011';
	printf("%d\n", hamWeight(ex1)); // prints 3

	char ex2[32] = '00000000000000000000000010000000';
	printf("%d\n", hamWeight(ex2)); // prints 1

	return 0;
}
