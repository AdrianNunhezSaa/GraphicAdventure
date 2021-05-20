// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerHUD_CXX.h"
#include "Player/MyCharacter_CXX.h"
#include "Items/ItemInventory_CXX.h"
#include "Player/InventoryManager_CXX.h"
#include "AventuraGrafica/Globals.h"

#include "Engine/Texture2D.h"
#include "Engine/UserInterfaceSettings.h"
#include "GameFramework/PlayerController.h"


void APlayerHUD_CXX::DrawHUD() {

	//Get the character
	AMyCharacter_CXX* Player = Cast<AMyCharacter_CXX>(GetOwningPawn());
	if (!Player) return;

	//Get viewport size and DPI
	int32 sizeX, sizeY;
	GetOwningPlayerController()->GetViewportSize(sizeX, sizeY);
	float dpi = GetDefault<UUserInterfaceSettings>()->GetDPIScaleBasedOnSize(FIntPoint(sizeX, sizeY));

	//Check that the texture is not null and draw the bar for items
	UE_CLOG(!Texture, GraphicAdventure, Error, TEXT("Texture not found"));
	if (Texture)
		DrawTexture(
			Texture,
			sizeX / 2 - (Texture->GetSizeX() * dpi) / 2,
			sizeY - Texture->GetSizeY() * dpi,
			Texture->GetSizeX() * dpi,
			Texture->GetSizeY() * dpi,
			0,
			0,
			1,
			1
		);

	//If have InventoryManager, iterate through the elements and draws them
	if (UInventoryManager_CXX * InvManager = Player->GetInventoryManager()) {

		for (int32 i = 0; i < InvManager->GetElementCount(); ++i) {

			const FInventoryElement data = InvManager->GetElementAt(i).GetDefaultObject()->GetData();

			DrawTexture(
				data.Texture,
				sizeX / 2 - (Texture->GetSizeX() * dpi) / 2 + (i * data.Texture->GetSizeX() * dpi),
				sizeY - Texture->GetSizeY() * dpi,
				data.Texture->GetSizeX() * dpi,
				data.Texture->GetSizeY() * dpi,
				0,
				0,
				1,
				1
			);

		}
	}

}