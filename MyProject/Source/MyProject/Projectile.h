// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class MYPROJECT_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UFUNCTION()
	void OnHit
	(
		UPrimitiveComponent* HitComp, // Projectile
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, // Direction & magnitude of impulse
		const FHitResult& Hit
	);

	UPROPERTY(EditAnywhere)
	float Damage = 25.f;
};
