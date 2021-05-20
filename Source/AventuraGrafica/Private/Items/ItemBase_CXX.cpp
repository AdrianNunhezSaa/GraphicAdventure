
#include "Items/ItemBase_CXX.h"
#include "AventuraGrafica/Globals.h"

#include "Components/ShapeComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AItemBase_CXX::AItemBase_CXX(const FObjectInitializer& Init)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creating Components
	StaticMesh = Init.CreateDefaultSubobject<UStaticMeshComponent>(this,TEXT("StaticMeshComponent"));
	Collision_Component = Init.CreateDefaultSubobject<UShapeComponent, UBoxComponent>(this, TEXT("CollisionOverrideable"));
	Scene_Component = Init.CreateDefaultSubobject<USceneComponent>(this,TEXT("Scene_Component"));

	//Attach Components
	this->SetRootComponent(Scene_Component);

	StaticMesh->SetupAttachment(Scene_Component);
	Collision_Component->SetupAttachment(StaticMesh);

	//Components Properties
	Collision_Component->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Collision_Component->SetCollisionResponseToChannel(Globals::ItemBaseChannel, ECollisionResponse::ECR_Block);

}

// Called when the game starts or when spawned
void AItemBase_CXX::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase_CXX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

