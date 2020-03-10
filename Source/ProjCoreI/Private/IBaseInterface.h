#pragma once

// WARNING!!! Compiles ever we do NOT include headers!
//#include "GameFramework/Actor.h" 
//#include "GameFramework/DamageType.h"
//#include "GameFramework/EngineMessage.h"
//#include "TestObj.h"
#include "UObject/Interface.h"// We DO need it (see my UE4 build doc)
#include "IBaseInterface.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FMyStruct
{
	GENERATED_BODY()

	UPROPERTY()
	float Value = 0.0F;
};

UINTERFACE(BlueprintType)
class UBaseInterface : public UInterface
{
	GENERATED_BODY()
};

class IBaseInterface 
{
	GENERATED_BODY()

public:
	virtual void Test() =0;
	virtual void ConstTest() const =0;
	// Compiles well
	virtual const int32& GetMyInt() const = 0;
	// Compiles well
	virtual const FMyStruct& GetMyStruct() const = 0;	
	virtual void TakeActor(AActor* A) = 0;
	virtual void TakeTheDamage(UDamageType* D) = 0;

	// FAILS TO COMPILE: There're NO BlueprintPure in interfaces!!!
	//UFUNCTION(BlueprintPure)
	//int32 CalcluateSum(int32 A, int32 B) const;

	// FAILS TO COMPILE: WARNING!!! BlueprintCallable and BlueprintNativeEvent must always be together:
	//UFUNCTION(BlueprintCallable)
	//virtual void TestBP() =0;

	// BlueprintNativeEvent:
	// 1) We specified both BlueprintNativeEvent and BlueprintCallable
	// 2) We do can specify const
	// 2) virtual is NOT specifier
	// NOTE: When we implement we declare as "virtual BPNativeCall_Implementation() const override"
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TestBPNativeCall() const;

	// Compiles well
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 GetBPNativeCall() const;

	// Does NOT work: seams like returning references to types cannot be done 
	// with BlueprintNativeEvent
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	//const int32& GetMyIntBPNativeCall() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)	
	void BPNativeCallOutStruct(FMyStruct& OutStruct) const;


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)	
	void BPNativeCallOutStructUParam(UPARAM(Ref) FMyStruct& OutStruct) const;

	// Fails to compile: why? Because we return reference in BlueprintNativeEvent
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	//const FMyStruct& GetMyStructNativeBP() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TakeActorNativeBP(AActor* A);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TakeTestObjNativeBP(UTestObj* Obj);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TakeObjNativeBP(UObject* Obj);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TakeEngineMessageNativeBP(UEngineMessage* M);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TakeTheDamageNativeBP(const UDamageType* D);

	// ~Methods with implementations in interface Begin
	virtual int32 UseMeInTestHelper() const;
	int32 TestHelper_GetValue() const;
	int32 TestHelper_GetValue_UseNativeFunction() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 TestHelper_GetValue_NativeEvent() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 TestHelper_GetValue_NativeEvent_WithImpl() const;
	// WARNING! Do NOT specify OVERRIDE when defininig default implementation of the interface function (compile error)!
	virtual int32 TestHelper_GetValue_NativeEvent_WithImpl_Implementation() const;
	// ~Methods with implementations in interface End

	// ~Testing static methods for interface Begin
	static void DoStaticCall(IBaseInterface* Obj);
	// ~Testing static methods for interface End

protected:	
	virtual void ProtectedTest() = 0;

private:
	virtual void PrivateTest() = 0;
};
