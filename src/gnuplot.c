#include<stdio.h>

void gnuplot(char *infile,char *outfile)
{
	FILE *gnuplotPipe = NULL;
	gnuplotPipe = popen("gnuplot","w");
	
//	fprintf(gnuplotPipe,"set term wxt enhanced \nset title \"Threshold vs Discriminative Index\"\nset ylabel \"Discriminative Index\"\nset xlabel \"Threshold\"\nset autoscale\nplot '%s' using 1:2 with lines\n",infile);
	
	fprintf(gnuplotPipe,"set term png\nset output '%s/a.png'\nset title \"Threshold vs Discriminative Index\"\nset ylabel \"Discriminative Index\"\nset xlabel \"Threshold\"\nset autoscale\nplot '%s' using 1:2 with lines\n",outfile,infile);
	
	//fprintf(gnuplotPipe,"set term wxt enhanced \nset title \"Threshold vs Ratio of Points\"\nset ylabel \"Ratio of Points\"\nset xlabel \"Threshold\"\nset autoscale\nplot '%s' using 1:3 with lines\n",infile);
	
	fprintf(gnuplotPipe,"set term png\nset output '%s/b.png'\nset title \"Threshold vs Ratio of Points\"\nset ylabel \"Ratio of Points\"\nset xlabel \"Threshold\"\nset autoscale\nplot '%s' using 1:3 with lines\n",outfile,infile);
	
//	fprintf(gnuplotPipe,"set term wxt enhanced \nset title \"Discriminative Index vs Ratio of Points\"\nset ylabel \"Ratio of Points\"\nset xlabel \"Discriminative Index\"\nset autoscale\nplot '%s' using 3:2 with lines\n",infile);
	
	fprintf(gnuplotPipe,"set term png\nset output '%s/c.png'\nset title \"Discriminative Index vs Ratio of Points\"\nset ylabel \"Ratio of Points\"\nset xlabel \"Discriminative Index\"\nset autoscale\nplot '%s' using 3:2 with lines\n",outfile,infile);
	pclose(gnuplotPipe);
}	
