#include "MyLoadTexture.h"
#include "Engine/Texture2D.h"

bool UMyLoadTexture::LoadMyColors(TArray<FLinearColor>& outColors, UTexture2D* inMyTexture)
{
	if (inMyTexture == nullptr) { return false; }
	const FColor* formatedImageData = (const FColor*)(inMyTexture->GetPlatformData()->Mips[0].BulkData.LockReadOnly());
	if (formatedImageData == nullptr) return false;
	FIntPoint WH = inMyTexture->GetImportedSize();
	for (int32  y = 0; y < WH.Y; y++)
	{
		for (int32 x = 0; x < WH.X; x++)
		{
			FColor pixelColor = formatedImageData[y * WH.X + x];
			//伽马空间颜色变为了线性空间颜色
			FLinearColor linearColor(pixelColor);
			outColors.Add(linearColor);
		}
	}
	return true;
}
