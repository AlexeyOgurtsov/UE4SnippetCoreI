#pragma once

#include "IBaseInterface.h"
#include "IDerivedInterface.generated.h"

UINTERFACE()
class UDerivedInterface : public UBaseInterface
{
	GENERATED_BODY()
};

class IDerivedInterface : public IBaseInterface
{
	GENERATED_BODY()

public:
	virtual void DerivedTest() = 0;

	// ~Methods with implementations in interface Begin
	virtual int32 UseMeInTestHelper() const override;
	virtual int32 TestHelper_GetValue_NativeEvent_WithImpl_Implementation() const override;
	// ~Methods with implementations in interface End

};