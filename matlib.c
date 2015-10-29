#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matlib.h"

int** matread(char *file)
{
	FILE* fp = fopen(file,"r");
	static int f;
	int r,c;
	fscanf(fp,"%d,%d\n",&r,&c);
	if(f==0)
	{
		r1=r;
		c1=c;
	}
	else
	{
		r2=r;
		c2=c;
	}

	int** mat = (int**)malloc(sizeof(int*)*r);
	int i;
	for(i=0;i<r;i++)
		mat[i]=(int*)malloc(sizeof(int)*c);
	int j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c-1;j++)
		{
			fscanf(fp,"%d,",mat[i]+j);
		}
		fscanf(fp,"%d\n",mat[i]+j);
	}
	f++;
	return mat;
}

void matprint(int** mat,int r,int c,char *file)
{
	int i,j;
	FILE *fp = fopen(file,"w");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			fprintf(fp,"%d ",mat[i][j]);
		fprintf(fp,"\n");
	}
}

int** mattra(int** mat,int r,int c)
{
	int i,j;
	int** mat1 = (int**)malloc(sizeof(int*)*c);
	for(i=0;i<c;i++)
		mat1[i]=(int*)malloc(sizeof(int)*r);
	for(i=0;i<c;i++)
		for(j=0;j<r;j++)
			mat1[i][j]=mat[j][i];
	return mat1;
}

void* matpro(void *arg)
{
	Args *args=(Args*)arg;
	// print(args);
	// printf("Hi\n");
	int i,j,k;
	for(i=args->rs;i<args->re;i++)
		for(j=args->cs;j<args->ce;j++)
			for(k=0;k<c1;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
	pthread_exit((void*)2);
}

void print(Args *args)
{
	printf("%d %d %d %d\n",args->rs,args->re,args->cs,args->ce);
}
