#ifndef DYNAMIC_MEMORY_H
#define DYNAMIC_MEMORY_H

#include<stdlib.h>

int **new_int2D(int row,int col)
{	
	int **mat = NULL;
	mat = (int**) malloc(row*sizeof(int*));
	int i,j;
	for(i=0;i<row;i++)
		mat[i] = (int*) malloc(col*sizeof(int));
			
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			mat[i][j] = 0;
	return(mat);
}

int *new_int1D(int n)
{
	int *arr = NULL;
	arr = (int*) malloc(sizeof(int) * n);
	int i;
	for(i=0;i<n;i++)
		arr[i] = 0;
	return(arr);
}

#endif
