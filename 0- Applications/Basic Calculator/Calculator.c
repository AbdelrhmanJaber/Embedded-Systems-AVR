#include"std_types.h"

#include"MDIO_interface.h"

#include"HLCD_interface.h"
#include"HKPD_interface.h"

#include"stack.h"


void InfixToPostfix (u8 infix[],u8 postfix[],u8 checkNegative);
u8 IsDigit(u8 digit);
u8 Precedent(u8 op1,u8 op2);
f32 evaluatePostfix(u8 postfix[]);
f32 operation(f32 op1,f32 op2,u8 c);
u8 IsOperand(u8 operand);

int main()
{
	MDIO_u8INIT();
	HLCD_voidINIT();
	u8 infix[16];
	u8 postfix[16];
	u8 infixIndex=0,checkNegative=0,floatNumber;
	u8 ReturnKeyValue,checkMathError=0,negativePrint=0;
	f32 result;
	while(1)
	{
	  while(1)
	   {
			HKPD_u8GetKey(&ReturnKeyValue);
			if(ReturnKeyValue!=HKPD_u8_NO_KEY_PRESSED)
			{
			HLCD_u8SendChar(ReturnKeyValue);
			if(ReturnKeyValue=='=')
				break;
			else
			  infix[infixIndex++]=ReturnKeyValue;
			}
		}
	  if(IsOperand(infix[infixIndex-1]))
		  checkMathError=1;
	  infix[infixIndex]='\0';
		if(infix[0]=='-')
				   checkNegative=1;

		for(u8 i=0;infix[i]!='\0';i++)
		{
			if(((IsOperand(infix[i]))&&(IsOperand(infix[i+1])))||((infix[i]=='/')&&(infix[i+1]=='0')))
			{
				checkMathError=1;
				break;
			}
		}
		if(infix[0]=='*'||infix[0]=='/'||infix[0]=='%')
			checkMathError=1;

		if(checkMathError)
		{
			HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
			HLCD_u8SendString("Math Error!",0);
		}
		else
		{
			InfixToPostfix(infix,postfix,checkNegative);
			result=evaluatePostfix(postfix);
			if(result<0)
			{
			  negativePrint=1;
			  floatNumber=(-1*result*100)-(-1*((u32)result)*100);
			  HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
		 	  HLCD_u8SendNumber(-1*(u32)result,floatNumber,negativePrint);
			}
			else
			{
				floatNumber=(result*100)-(((u32)result)*100);
				HLCD_u8SetCursor(HLCD_u8_LINE_2,HLCD_u8_Position_0);
				HLCD_u8SendNumber((u32)result,floatNumber,negativePrint);
			}
		}
	}
	return 0;
}

void InfixToPostfix (u8 infix[],u8 postfix[],u8 checkNegative)
{
	Stack*Topstack;
	Topstack=CreateStack(Topstack);
	u8 PostfixIndex=0;
	u8 op;
	if(checkNegative)
		postfix[PostfixIndex++]='0';

	checkNegative=0;

	for(u8 i=0;infix[i]!='\0';i++)
	{
		if(IsDigit(infix[i]))
			postfix[PostfixIndex++]=infix[i];
		else
		{
			postfix[PostfixIndex++]='n';
			if(!StackEmpty(Topstack))
			{
				TopElement(Topstack,&op);
				while((!StackEmpty(Topstack))&&(Precedent(op,infix[i])))
				{
					/*pop from stack if the priority of new operands less than or equal the operand at topStack*/
					Topstack=pop(Topstack,&op);
					postfix[PostfixIndex++]=op;
					if(!StackEmpty(Topstack)) /*to update its value for while condition*/
						TopElement(Topstack,&op);
				}
			}
			Topstack=push(Topstack,infix[i]);
		}
	}
	postfix[PostfixIndex++]='n'; /*the last number*/
	while(!StackEmpty(Topstack))
		{
			Topstack=pop(Topstack,&op);
			postfix[PostfixIndex++]=op;
		}
		postfix[PostfixIndex]='\0';
}

f32 evaluatePostfix(u8 postfix[])
{
	f32 op1,op2;
	f32 result=0;
	u16 temp=1;
	f32 val=0;
	u8 counter=0,PostfixIndex=0;
	u8 arr[10];
	evaluateStack*Topstack;
	Topstack=CreateStack2(Topstack);
	for(u8 i=0;postfix[PostfixIndex]!='\0';i++)
	{
		if((IsDigit(postfix[PostfixIndex])))
		{
			while(postfix[PostfixIndex]!='n')
			{
				arr[counter++]=(postfix[PostfixIndex++]-'0');
			}
				    PostfixIndex++;
			    for(u8 i=0;i<(counter-1);i++)
		           temp=temp*10;

	            for(u8 i=0;i<counter;i++)
	            {
	            	val=val+(arr[i]*temp);
	            	temp=temp/10;
	            }
				Topstack=push2(Topstack,val);
				counter=0;
				val=0;
				temp=1;
		}
		else
		{
			Topstack=pop2(Topstack,&op2);
			Topstack=pop2(Topstack,&op1);
			result=operation(op1,op2,postfix[PostfixIndex]);
			Topstack=push2(Topstack,result);
			PostfixIndex++;
		}
	}
	Topstack=pop2(Topstack,&result);
	return result;
}

u8 IsDigit(u8 digit)
{
	if((digit>='0')&&(digit<='9'))
		return 1;
	else
		return 0;
}

u8 Precedent(u8 op1,u8 op2)
{
	if((op1=='*')||(op1=='/')||(op1=='%'))
		return 1;
	if((op1=='+')||(op1=='-'))
		return ((op2!='*')&&(op2!='/')&&(op2!='%'));

	return 0;
}

f32 operation(f32 op1,f32 op2,u8 c)
{
	if(c=='+')
	  return (op1+op2);

    if(c=='-')
	  return (op1-op2);

	if(c=='*')
	  return (op1*op2);

    if(c=='/')
	  return (op1/op2);

	if(c=='%')
	  return ((u32)op1%(u32)op2);

	return 0.00;
}

u8 IsOperand(u8 operand)
{
	if((operand=='+')||(operand=='-')||(operand=='*')||(operand=='/')||(operand=='%'))
		return 1;
	else
		return 0;
}
