#pragma once

/**
* Public interface of the save system (for calls from IMySaveable, for example).
*/
#include "IMySaveable.h"
#include "UObject/ScriptInterface.h" // We Do NEED It
#include "IMySaveLoadSystem.generated.h"

class IMySaveableHandle;
class IMySaveable;

UINTERFACE()
class UMySaveLoadSystem : public UInterface
{
	GENERATED_BODY()
};


class IMySaveLoadSystem
{
	GENERATED_BODY()

public:
	/**
	* Compiles well
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = SaveLoadSystem)
	void MyNativeCall_NotImplementedInDerived();

	/**
	* Compiles well
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = SaveLoadSystem)
	TScriptInterface<IMySaveableHandle> MyNativeCallReturnScriptInterface_NotImplementedInDerived();

	/**
	* Taking script interface by REFERENCE compiles well.
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = SaveLoadSystem)
	void MyNativeCallTakeScriptInterfaceReference_NotImplementedInDerived(const TScriptInterface<IMySaveableHandle>& InSaveable);

	// ~Implemented BlueprintNativeEvent Begin
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = SaveLoadSystem)
	void MyNativeCallTakeScriptInterfaceReference(const TScriptInterface<IMySaveableHandle>& InSaveable);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = SaveLoadSystem)
	TScriptInterface<IMySaveableHandle> MyNativeCallReturnScriptInterface();
	// ~Implemented BlueprintNativeEvent End

	/**
	* Fails to copmile
	*/
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = SaveLoadSystem)
	//void MyNativeCallTakeScriptInterface_NotImplementedInDerived(TScriptInterface<IMySaveableHandle> InSaveable);

	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = SaveLoadSystem)
	//TScriptInterface<IMySaveableHandle> CreateSaveable(TScriptInterface<IMySaveable> InSaveable);

	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = SaveLoadSystem)
	//void NotifySaveableDestructed();
};



