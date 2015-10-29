#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matlib.h"

int** A;
int** B;
int** C;
int r1,c1,r2,c2;

int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Usage : No of threads , output file.\n");
		return 0;
	}
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

	long str,end;
	struct timespec st,en;
	double runtime;
	int *ret;
	int j,k;
	runtime=0;

	// CLOCK_THREAD_CPUTIME_ID CLOCK_REALTIME
	clock_gettime(CLOCK_MONOTONIC,&st);
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
	}
	for(i=0;i<thrcnt;i++)
		pthread_join(tid[i],(void**)&ret);
	clock_gettime(CLOCK_MONOTONIC,&en);

	runtime = (en.tv_nsec-st.tv_nsec)/1000;
	printf("time for %d threads : %f\n",thrcnt,runtime);
	matprint(C,r1,c2,argv[2]);
	return 0;
}
