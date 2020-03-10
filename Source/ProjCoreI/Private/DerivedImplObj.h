#pragma once

/**
* Instruction for how to override interface functions correctly.
*/

#include "ImplObj.h"
#include "DerivedImplObj.generated.h"

UCLASS()
class UDerivedImplObj : public UImplObj
{
	GENERATED_BODY()

public:
	/**
	* Overriding ordinary C++ function:
	*/
	virtual void TakeActor(AActor* A) override;

	/**
	* Overriding BP-NativeCall function:
	*/
	virtual void TestBPNativeCall_Implementation() const override;
};