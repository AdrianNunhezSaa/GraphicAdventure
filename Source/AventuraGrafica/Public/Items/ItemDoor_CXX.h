// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase_CXX.h"
#include "Items/ItemInventory_CXX.h"

#include "ItemDoor_CXX.generated.h"

class UCurveFloat;

UCLASS()
class AVENTURAGRAFICA_API AItemDoor_CXX : public AItemBase_CXX
{
	GENERATED_BODY()
	

public:

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Blueprintcallable)
	virtual void On_Use_Implementation(AMyCharacter_CXX* character) override;

private:

	UPROPERTY(EditAnywhere)
	UCurveFloat* Curve;

	UPROPERTY(EditAnywhere)
	bool bRequiresKey = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true", EditCondition = "bRequiresKey"))
	TSubclassOf <AItemInventory_CXX> RequireKeyClass;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bRequiresKey"))
	bool bRemovesKeyWhenUsed;

	float timeValue;
	bool bIsOpening, bIsClosing, bUnlocked;

};
