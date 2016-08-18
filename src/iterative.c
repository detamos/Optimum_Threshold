#include<math.h>
#include<stdio.h>
#define undefined -1

int iterative(int **pixels,int row,int col)
{	
	FILE *result = NULL;
	result = fopen("../results/iterative/result.dat","w");
	if(result == NULL)
	{
		printf("ERROR : Cannot open file !!\n");
		return;
	}
	printf("File is open\n");
	float size_a,size_b,var_a,var_b,mean_a,mean_b,disc_index,diff;
	int th,i,j,opt_th;
	
	diff = 256;
	
	for(th=0;th<256;th++)
	{
		size_a = size_b = 0;
		var_a = var_b = 0;
		mean_a = mean_b = 0;
		
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(pixels[i][j] <= th)
				{
					size_a++;
					mean_a += pixels[i][j];
				}
				else
				{
					size_b++;
					mean_b += pixels[i][j];
				}
		if((!size_a)||(!size_b))
			continue;
		if(diff > fabs(size_a - size_b))	
		{
			diff = fabs(size_a - size_b);
			opt_th = th;
		}			
		mean_a = (size_a)? mean_a/size_a : undefined;
		mean_b = (size_b)? mean_b/size_b : undefined;		
	
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(pixels[i][j] <= th)
					var_a += (pixels[i][j] - mean_a)*(pixels[i][j] - mean_a);
				else
					var_b += (pixels[i][j] - mean_b)*(pixels[i][j] - mean_b);
					
		var_a = (size_a)? var_a/size_a : undefined;
		var_b = (size_b)? var_b/size_b : undefined;
		
		disc_index = (size_a)? (fabs(mean_a-mean_b)/sqrt(var_a+var_b)) : undefined;
							
		fprintf(result,"%d\t%f\t%f\n",th,disc_index,size_a/size_b);
	}
	fclose(result);
	return opt_th;
}
