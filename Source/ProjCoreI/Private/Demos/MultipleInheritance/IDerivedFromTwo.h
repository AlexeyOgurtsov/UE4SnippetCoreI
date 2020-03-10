#pragma once

#include "IDerivedFromTwoBase1.h"
#include "IDerivedFromTwoBase2.h"
#include "IDerivedFromTwo.generated.h"

// WARNING!!!!
// Interface can ONLY inherit up to ONE other interface!!!
// (Otherwise - how should we inherit many U classes?)

UINTERFACE(BlueprintType)
class UDerivedFromTwo : 
	public UDerivedFromTwoBase1
// ERROR: Missing { in class!!!
//,	public UDerivedFromTwoBase2
{
	GENERATED_BODY()

public:
};

class IDerivedFromTwo : 
	public IDerivedFromTwoBase1
//,	public IDerivedFromTwoBase2
{
	GENERATED_BODY()

public:
};
