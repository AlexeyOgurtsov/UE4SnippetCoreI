#include "MyPC.h"
#include "DerivedImplObj.h"
#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(PCLog, Display, All);
DEFINE_LOG_CATEGORY(PCLog);

void AMyPC::BeginPlay()
{
	Obj = NewObject<UImplObj>(this, ObjClass);
	ObjProp = NewObject<UImplObj>(this, ObjClass);
	BaseInterface = NewObject<UImplObj>(this, ObjClass);
	BaseInterfaceProp = NewObject<UImplObj>(this, ObjClass);

	
	// Calling normal interface functions not UPROPERTY()
	UE_LOG(PCLog, Display, TEXT("APC:: Calling through Obj"));
	if(Obj)
	{
		Obj->Test();
		Obj->ConstTest();
	}

	UE_LOG(PCLog, Display, TEXT("APC:: Calling normal functions"));

	// Calling normal interface functions through UPROPERTY()
	UE_LOG(PCLog, Display, TEXT("APC:: Calling through ObjProp (UPROPERTY())"));
	if(ObjProp)	
	{
		ObjProp->Test();
		ObjProp->ConstTest();
	}

	// Calling normal interface functions through pointer:
	UE_LOG(PCLog, Display, TEXT("APC:: Calling through BaseInterface"));
	if(BaseInterface)
	{
		BaseInterface->Test();
		BaseInterface->ConstTest();
	}

	// Calling normal interface functions through TScriptInterface pointer:
	UE_LOG(PCLog, Display, TEXT("APC:: Calling through BaseInterfaceProp (UPROPERTY())"));
	if(BaseInterfaceProp)
	{
		BaseInterfaceProp->Test();
		BaseInterfaceProp->ConstTest();
	}

	// -------------------------------------------------------------------------------------------
	// Calling BlueprintNativeEvent functions
	UE_LOG(PCLog, Display, TEXT("APC:: Calling BlueprintNativeEvent functions"));

	UE_LOG(PCLog, Display, TEXT("APC:: Calling through Obj"));
	if(Obj)
	{
		// WARNING!!! This will fail!
		//Obj->TestBPNativeCall();

		Obj->Execute_TestBPNativeCall(Obj);
	}

	UE_LOG(PCLog, Display, TEXT("APC:: Calling through ObjProp (UPROPERTY())"));
	if(ObjProp)
	{
		// WARNING!!! This will fail!
		//ObjProp->TestBPNativeCall();

		IBaseInterface::Execute_TestBPNativeCall(ObjProp);
	}

	// Calling normal interface functions through pointer:
	UE_LOG(PCLog, Display, TEXT("APC:: Calling through BaseInterface"));
	if(BaseInterface)
	{
		// WARNING!!! This will fail!
		//BaseInterface->TestBPNativeCall();

		// WARNING!!! It will FAIL to compile, because we need UObject* to be passed as the first arg to Execute!
		//BaseInterface->Execute_TestBPNativeCall(BaseInterface);
		//IBaseInterface::Execute_TestBPNativeCall(BaseInterface);
	}

	// Calling normal interface functions through TScriptInterface pointer:
	UE_LOG(PCLog, Display, TEXT("APC:: Calling through BaseInterfaceProp (UPROPERTY())"));
	if(BaseInterfaceProp)
	{
		// WARNING!!! This will fail!
		//BaseInterfaceProp->TestBPNativeCall();

		BaseInterfaceProp->Execute_TestBPNativeCall(BaseInterfaceProp.GetObject());
	}

	
	// ---------- Testing initializing TScriptInterface:
	// The following will not compile, if we just pass pointer to interface (and NOT object)
	//TScriptInterface<IBaseInterface> I = InterfacePointer;

	
	// Here we pass UObject that does NOT implement base interface:
	// Result:
	TScriptInterface<IBaseInterface> I_NotImpl = this;
	if(I_NotImpl && I_NotImpl.GetInterface())
	{
		UE_LOG(PCLog, Display, TEXT("APC:: I_NotImpl is valid after assignment"));
	}
	else
	{
		UE_LOG(PCLog, Display, TEXT("APC:: I_NotImpl is NOT valid after assignment"));
	}

	if(I_NotImpl)
	{
		UE_LOG(PCLog, Display, TEXT("APC:: if(I_NotImpl) branched as TRUE"));
	}
	else
	{
		UE_LOG(PCLog, Display, TEXT("APC:: if(I_NotImpl) as false"));
	}

	if(I_NotImpl.GetObject())
	{
		UE_LOG(PCLog, Display, TEXT("APC:: if(I_NotImpl.GetObject()) branched as TRUE"));
	}
	else
	{
		UE_LOG(PCLog, Display, TEXT("APC:: if(I_NotImpl.GetObject()) as false"));
	}

	if(I_NotImpl.GetInterface())
	{
		UE_LOG(PCLog, Display, TEXT("APC:: if(I_NotImpl.GetInterface()) branched as TRUE"));
	}
	else
	{
		UE_LOG(PCLog, Display, TEXT("APC:: if(I_NotImpl.GetInterface()) as false"));
	}

	// FAILS to compile:
	//{
	//	if(nullptr == I_NotImpl)
	//	{
	//		UE_LOG(PCLog, Display, TEXT("APC:: if(nullptr == I_NotImpl) branched as TRUE"));
	//	}
	//	else
	//	{
	//		UE_LOG(PCLog, Display, TEXT("APC:: if(nullptr == I_NotImpl) as false"));
	//	}
	//}

	if( ! I_NotImpl)
	{
		UE_LOG(PCLog, Display, TEXT("APC:: if( ! I_NotImpl) branched as TRUE"));
	}
	else
	{
		UE_LOG(PCLog, Display, TEXT("APC:: if( ! I_NotImpl) as false"));
	}

	// Here we pass object that DO implement interface:
	TScriptInterface<IBaseInterface> I_FromObj = Obj;
	if(I_FromObj)
	{
		UE_LOG(PCLog, Display, TEXT("APC:: I_FromObj is valid after assignment"));
	}
	else
	{
		UE_LOG(PCLog, Display, TEXT("APC:: I_FromObj is nullptr after assignment"));
	}
	if(I_FromObj.GetInterface())
	{
		UE_LOG(PCLog, Display, TEXT("APC:: I_FromObj.GetInterface() is valid after assignment"));
	}
	else
	{
		UE_LOG(PCLog, Display, TEXT("APC:: I_FromObj.GetInterface() is nullptr after assignment"));
	}

	Test_ImplementationsInInterface();
	Test_Casts();
	Test_UInterface();

	UE_LOG(PCLog, Display, TEXT("Calling TakeActor..."));
	UDerivedImplObj* MyDerivedObj = NewObject<UDerivedImplObj>(this, UDerivedImplObj::StaticClass());
	MyDerivedObj->TakeActor(this);
	UE_LOG(PCLog, Display, TEXT("Calling TakeActor DONE"));
}

void AMyPC::Test_ImplementationsInInterface()
{
	UE_LOG(PCLog, Display, TEXT("AMyPC::Test_ImplementationsInInterface..."));
	UImplObj* const MyImplObj = NewObject<UImplObj>(this, ObjClass);
	IDerivedInterface* const ObjByIfc = MyImplObj;

	{
		int32 const GettedValue = ObjByIfc->TestHelper_GetValue();
		UE_LOG(PCLog, Display, TEXT("ObjByIfc->TestHelper_GetValue() returned %d"), GettedValue);
	}

	{
		int32 const GettedValue_UsingNativeFunction = ObjByIfc->TestHelper_GetValue_UseNativeFunction();
		UE_LOG(PCLog, Display, TEXT("ObjByIfc->TestHelper_GetValue_UseNativeFunction() returned %d"), GettedValue_UsingNativeFunction);
	}

	{
		int32 const GettedValue_NativeEvent = IBaseInterface::Execute_TestHelper_GetValue_NativeEvent_WithImpl(MyImplObj);
		UE_LOG(PCLog, Display, TEXT("IBaseInterface::Execute_TestHelper_GetValue_NativeEvent_WithImpl(MyImplObj) returned %d"), GettedValue_NativeEvent);
	}

	{
		int32 const GettedValue_UseMeInTestHelper = ObjByIfc->UseMeInTestHelper();
		UE_LOG(PCLog, Display, TEXT("ObjByIfc->UseMeInTestHelper() returned %d"), GettedValue_UseMeInTestHelper);	
	}

	UE_LOG(PCLog, Display, TEXT("AMyPC::Test_ImplementationsInInterface DONE"));
}

void AMyPC::Test_Casts()
{
	UE_LOG(PCLog, Display, TEXT("AMyPC::Test_Casts..."));

	UImplObj* const MyImplObj = NewObject<UImplObj>(this, ObjClass);
	IDerivedInterface* const InterfacePtr = MyImplObj;

	{
		// Casting interface pointer back to UObject:
		UObject* const MyObj = Cast<UObject>(InterfacePtr);
		UE_LOG(PCLog, Display, TEXT("Cast<UObject>(InterfacePtr) returned \"%s\""), MyObj ? TEXT("VALID") : TEXT("nullptr"));
	}	

	{
		// Casting interface pointer back to UImplObj:
		UImplObj* const ImplObj = Cast<UImplObj>(InterfacePtr);
		UE_LOG(PCLog, Display, TEXT("Cast<UImplObj>(InterfacePtr) returned \"%s\""), ImplObj ? TEXT("VALID") : TEXT("nullptr"));
	}	

	UE_LOG(PCLog, Display, TEXT("AMyPC::Test_Casts DONE"));
}

void AMyPC::Test_UInterface()
{
	UE_LOG(PCLog, Display, TEXT("AMyPC::Test_UInterface..."));
	UE_LOG(PCLog, Display, TEXT("AMyPC::Test_UInterface DONE"));
}
