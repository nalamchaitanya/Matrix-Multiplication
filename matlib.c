#include <stdio.h>
#include <stdlib.h>
#include "matlib.h"

int** matread(char *file)
{
	FILE* fp = fopen(file,"r");
	int r,c;
	fscanf(fp,"%d,%d\n",&r,&c);

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
	return mat;
}

void matprint(int** mat,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
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
