#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 512

void saxpy(int alpha, int* x, int* y) {
	for (int i=0; i<SIZE; i++) {
		y[i] = alpha * x[i];
	}
}

void init(int* x, int* y) {
	for (int i=0; i<SIZE; i++) {
		x[i] = 450;
		y[i] = -1;
	}
}

void validate(int* y) {
	bool valid = true;
	for (int i=0; i<SIZE; i++) {
		if (y[i] != 900) {
			valid = false;
			break;
		}
	}
	printf((valid)?"Success":"Fail");
}

int main() {
	int* x;
	int* y;
	int counter=0;
	
	x = (int*)malloc(SIZE*sizeof(int));
	y = (int*)malloc(SIZE*sizeof(int));
	
	init(x, y);
	
	while (counter++ < 100000) {
		saxpy(2, x, y);
	}

	validate(y);
	
	free(x);
	free(y);
	return 0;
}
