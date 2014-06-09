#include "Exception.h"
#include "CException.h"
#include <stdio.h>

int divide(int x,int y)
{
	if (y == 0 )
		Throw(ERR_DIVIDE_BY_ZERO);
		
	return x/y;
}

int doSomethingWhichGeneratesException(int value)
{
	if (value == 25)
		Throw(ERR_DONT_LIKE_THAT_VALUE);
		
	printf("Ok.Value %d looks just fine.\n",value);
}

int doSomethingWhichGeneratesNoException(int value)
{
	doSomethingWhichGeneratesException(value);
	printf("Hehehe...got through!\n");
}

int a()
{
	printf("Entering a().\n");
	Throw(ERR_I_TRY_2_B_NASTY);
	printf("Exiting a().\n");
}

int z()
{
	CEXCEPTION_T err;
	int isErr = 0;
	
	printf("Entering z().\n");
	Try
	{
		a();
	} 
	Catch(err)
	{
		isErr = 1;
	}
	printf("Exiting z().\n");
	if (isErr)
		Throw(err);
}

int y()
{
	printf("Entering y().\n");
	z();
	printf("Exiting y().\n");
}