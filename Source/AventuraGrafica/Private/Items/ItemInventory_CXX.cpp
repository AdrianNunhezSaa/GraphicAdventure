// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/ItemInventory_CXX.h"
#include "Player/MyCharacter_CXX.h"
#include "Player/InventoryManager_CXX.h"
#include "AventuraGrafica/Globals.h"

#include "Engine/World.h"

void AItemInventory_CXX::On_Use_Implementation(AMyCharacter_CXX* character) {

	Super::On_Use_Implementation(character);

	

	//Add the item and destroy it
	if (character->GetInventoryManager()->AddElement(GetClass())) {
		GetWorld()->DestroyActor(this);
		UE_LOG(GraphicAdventure, Error, TEXT("%s"), *Info);
	}
		

}
