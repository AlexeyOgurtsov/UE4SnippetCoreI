#pragma once

#include "UObject/Interface.h"// We DO need it (see my UE4 build doc)
#include "IMyEmptyInterface.generated.h"

UINTERFACE()
class UMyEmptyInterface : public UInterface
{
	GENERATED_BODY()
};

class IMyEmptyInterface
{
	GENERATED_BODY()

public:
};