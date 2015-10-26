#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv)
{
	int lmt = atoi(argv[1]);
	int dim = atoi(argv[2]);

	FILE *fp = fopen("mat1.dat","w");
	int i,j;
	fprintf(fp,"%d,%d\n",dim,dim);
	for(i=0;i<dim;i++)
	{
		for(j=0;j<dim-1;j++)
		{
			fprintf(fp,"%d,",rand()%lmt);
		}
		fprintf(fp,"%d\n",rand()%lmt);
	}
	fclose(fp);

	fp=fopen("mat2.dat","w");
	fprintf(fp,"%d,%d\n",dim,dim);
	for(i=0;i<dim;i++)
	{
		for(j=0;j<dim-1;j++)
		{
			fprintf(fp,"%d,",rand()%lmt);
		}
		fprintf(fp,"%d\n",rand()%lmt);
	}
	fclose(fp);
	return 0;
}
