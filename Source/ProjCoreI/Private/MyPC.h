#pragma once

#include "GameFramework/PlayerController.h"
#include "ImplObj.h"
#include "MyPC.generated.h"

UCLASS()
class AMyPC : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	/**
	* Classes of objects.
	*/
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UImplObj> ObjClass;

	// The TSubclassOf<IntefaceName> compiles, BUT!!!
	// You must rather use form with (Meta = (MustImplement = Interfacename))
	// (otherwise you will be unable to choose anything)
	UPROPERTY(EditDefaultsOnly, Meta=(MustImplement = BaseInterface))
	TSubclassOf<UObject> BaseInterfaceClass;

	/**
	* Objects to test interface calls on
	*/
	UImplObj* Obj = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UImplObj* ObjProp = nullptr;

	// Non-property
	IBaseInterface* BaseInterface = nullptr;

	// Fails to compile: "UPropertyPointers cannot be interfaces - did you mean TScriptInterface?"
	//UPROPERTY()
	//IBaseInterface* BaseInstanceProp = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = InterfaceTest)
	TScriptInterface<IBaseInterface> BaseInterfaceProp = nullptr;

private:
	UFUNCTION(BlueprintCallable)
	void Test_ImplementationsInInterface();

	UFUNCTION(BlueprintCallable)
	void Test_Casts();

	UFUNCTION(BlueprintCallable)
	void Test_UInterface();
};
