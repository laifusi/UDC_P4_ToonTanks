// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();

	// UPROPERTY SPECIFIERS - Exposing Variables
	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 VisibleAnywhereInt = 12;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 EditAnywhereInt = 22;
	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt = 13;
	UPROPERTY(EditInstanceOnly)
	int32 EditInstanceOnlyInt = 23;
	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultsOnlyInt = 14;
	UPROPERTY(EditDefaultsOnly)
	int32 EditDefaultsOnlyInt = 24;*/

protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere)
	UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category="Combat")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category="Combat")
	TSubclassOf<class ULegacyCameraShake> DeathCameraShake;


	// UPROPERTY SPECIFIERS - Exposing private variables
	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "My Variables", meta = (AllowPrivateAccess = "true"))
	int32 VisibleAnywherePrivateInt = 12;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Variables", meta = (AllowPrivateAccess = "true"))
	int32 EditAnywherePrivateInt = 22;*/
};
