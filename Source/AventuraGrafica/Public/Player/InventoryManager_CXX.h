// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryManager_CXX.generated.h"

class AItemInventory_CXX;
class USoundBase;

UCLASS(Blueprintable)
class AVENTURAGRAFICA_API UInventoryManager_CXX : public UObject
{
	GENERATED_BODY()
	

public:

	UInventoryManager_CXX();

	UFUNCTION(BlueprintCallable, Category = "GraphicAdventure|InventoryManager")
	bool AddElement(TSubclassOf<AItemInventory_CXX> item);

	UFUNCTION(BlueprintCallable, Category = "GraphicAdventure|InventoryManager")
	void RemoveElement(TSubclassOf<AItemInventory_CXX> item);

	UFUNCTION(BlueprintCallable, Category = "GraphicAdventure|InventoryManager")
	bool HasElement(TSubclassOf<AItemInventory_CXX> item);

	TSubclassOf<AItemInventory_CXX>& GetElementAt(int32 index);
	int32 GetElementCount();

private:

	UPROPERTY(EditDefaultsOnly)
	int32 maxElements;

	UPROPERTY(EditDefaultsOnly)
	USoundBase* soundFull;

	UPROPERTY(EditDefaultsOnly)
	USoundBase* soundPick;

	UPROPERTY(EditDefaultsOnly)
	USoundBase* soundDiscard;


	TArray<TSubclassOf<AItemInventory_CXX>> elements;


};
