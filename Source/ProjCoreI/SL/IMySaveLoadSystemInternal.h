#pragma once

/**
* Interface for doing internal calls from the save system itself.
*/

#include "IMySaveLoadSystem.h"
#include "UObject/ScriptInterface.h" // We Do NEED It
#include "IMySaveLoadSystemInternal.generated.h"

UINTERFACE()
class UMySaveLoadSystemInternal : public UMySaveLoadSystem
{
	GENERATED_BODY()
};

class IMySaveLoadSystemInternal : public IMySaveLoadSystem
{
	GENERATED_BODY()

public:
};