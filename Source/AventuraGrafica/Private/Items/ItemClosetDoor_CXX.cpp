#include "Items/ItemClosetDoor_CXX.h"
#include "Player/MyCharacter_CXX.h"
#include "Player/InventoryManager_CXX.h"
#include "AventuraGrafica/Globals.h"

void AItemClosetDoor_CXX::On_Use_Implementation(AMyCharacter_CXX* character)
{
	Super::On_Use_Implementation(character);

	//If the player doesn't have the the item
	if (!character->GetInventoryManager()->HasElement(RequireItemClass)) {

		UE_LOG(GraphicAdventure, Error, TEXT("If I had something heavy, maybe I could break the door."));
	}
	else {
		//Delete the item from the inventory
		if (bRemovesItemWhenUsed)
			character->GetInventoryManager()->RemoveElement(RequireItemClass);
	}

}
