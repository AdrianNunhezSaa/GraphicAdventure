// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemGarageDoor_CXX.h"
#include "Player/MyCharacter_CXX.h"
#include "Player/InventoryManager_CXX.h"
#include "AventuraGrafica/Globals.h"

void AItemGarageDoor_CXX::On_Use_Implementation(AMyCharacter_CXX* character)
{
	Super::On_Use_Implementation(character);

	//If the player doesn't have the the item
	if (!character->GetInventoryManager()->HasElement(RequireItemClass)) {

		UE_LOG(GraphicAdventure, Error, TEXT("I have to find the remote control to open this damn door and get out of here."));
	}
	else {
		//Delete the item from the inventory
		if (bRemovesItemWhenUsed)
			character->GetInventoryManager()->RemoveElement(RequireItemClass);
	}

}

