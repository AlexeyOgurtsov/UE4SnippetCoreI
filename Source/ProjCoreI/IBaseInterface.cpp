#include "IBaseInterface.h"

int32 IBaseInterface::UseMeInTestHelper() const
{
	return 3;
}

int32 IBaseInterface::TestHelper_GetValue() const
{
	return UseMeInTestHelper();
}

int32 IBaseInterface::TestHelper_GetValue_UseNativeFunction() const
{
	// Fails to compile: we must pass UObject when calling native function!
	// int32 Result = Execute_TestHelper_GetValue_NativeEvent(this);

	int32 Result = TestHelper_GetValue_NativeEvent_WithImpl_Implementation();
	return Result;
}

// ATTENTION!!! When defining implementation of the native event we must,
// Define it in the HEADER also!
int32 IBaseInterface::TestHelper_GetValue_NativeEvent_WithImpl_Implementation() const
{
	return 3;
}

void IBaseInterface::DoStaticCall(IBaseInterface* InInterface)
{
}