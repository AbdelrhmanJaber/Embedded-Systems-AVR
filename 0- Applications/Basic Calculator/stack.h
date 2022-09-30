#ifndef STACK_H
#define STACK_H

typedef struct myStruct
{
	u8 data;
	struct myStruct *next;
}Stack;

typedef struct myStruct2
{
	f32 data;
	struct myStruct2 *next;
}evaluateStack;

Stack*CreateStack(Stack*TopStack);
Stack*push(Stack*TopStack,u8 data);
Stack*pop(Stack*TopStack,u8*data);
void TopElement(Stack*TopStack,u8*data);
u8 StackEmpty(Stack*TopStack);

evaluateStack*CreateStack2(evaluateStack*TopStack);
evaluateStack*push2(evaluateStack*TopStack,f32 data);
evaluateStack*pop2(evaluateStack*TopStack,f32*data);

#endif