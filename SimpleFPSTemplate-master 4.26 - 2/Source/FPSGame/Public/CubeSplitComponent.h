// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BombActor.h"
#include "FPSCharacter.h"
#include "CubeSplitComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class FPSGAME_API UCubeSplitComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCubeSplitComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void ColorChange();

	bool setup = false;

	AFPSCharacter* m_PlayerChar;

public:	

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* m_MeshComp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> m_SplitCubeTemplate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> m_ProjectileToReact;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void OnComponentDestroyed(bool bDestroyHierarchy) override;

	//https://unrealcpp.com/on-component-hit/
	UFUNCTION()
	virtual void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	

};
