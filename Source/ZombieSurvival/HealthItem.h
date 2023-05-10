#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "RespawnComponent.h"
#include "HealthItem.generated.h"

UCLASS()
class MYPROJECT_API AHealthItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHealthItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
		float RespawnDelay;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		float HealAmount;

private:
	

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere)
		URespawnComponent* RespawnComponent;

	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};