#pragma once

/**
* Quick implementation of the Save system.
*/

#include "IMySaveLoadSystemInternal.h"
#include "MySaveLoadSystemQuick.generated.h"

UCLASS()
class UMySaveLoadSystemQuick : 
	public UObject, 
	public IMySaveLoadSystemInternal
{
	GENERATED_BODY()

public:
	// ~IMySaveLoadSystem Begin

	/**
	* Warning: Only passing TScriptInterface<IMySaveable> BY REFERENCE compiles!!!
	* (const TScriptInterface<IMySaveableHandle>&).
	*/
	virtual void MyNativeCallTakeScriptInterfaceReference_Implementation(const TScriptInterface<IMySaveableHandle>& InSaveable) override;
	virtual TScriptInterface<IMySaveableHandle> MyNativeCallReturnScriptInterface_Implementation() override;

	//virtual TScriptInterface<IMySaveableHandle> CreateSaveable_Implementation(TScriptInterface<IMySaveable> InSaveable) override;
	//virtual void NotifySaveableDestructed_Implementation(TScriptInterface<IMySaveableHandle> InSaveableHandle) override;

	/**
	* Compilation fails when we take TScriptInterface<IMySaveable>
	*/
	//virtual TScriptInterface<IMySaveableHandle> CreateSaveable_Implementation(TScriptInterface<IMySaveable> InSaveable);
	//virtual void NotifySaveableDestructed_Implementation() override;
	// ~IMySaveLoadSystem End

private:
};