// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase_CXX.h"
#include "Items/ItemInventory_CXX.h"

#include "ItemClosetDoor_CXX.generated.h"

/**
 * 
 */
UCLASS()
class AVENTURAGRAFICA_API AItemClosetDoor_CXX : public AItemBase_CXX
{
	GENERATED_BODY()

public:

	UFUNCTION(Blueprintcallable)
	virtual void On_Use_Implementation(AMyCharacter_CXX* character) override;

private:

	UPROPERTY(EditAnywhere)
	bool bRequiresItem = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", EditCondition = "bRequiresItem"))
	TSubclassOf <AItemInventory_CXX> RequireItemClass;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bRequiresItem"))
	bool bRemovesItemWhenUsed;
};
