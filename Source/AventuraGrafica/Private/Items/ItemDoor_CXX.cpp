#include "Items/ItemDoor_CXX.h"
#include "Player/MyCharacter_CXX.h"
#include "Player/InventoryManager_CXX.h"
#include "AventuraGrafica/Globals.h"

#include "Curves/CurveFloat.h"

void AItemDoor_CXX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//"Curve_Timeline" to open/close the door. MaxKeyValue = 90, created in editor ->CurveDoor
	if (bIsOpening) {

		timeValue += DeltaTime;

		//Ternary to change positive and negative values to add and substract the values of the curve
		float curveValue = bIsClosing 
			? Curve->FloatCurve.GetLastKey().Time - timeValue
			: timeValue;

		//Check the time with the lastKey
		if (abs(timeValue) >= Curve->FloatCurve.GetLastKey().Time) {

			bIsOpening = false;
			bIsClosing = !bIsClosing;
			return;
		}

		//Rotate
		float rotatorValue = Curve->GetFloatValue(curveValue);
		Scene_Component->SetRelativeRotation(FRotator(0, rotatorValue, 0));
	}
}

void AItemDoor_CXX::On_Use_Implementation(AMyCharacter_CXX* character)
{
	Super::On_Use_Implementation(character);
	
	//If the player doesn't have the key and the door is locked
	if (!bUnlocked && bRequiresKey && !character->GetInventoryManager()->HasElement(RequireKeyClass)) {

		UE_LOG(GraphicAdventure, Error, TEXT("Closed. I need a key or something to open it."));
	}

	//Check if the door need a key to open it, and is closed and the player has the key.
	if (!bUnlocked && bRequiresKey && character->GetInventoryManager()->HasElement(RequireKeyClass)) {

		//Delete the key from the inventory
		if (bRemovesKeyWhenUsed)
			character->GetInventoryManager()->RemoveElement(RequireKeyClass);

		bUnlocked = true;
	}

	//If its unlocked set the timeValue=0 for the Curve (Event Tick)
	if (bUnlocked || !bRequiresKey) {
		bIsOpening = true;
		timeValue = 0;
	}
}