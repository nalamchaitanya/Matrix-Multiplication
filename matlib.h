/**
 * Nalam V S S Krishna Chaitanya
 * Matrix library.
 */

#ifndef MATLIB_H
#define MATLIB_H

extern int** A;
extern int** B;
extern int** C;
extern int r1,c1,r2,c2;

typedef struct _Args
{
	int rs;
	int re;
	int cs;
	int ce;
}Args;

int** matread(char *file);

void matprint(int** mat,int r,int c);

int** mattra(int** mat,int r,int c);

void matpro(Args *args);

#endif
