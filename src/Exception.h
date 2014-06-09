#ifndef Exception_H
#define Exception_H

int divide(int x,int y);
int doSomethingWhichGeneratesNoException(int value);
int doSomethingWhichGeneratesException(int value);

typedef enum {ERR_NO_ERROR,
			  ERR_DIVIDE_BY_ZERO,
			  ERR_DONT_LIKE_THAT_VALUE,
			  ERR_I_TRY_2_B_NASTY} ErrorCode ;
#endif // Exception_H
