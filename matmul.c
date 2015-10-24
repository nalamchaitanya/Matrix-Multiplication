#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matlib.h"

int** A;
int** B;
int** C;
int r1,c1,r2,c2;

int main()
{
	A = matread("mat1.dat");
	B = matread("mat2.dat");
	B = mattra(B,r2,c2);

	if(c1!=r2)
	{
		printf("Matrix dimensions mismatch.\n");
		return 0;
	}

	C=(int**)malloc(sizeof(int*)*r1);
	int i;
	for(i=0;i<r1;i++)
	{
		C[i]=(int*)malloc(sizeof(int)*c2);
		memset(C[i],0,sizeof(int)*c2);
	}

	matprint(A,r1,c1);
	matprint(B,r2,c2);

	Args *args = (Args*)malloc(sizeof(Args));
	args->rs=0;
	args->re=r1;
	args->cs=0;
	args->ce=c2;

	matpro(args);

	matprint(C,r1,c2);
	//print();
	return 0;
}
