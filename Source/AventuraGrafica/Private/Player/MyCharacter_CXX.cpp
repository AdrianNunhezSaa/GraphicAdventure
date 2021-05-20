#include "Player/MyCharacter_CXX.h"
#include "AventuraGrafica/Globals.h"
#include "AventuraGrafica/AventuraGrafica.h"
#include "Items/ItemBase_CXX.h"
#include "Player/InventoryManager_CXX.h"
#include "Items/ItemInventory_CXX.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "UObject/ConstructorHelpers.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimSequenceBase.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AMyCharacter_CXX::AMyCharacter_CXX() : rotationRate{25}, bInspectionMode{false}, traceDistance{700}
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Camera Rotation Rate
	rotationRate = 25;

	//Create the components
	SpringArm_Component = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera_Component = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	//AttachComponents (Hierarchy)
	SpringArm_Component->SetupAttachment(RootComponent);
	Camera_Component->SetupAttachment(SpringArm_Component);

	//Components Properties
	SpringArm_Component->bUsePawnControlRotation = true;
	bUseControllerRotationYaw = true;

	//Animation
	static ConstructorHelpers::FObjectFinder<UAnimSequenceBase> Anim_Interact(TEXT("/Game/GameContent/Animations/Clips/Interact.Interact"));
	anim_Interaction = Anim_Interact.Object;
}

// Called when the game starts or when spawned
void AMyCharacter_CXX::BeginPlay()
{
	Super::BeginPlay();

	//Initialize the inventory and the first item
	bool bInvClassInitialized = InventoryManagerClass.Get() != nullptr; 
	UE_CLOG(!bInvClassInitialized, GraphicAdventure, Error, TEXT("MyCharacter_CXX initialized without InventoryManager"));

	if (bInvClassInitialized) {
		InventoryManager = NewObject<UInventoryManager_CXX>(this, InventoryManagerClass);
		InventoryManager->AddElement(ZippoInventory);

		AItemInventory_CXX* a = Cast<AItemInventory_CXX>(ZippoInventory->GetDefaultObject());

		UE_LOG(GraphicAdventure, Error, TEXT("%s"), *a->getInfo());
	}
		
}

// Called every frame
void AMyCharacter_CXX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter_CXX::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Action
	PlayerInputComponent->BindAction("Interact", EInputEvent::IE_Pressed, this, &AMyCharacter_CXX::On_Interact);
	PlayerInputComponent->BindAction("InspectionMode", EInputEvent::IE_Pressed, this, &AMyCharacter_CXX::On_InspectionMode);
	PlayerInputComponent->BindAction("Menu", EInputEvent::IE_Pressed, this, &AMyCharacter_CXX::On_Menu);

	//Axis
	PlayerInputComponent->BindAxis("Move_Horizontal", this, &AMyCharacter_CXX::On_MovementHorizontal);
	PlayerInputComponent->BindAxis("Move_Vertical", this, &AMyCharacter_CXX::On_MovementVertical);
	PlayerInputComponent->BindAxis("Rotate_Horizontal", this, &AMyCharacter_CXX::On_RotateHorizontal);
	PlayerInputComponent->BindAxis("Rotate_Vertical", this, &AMyCharacter_CXX::On_RotateVertical);

}

//Called when A,D is used
void AMyCharacter_CXX::On_MovementHorizontal(float axisValue)
{
	if (axisValue != 0.f)
		AddMovementInput(GetActorRightVector(), axisValue, false);
}

//Called when W,S is used
void AMyCharacter_CXX::On_MovementVertical(float axisValue)
{
	if (axisValue != 0.f)
		AddMovementInput(GetActorForwardVector(), axisValue, false);
}

//Called when rotate yaw spring arm
void AMyCharacter_CXX::On_RotateHorizontal(float axisValue)
{
	if (axisValue != 0.f)
		AddControllerYawInput(axisValue * rotationRate * GetWorld()->GetDeltaSeconds());
}

//Called when rotate pitch spring arm
void AMyCharacter_CXX::On_RotateVertical(float axisValue)
{
	if (axisValue != 0.f)
		AddControllerPitchInput(axisValue * rotationRate * GetWorld()->GetDeltaSeconds());
}

//Called when Left Click is used
void AMyCharacter_CXX::On_Interact()
{
	if (APlayerController* PC = Cast<APlayerController>(GetController())) {

		if (bInspectionMode) {

			FHitResult hitResult;
			FCollisionQueryParams traceParams;

			FVector Loc, Dir;
			PC->DeprojectMousePositionToWorld(Loc, Dir);

			FVector startTrace = Loc;
			FVector endTrace = startTrace + (Dir * traceDistance);	

			//Disable the DrawDebug in shipping mode
	/*		#if !UE_BUILD_SHIPPING
						DrawDebugLine(GetWorld(), startTrace, endTrace, FColor::Orange, false, 1.0f, 0, 1.0f);
			#endif*/

			//Line trace
			if (GetWorld()->LineTraceSingleByChannel(hitResult, startTrace, endTrace, Globals::ItemBaseChannel, traceParams)) {

				if (AItemBase_CXX * actorHited = Cast<AItemBase_CXX>(hitResult.GetActor())) {
					//If the actorhited is an ItemInventory, plays animation.
					if(Cast<AItemInventory_CXX>(actorHited)) 
						GetMesh()->GetAnimInstance()->PlaySlotAnimationAsDynamicMontage(anim_Interaction, "DefaultSlot", .25f, .25f);
					
					actorHited->On_Use(this);
				}
				else {
					UE_LOG(GraphicAdventure, Warning, TEXT("There is nothing to find here"));
				}
			}
			else
				UE_LOG(GraphicAdventure, Warning, TEXT("There is nothing to find here"));
		}
	}
}

//Called when Spacebar is used
void AMyCharacter_CXX::On_InspectionMode() {

	//Show mouse and disable movement	
	if (APlayerController * PC = Cast<APlayerController>(GetController())) {
		
		bInspectionMode = !bInspectionMode;

		PC->bShowMouseCursor = !PC->bShowMouseCursor;

		PC->ClientIgnoreLookInput(PC->bShowMouseCursor);
		PC->ClientIgnoreMoveInput(PC->bShowMouseCursor);
	}
	else {
		UE_LOG(GraphicAdventure, Error, TEXT("AMyCharacter::On_InspectionMode cant cast PlayerController"));
	}

}

//Called when Escape is used
void AMyCharacter_CXX::On_Menu() {

}