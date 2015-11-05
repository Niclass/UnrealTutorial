// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class THEGAME_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FTimerHandle DoorCloseTimerHandle;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* DoorMesh;

	UPROPERTY(EditAnywhere)
		UBoxComponent* Trigger;

	UFUNCTION()
		void CloseDoor();

	UFUNCTION()
		void OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
		OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		void OnEndOverlap(AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32
		OtherBodyIndex);

	UFUNCTION()
		void OpenDoor();
};
