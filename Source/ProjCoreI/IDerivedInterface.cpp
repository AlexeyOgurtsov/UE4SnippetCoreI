#include "IDerivedInterface.h"

int32 IDerivedInterface::UseMeInTestHelper() const
{
	return 5;
}

// ATTENTION!!! When defining implementation of the native event we must,
// Define it in the HEADER also!
int32 IDerivedInterface::TestHelper_GetValue_NativeEvent_WithImpl_Implementation() const
{
	auto SuperValue = IBaseInterface::TestHelper_GetValue_NativeEvent_WithImpl_Implementation();

	return 5;
}