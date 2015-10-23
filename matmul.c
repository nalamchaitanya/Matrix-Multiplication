#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "matlib.h"

int main()
{
	int** A = matread("mat1");
	int** B = mattra(A,2,2);
	matprint(A,2,2);
	matprint(B,2,2);
	return 0;
}
