// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase_CXX.h"
#include "AventuraGrafica/Globals.h"

#include "ItemInventory_CXX.generated.h"

UCLASS()
class AVENTURAGRAFICA_API AItemInventory_CXX : public AItemBase_CXX
{
	GENERATED_BODY()
	
public:

	virtual void On_Use_Implementation(AMyCharacter_CXX* character) override;

	FORCEINLINE const FInventoryElement& GetData() const { return Data; };

	UFUNCTION(BlueprintCallable)
	FString getInfo() { return Info; };

private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	FInventoryElement Data;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString Info;
};
