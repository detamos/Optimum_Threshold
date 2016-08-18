#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}list;


list *push(int data,list *top)
{
	if(top == NULL)
	{
		top = (list*) malloc(sizeof(list));
		top->data = data;
		return top;
	}
	list *temp = NULL;
	temp = (list*) malloc(sizeof(list));
	temp->data = data;
	temp->next = top;
	top = temp;
	return top;
}

list *pop(list *top)
{
	if(top == NULL)
		return NULL;
	list *temp = NULL;
	temp = top;
	top = top->next;
	free(temp);
	return top;
}

list* empty(list *top)
{
	while(top)
		top = pop(top);
	return(top);
}


void print_list(list *top)
{
	FILE *file = NULL;
	file = fopen("i.txt","w");
	if(top == NULL)
		return;
	list *temp = NULL;
	temp = top;
	do
		fprintf(file,"%d\n",temp->data);
	while(temp = temp->next);
}

#endif
