#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyLoadTexture.generated.h"


UCLASS()
class RENDERPIPLELINE_API UMyLoadTexture : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, category = "zjhAddFuns")
	bool LoadMyColors(TArray<FLinearColor>& outColors, UTexture2D* inMyTexture);
};
