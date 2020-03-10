#include "DerivedImplObj.h"
#include "Logging/LogMacros.h"

void UDerivedImplObj::TakeActor(AActor* A)
{
	UE_LOG(LogTemp, Log, TEXT("UDerivedImplObj::TakeActor..."));
	Super::TakeActor(A);

	// Testing calling Native call using _Implementation
	UE_LOG(LogTemp, Log, TEXT("Calling UDerivedImplObj::TestBPNativeCall_Implementation."));
	TestBPNativeCall_Implementation();

	// Testing calling Native call using IBaseInterface::Execute_TestBPNativeCall
	UE_LOG(LogTemp, Log, TEXT("Calling IBaseInterface::Execute_TestBPNativeCall."));
	IBaseInterface::Execute_TestBPNativeCall(this);
}

void UDerivedImplObj::TestBPNativeCall_Implementation() const
{
	UE_LOG(LogTemp, Log, TEXT("UDerivedImplObj::TestBPNativeCall_Implementation..."));
	Super::TestBPNativeCall_Implementation();
}