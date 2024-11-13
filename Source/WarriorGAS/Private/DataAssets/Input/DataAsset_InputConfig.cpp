// Atthiyya Agustian All Rights Reserved


#include "DataAssets/Input/DataAsset_InputConfig.h"

TObjectPtr<UInputAction> UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag)  const
{
	for (const FWarriorInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}

	return nullptr;
}
