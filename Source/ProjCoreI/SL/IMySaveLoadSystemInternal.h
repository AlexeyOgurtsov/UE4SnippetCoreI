#pragma once

/**
* Interface for doing internal calls from the save system itself.
*/

#include "IMySaveLoadSystem.h"
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