#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv)
{
	if(argc!=5)
	{
		printf("InputFile Repitition MaxThread OutputFile\n");
		exit(1);
	}
	int rep,mtrd,i,j;
	rep = atoi(argv[2]);
	mtrd = atoi(argv[3]);
	FILE *fp = fopen(argv[1],"r");
	FILE *fq = fopen(argv[4],"w");
	for(i=1;i<=mtrd;i++)
	{
		double temp,tem;
		temp=0;
		for(j=0;j<rep;j++)
		{
			fscanf(fp,"%lf\n",&tem);
			temp+=tem;
		}
		fprintf(fq, "%d %f\n",i,temp/rep);
	}
	fclose(fp);
	fclose(fq);
	return 0;
}
