#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matlib.h"

int** A;
int** B;
int** C;
int r1,c1,r2,c2;

int main(int argc,char **argv)
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

	// matprint(A,r1,c1);
	// matprint(B,r2,c2);


	// printf("%d %d %d %d\n",r1,c1,r2,c2);

	int thrcnt;
	thrcnt=atoi(argv[1]);
	int bsize=r1/thrcnt;
	if(r1%thrcnt!=0)
		thrcnt++;

	pthread_t *tid = (pthread_t*)malloc(sizeof(pthread_t)*thrcnt);

	void* (*fun)(void*);
	fun = &matpro;

	int j,k;
	for(i=0;i<thrcnt;i++)
	{
		Args *args = (Args*)malloc(sizeof(Args));
		args->rs=i*bsize;
		if((i+1)*bsize>r1)
			args->re=r1;
		else
			args->re=(i+1)*bsize;
		args->cs=0;
		args->ce=c2;

		pthread_create((tid+i),NULL,fun,(void*)args);
		pthread_join(tid[i],NULL);
	}

	matprint(C,r1,c2,argv[2]);
	return 0;
}
