// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter_CXX.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInventoryManager_CXX;
class AItemInventory_CXX;
class UAnimSequenceBase;

UCLASS()
class AVENTURAGRAFICA_API AMyCharacter_CXX : public ACharacter
{
	GENERATED_BODY()

public:

	// Sets default values for this character's properties
	AMyCharacter_CXX();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rotationRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bHasPassword = false;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE UInventoryManager_CXX* GetInventoryManager() const { return InventoryManager; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm_Component;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera_Component;

	UPROPERTY()
	UInventoryManager_CXX* InventoryManager;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventoryManager_CXX> InventoryManagerClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AItemInventory_CXX> ZippoInventory;

	bool bInspectionMode;
	float traceDistance;
	UAnimSequenceBase* anim_Interaction;

	UFUNCTION(BlueprintCallable)
	void On_Interact();

	void On_MovementHorizontal(float axisValue);
	void On_MovementVertical(float axisValue);
	void On_RotateHorizontal(float axisValue);
	void On_RotateVertical(float axisValue);
	void On_InspectionMode();
	void On_Menu();

};
