// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase_CXX.generated.h"

class UStaticMeshComponent;
class UShapeComponent;
class USceneComponent;
class AMyCharacter_CXX;

UCLASS()
class AVENTURAGRAFICA_API AItemBase_CXX : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AItemBase_CXX(const FObjectInitializer& Init);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent)
	void On_Use(AMyCharacter_CXX* character);

	virtual void On_Use_Implementation(AMyCharacter_CXX* character) {};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Scene_Component;

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UShapeComponent* Collision_Component;


};
