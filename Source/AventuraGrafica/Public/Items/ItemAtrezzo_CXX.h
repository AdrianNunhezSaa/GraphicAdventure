// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase_CXX.h"
#include "ItemAtrezzo_CXX.generated.h"

class AMyCharacter_CXX;

UCLASS()
class AVENTURAGRAFICA_API AItemAtrezzo_CXX : public AItemBase_CXX
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;

	virtual void On_Use_Implementation(AMyCharacter_CXX* character) override;
};
