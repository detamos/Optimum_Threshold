#include<math.h>
#include<stdio.h>
//#include"linked_list.h"
#define undefined -1

int efficient(int **pixels,int row,int col)
{	
	FILE *result = NULL;
	result = fopen("../results/efficient/result.dat","w");
	if(result == NULL)
	{
		printf("ERROR : Cannot open file !!\n");
		return;
	}

	int hash[256]={0},cum_hash[256]={0},i,j,th,opt_th;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			hash[pixels[i][j]]++;
			cum_hash[pixels[i][j]]++;
		}

	for(i=1;i<256;i++)
		cum_hash[i] += cum_hash[i-1];

	float size_a,size_b,var_a,var_b,mean_a,mean_b,disc_index,diff;
	
	diff = 256;
	for(th=0;th<256;th++)
	{
	
		size_a = cum_hash[th];
		size_b = cum_hash[255] - cum_hash[th];
		if(diff > fabs(size_a - size_b))
		{
			diff = fabs(size_a - size_b);
			opt_th = th;
		}
		
		mean_a = mean_b = 0;
		var_a = var_b = 0;
		for(j=0;j<=th;j++)
			mean_a += (j*hash[j]);
		for(j=th+1;j<256;j++)
			mean_b += (j*hash[j]);
		
		if((!size_a) || (!size_b))
			continue;
		mean_a = (size_a)? mean_a/size_a : undefined;
		mean_b = (size_b)? mean_b/size_b : undefined;
	
		for(j=0;j<=th;j++)
			var_a += (hash[j]*(j-mean_a)*(j-mean_a));
		for(j=th+1;j<256;j++)
			var_b += (hash[j]*(j-mean_b)*(j-mean_b));

		var_a = (size_a)? var_a/size_a : undefined;
		var_b = (size_b)? var_b/size_b : undefined;
		
		disc_index = (size_a)? (fabs(mean_a-mean_b)/sqrt(var_a+var_b)) : undefined;
							
		fprintf(result,"%d\t%f\t%f\n",th,disc_index,size_a/size_b);
	}
	return opt_th;
	fclose(result);
}
