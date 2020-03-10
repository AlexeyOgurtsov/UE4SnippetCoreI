#include "ImplObj.h"
#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(MyILog, Display, All);
DEFINE_LOG_CATEGORY(MyILog);

void UImplObj::DerivedTest()
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::DerivedTest"));
}

void UImplObj::Test() 
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::Test"));
}

void UImplObj::ConstTest() const 
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::ConstTest"));
}

void UImplObj::TestBPNativeCall_Implementation() const
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::BPNativeCall"));
}

void UImplObj::TakeActor(AActor* A)
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::TakeActor"));
}

void UImplObj::TakeTheDamage(UDamageType* D)
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::TakeTheDamage"));
}

//const FMyStruct& UImplObj::GetMyStructNativeBP_Implementation() const
//{
//	return MyStruct;
//}

void UImplObj::ProtectedTest() 
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::ProtectedTest"));
}

void UImplObj::PrivateTest() 
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::PrivateTest"));
}

void UImplObj::TakeActorNativeBP_Implementation(AActor* A)
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::TakeActorNativeBP"));
}

void UImplObj::TakeTestObjNativeBP_Implementation(UTestObj* Obj)
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::TakeTestObjNativeBP"));
}

void UImplObj::TakeObjNativeBP_Implementation(UObject* Obj)
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::TakeObjNativeBP"));
}

void UImplObj::TakeEngineMessageNativeBP_Implementation(UEngineMessage* M) 
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::TakeEngineMessageNativeBP"));
}

void UImplObj::TakeTheDamageNativeBP_Implementation(const UDamageType* D)
{
	UE_LOG(MyILog, Display, TEXT("UImplObj::TakeTheDamageNativeBP"));
}

void UImplObj::BeginDestroy()
{
	Super::BeginDestroy();
	UE_LOG(MyILog, Display, TEXT("UImplObj::BeginDestroy, this=%p"), this);
}
