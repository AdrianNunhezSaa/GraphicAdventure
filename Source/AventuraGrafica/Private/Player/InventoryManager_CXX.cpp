// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/InventoryManager_CXX.h"
#include "Items/ItemInventory_CXX.h"

#include "Engine/World.h"
#include "AudioDevice.h"


UInventoryManager_CXX::UInventoryManager_CXX() {

	elements.Reserve(maxElements);
}

//Add item to inventory
bool UInventoryManager_CXX::AddElement(TSubclassOf<AItemInventory_CXX> item) {

	//Inventory full
	if (elements.Num() >= maxElements) {

		//Sound when try to pick an object with inventory full
		FAudioDevice::FCreateComponentParams Params = FAudioDevice::FCreateComponentParams(GetWorld()->GetAudioDevice());
		UAudioComponent* AudioComponent = FAudioDevice::CreateComponent(soundFull, Params);

		if (AudioComponent) {

			AudioComponent->bIsUISound = true;
			AudioComponent->bAutoDestroy = true;
			AudioComponent->Play();
		}
		return false;
	}
	else {

		//Audio and pick object to inventory
		FAudioDevice::FCreateComponentParams Params = FAudioDevice::FCreateComponentParams(GetWorld()->GetAudioDevice());
		UAudioComponent* AudioComponent = FAudioDevice::CreateComponent(soundPick, Params);

		if (AudioComponent) {

			AudioComponent->bIsUISound = true;
			AudioComponent->bAutoDestroy = true;
			AudioComponent->Play();
		}

		elements.Add(item);
		return true;
	}

}

//Remove item from inventory
void UInventoryManager_CXX::RemoveElement(TSubclassOf<AItemInventory_CXX> item) {

	//Audio
	FAudioDevice::FCreateComponentParams Params = FAudioDevice::FCreateComponentParams(GetWorld()->GetAudioDevice());
	UAudioComponent* AudioComponent = FAudioDevice::CreateComponent(soundDiscard, Params);

	if (AudioComponent) {

		AudioComponent->bIsUISound = true;
		AudioComponent->bAutoDestroy = true;
		AudioComponent->Play();
	}

	elements.Remove(item);
}

//Check if the itm is in the inventory
bool UInventoryManager_CXX::HasElement(TSubclassOf<AItemInventory_CXX> item) {

	return elements.Contains(item);
}

//Find the element and return it
TSubclassOf<AItemInventory_CXX>& UInventoryManager_CXX::GetElementAt(int32 index)
{
	return elements[index];
}

//Return the number of elements in the inventory
int32 UInventoryManager_CXX::GetElementCount()
{
	return elements.Num();
}