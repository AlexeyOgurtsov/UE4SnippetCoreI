#pragma once

#include "IDerivedInterface.h"
#include "ImplObj.generated.h"

class AActor;
class UDamageType;

UCLASS(Blueprintable)
class UImplObj : public UObject, public IDerivedInterface
{
	GENERATED_BODY()
public:
	virtual void DerivedTest() override;

	virtual void Test() override;
	virtual void ConstTest() const override;
	virtual const int32& GetMyInt() const override { return MyInt; }
	virtual const FMyStruct& GetMyStruct() const override { return MyStruct; }
	// Compiles good
	virtual void TakeActor(AActor* A) override;
	virtual void TakeTheDamage(UDamageType* D) override;

	// Note how we implementing BlueprintNativeEvent interface: 
	virtual void TestBPNativeCall_Implementation() const override;

	virtual int32 GetBPNativeCall_Implementation() const override { return -1; }

	// Fails to compile
	//virtual const int32& GetMyIntBPNativeCall_Implementation() const override { return MyInt; }
	// Fails to compile
	//virtual const int32& GetMyIntBPNativeCall_Implementation() const override { return MyIntProp; }

	// Fails to compile
	//virtual const FMyStruct& GetMyStructNativeBP_Implementation() const override;

	virtual void BPNativeCallOutStruct_Implementation(FMyStruct& OutStruct) const override
	{
		OutStruct =  MyStruct;
	}

	virtual void BPNativeCallOutStructUParam_Implementation(FMyStruct& OutStruct) const override
	{
		OutStruct =  MyStruct;
	}

	// WORKS fine!
	virtual void TakeActorNativeBP_Implementation(AActor* A) override;

	// WORKS fine!
	virtual void TakeTestObjNativeBP_Implementation(UTestObj* Obj) override;	

	virtual void TakeEngineMessageNativeBP_Implementation(UEngineMessage* M) override;

	virtual void TakeObjNativeBP_Implementation(UObject* Obj) override;

	// Failes to compile EVER if UDamageType header is included! We need const!!!
	//virtual void TakeTheDamageNativeBP_Implementation(UDamageType* D) override;
	// OK: As UDamageType is a CONST class: works fine!!!
	virtual void TakeTheDamageNativeBP_Implementation(const UDamageType* D) override;

	// UObject::BeginDestroy: for debug purposes (like destructor)
	virtual void BeginDestroy() override;

protected:	
	virtual void ProtectedTest() override;

private:
	virtual void PrivateTest() override;

	FMyStruct MyStruct;
	int32 MyInt = 1;

	UPROPERTY()
	FMyStruct MyStructProp;

	UPROPERTY()
	int32 MyIntProp = 1;
};
