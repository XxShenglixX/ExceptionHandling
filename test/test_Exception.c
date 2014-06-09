#include "unity.h"
#include "Exception.h"
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_divide_given_5_and_2_should_get_2()
{
	CEXCEPTION_T err;
	Try
	{
		TEST_ASSERT_EQUAL(2,divide(5,2));
		printf("Success: No exception generated.");	
	}
	Catch(err)
	{
		TEST_FAIL_MESSAGE("Do not expect exception to be generated.");
	}
}

void test_divide_given_13_and_0_should_get_2()
{
	CEXCEPTION_T err;
	Try
	{
		TEST_ASSERT_EQUAL(0,divide(13,0));
		TEST_FAIL_MESSAGE("Should generate an exception due to divide by 0.");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_DIVIDE_BY_ZERO,err);
		printf("Success: Exception generated. Error code: %d",err);
	}
}

void test_doSomethingWhichGeneratesNoException_given_7_should_not_throw_exception()
{
	CEXCEPTION_T err;
	Try
	{
		doSomethingWhichGeneratesNoException(7);
	}
	Catch(err)
	{
		TEST_FAIL_MESSAGE("Should NOT generate an exception due to divide by 0.");
	}
}

void test_doSomethingWhichGeneratesNoException_given_25_should_throw_an_exception()
{
	CEXCEPTION_T err;
	Try
	{
		doSomethingWhichGeneratesNoException(25);
		TEST_FAIL_MESSAGE("Should generate an exception, but did not");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_DONT_LIKE_THAT_VALUE,err);
	}
}

void test_y_should_throw_an_exception()
{
	CEXCEPTION_T err;
	Try
	{
		y();
		TEST_FAIL_MESSAGE("Should generate an exception, but did not");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_I_TRY_2_B_NASTY,err);
		printf("Caught an exception\n");
	}
}