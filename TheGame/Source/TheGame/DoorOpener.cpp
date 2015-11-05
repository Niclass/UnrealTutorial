// Fill out your copyright notice in the Description page of Project Settings.

#include "TheGame.h"
#include "DoorOpener.h"


// Sets default values
ADoorOpener::ADoorOpener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));

	Trigger->AttachTo(RootComponent);
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ADoorOpener::OnBeginOverlap);
	
}

// Called when the game starts or when spawned
void ADoorOpener::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorOpener::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void ADoorOpener::OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent*
	OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &
	SweepResult)
{
	if (door)
	door->OpenDoor();
}
