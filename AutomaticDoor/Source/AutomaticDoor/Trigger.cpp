// Fill out your copyright notice in the Description page of Project Settings.

#include "AutomaticDoor.h"
#include "Trigger.h"


// Sets default values
ATrigger::ATrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->AttachTo(RootComponent);

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ATrigger::OnBeginOverlap);

}

// Called when the game starts or when spawned
void ATrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrigger::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATrigger::OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (door)
		door->OpenDoor();
}

