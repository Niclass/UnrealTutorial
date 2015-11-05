// Fill out your copyright notice in the Description page of Project Settings.

#include "TheGame.h"
#include "Door.h"


// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	DoorMesh->AttachTo(RootComponent);

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->AttachTo(RootComponent);
	Trigger->SetRelativeScale3D(FVector(10, 10, 10));

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnBeginOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &ADoor::OnEndOverlap);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ADoor::OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent*
	OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &
	SweepResult){
	DoorMesh->SetRelativeRotation(FRotator(0, 90, 0));
	if (GetWorldTimerManager().IsTimerActive(DoorCloseTimerHandle)){
		GetWorldTimerManager().ClearTimer(DoorCloseTimerHandle);
	}
}

void ADoor::OnEndOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex){
	GetWorldTimerManager().SetTimer(DoorCloseTimerHandle, this,
		&ADoor::CloseDoor, 3.0f, false);
}

void ADoor::CloseDoor(){
	DoorMesh->SetRelativeRotation(FRotator(0, 0, 0));
}

void ADoor::OpenDoor()
{
	DoorMesh->SetRelativeRotation(FRotator(0, 90, 0));
	GetWorldTimerManager().SetTimer(DoorCloseTimerHandle, this,
		&ADoor::CloseDoor, 3.0f, false);
}