#include<stdio.h>
#include<time.h>
#include"../include/dynamic_memory.h"
#include"../include/functions.h"
#include"opt_thresh.c"

int main(int argc,const char *argv[])
{	
	if(argc != 2)
	{
		printf("ERROR : Wrong number of arguments!!\n");
		return (1);
	}
	
	FILE *input = NULL,*resTXT = NULL;
	
	char *str = "../data/txt/";
	str = merge(str,argv[1]);
	input = fopen(str,"r");
	if(input == NULL)
	{
		printf("ERROR : Cannot open the input file!!\n");
		return (1); 
	}
	
	resTXT = fopen("../results/res.txt","w");

	int **pixels = NULL,col,row,i,j;
	clock_t start,end;
	
	fscanf(input,"%d%d\n",&row,&col);
	
	pixels = new_int2D(row,col);
	if(pixels == NULL)
	{
		printf("ERROR : Cannot allocate memory !!\n");
		return(1);
	}
	
	printf("Reading the input data....\n");	
	start = clock();
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			fscanf(input,"%d",&pixels[i][j]);
	end = clock();
	
	double time = (double)(end - start)/CLOCKS_PER_SEC;
	
	printf("Data Read in %lf ms \n",(time * 1000));
	fprintf(resTXT,"Time taken for taking input : %lf ms\n",time*1000);	
	fclose(resTXT);
	OPT_Thresh(pixels,row,col);
	
	resTXT = fopen("../results/res.txt","a");		
	
	fprintf(resTXT,"\n\n\nAs we can see both the methods are generating same optimum value\n\n");
	
	fprintf(resTXT,"Our task in the question was to find the optimum threshold, which basically divides our image in two parts fore ground and background\nSo we have found an optimum threshold for our problem for which the number of pixels with gray value less than our threshold is equal to the number of pixels with gray value greater than our threshold\n");
	fclose(resTXT);
	fclose(input);				
	return 0;
}
