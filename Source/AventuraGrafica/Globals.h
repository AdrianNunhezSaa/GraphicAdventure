#pragma once

#include "CoreMinimal.h"
#include "Globals.generated.h"

class UTexture2D;

//Custom Log
DECLARE_LOG_CATEGORY_EXTERN(GraphicAdventure, All, All);


//Structure
USTRUCT(BlueprintType)
struct FInventoryElement {

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Texture;
};


namespace Globals {

	extern FName ItemBase_CollisionOverrideable;

	constexpr ECollisionChannel ItemBaseChannel = ECollisionChannel::ECC_GameTraceChannel1; 
}