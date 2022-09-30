#include "std_types.h"
#include "stack.h"
#include<stdlib.h>
#include<stdio.h>

Stack*CreateStack(Stack*TopStack)
{
	TopStack=NULL;
	return TopStack;
}

Stack*push(Stack*TopStack,u8 data)
{
	Stack*temp=(Stack*)malloc(sizeof(Stack));
	temp->data=data;
	temp->next=TopStack;
	TopStack=temp;
	return TopStack;
}

Stack*pop(Stack*TopStack,u8*data)
{
	Stack*temp=TopStack;
	*data=temp->data;
	TopStack=temp->next;
	free(temp);
	return TopStack;
}

void TopElement(Stack*TopStack,u8*data)
{
	*data=TopStack->data;
}

u8 StackEmpty(Stack*TopStack)
{
	if(TopStack==NULL)
		return 1;
	else
		return 0;
}

evaluateStack*CreateStack2(evaluateStack*TopStack)
{
	TopStack=NULL;
	return TopStack;
}

evaluateStack*push2(evaluateStack*TopStack,f32 data)
{
	evaluateStack*temp=(evaluateStack*)malloc(sizeof(evaluateStack));
	temp->data=data;
	temp->next=TopStack;
	TopStack=temp;
	return TopStack;
}

evaluateStack*pop2(evaluateStack*TopStack,f32*data)
{
	evaluateStack*temp=TopStack;
	*data=temp->data;
	TopStack=temp->next;
	free(temp);
	return TopStack;
}
