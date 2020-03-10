#include "MySaveLoadSystemQuick.h"
#include "IMySaveableHandle.h"

void UMySaveLoadSystemQuick::MyNativeCallTakeScriptInterfaceReference_Implementation(const TScriptInterface<IMySaveableHandle>& InSaveable)
{
}

TScriptInterface<IMySaveableHandle> UMySaveLoadSystemQuick::MyNativeCallReturnScriptInterface_Implementation()
{
	return nullptr;
	//return TScriptInterface<IMySaveableHandle>(); 
}

//TScriptInterface<IMySaveableHandle> UMySaveLoadSystemQuick::CreateSaveable_Implementation(TScriptInterface<IMySaveable> InSaveable)
//{
//	return TScriptInterface<IMySaveableHandle>();
//}

//void UMySaveLoadSystemQuick::NotifySaveableDestructed_Implementation()
//{
//}