#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<string.h>
#include<stdlib.h>

char *merge(char *str1,const char *str2)
{
	char *str = NULL;
	int len1 = strlen(str1),len2 = strlen(str2),i,j;
	str = (char*) malloc(sizeof(char) * (len1+len2));
	
	for(i=0;i<len1;i++)
		str[i] = str1[i];
	for(i=0;i<len2;i++)
		str[len1+i] = str2[i];
		
	return(str); 
}

#endif
