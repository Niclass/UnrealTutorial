// Fill out your copyright notice in the Description page of Project Settings.

#include "AutomaticDoor.h"
#include "DoorWall.h"


// Sets default values
ADoorWall::ADoorWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wall"));
	WallMesh->AttachTo(RootComponent);
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	DoorMesh->AttachTo(RootComponent);
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->AttachTo(RootComponent);
	Trigger->SetRelativeScale3D(FVector(10, 10, 10));

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ADoorWall::OnBeginOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &ADoorWall::OnEndOverlap);


	

}

// Called when the game starts or when spawned
void ADoorWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorWall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ADoorWall::OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent*
	OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &
	SweepResult)
{
	DoorMesh->SetRelativeRotation(FRotator(0, 0, 0));
	if (GetWorldTimerManager().IsTimerActive(DoorCloseTimerHandle))
	{
		GetWorldTimerManager().ClearTimer(DoorCloseTimerHandle);
	}
}

void ADoorWall::OnEndOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	GetWorldTimerManager().SetTimer(DoorCloseTimerHandle, this,
		&ADoorWall::CloseDoor, 3.0f, false);
}
void ADoorWall::CloseDoor(){
	DoorMesh->SetRelativeRotation(FRotator(0, 90, 0));
}


void ADoorWall::OpenDoor()
{
	DoorMesh->SetRelativeRotation(FRotator(0, 0, 0));
	if (GetWorldTimerManager().IsTimerActive(DoorCloseTimerHandle))
	{
		GetWorldTimerManager().ClearTimer(DoorCloseTimerHandle);
	}
}