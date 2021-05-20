// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "GameLogic/MyGameMode_CXX.h"
/*
	//Estructura para no tener que estar repitiendo lo de arriba para cada clase. Con una estructura con constructor vamos creando los objetos.
struct Finder {
	ConstructorHelpers::FClassFinder<AMyCharacter> Character;
	ConstructorHelpers::FClassFinder<APlayerController> PlayerController;

	Finder() :
		Character(TEXT("/Game/GameContent/Blueprints/BP_Character_CXX.BP_Character_CXX_C")),
		PlayerController(TEXT("/Game/GameContent/Blueprints/BP_PlayerController_CXX.BP_PlayerController_CXX_C"))
	{
	}
};

Finder f;
//Asignamos las clases por defecto a nuestro Game Mode
DefaultPawnClass = f.Character.Succeeded() ? f.Character.Class : ADefaultPawn::StaticClass(); //En caso de no encontrar nuestro pawn, pone el pawn por defecto de Unreal.
PlayerControllerClass = f.PlayerController.Succeeded() ? f.PlayerController.Class : APlayerController::StaticClass();
*/