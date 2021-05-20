// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD_CXX.generated.h"

class UTexture2D;

UCLASS()
class AVENTURAGRAFICA_API APlayerHUD_CXX : public AHUD
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* Texture;

	virtual void DrawHUD() override;
};
