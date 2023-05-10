#include "HealthItem.h"
#include "BaseCharacter.h"
#include "RespawnComponent.h"

AHealthItem::AHealthItem()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetBoxExtent(FVector(25.0f, 25.0f, 25.0f));
	CollisionComponent->SetCollisionProfileName(TEXT("OverlapAll"));
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AHealthItem::OnOverlapBegin);
	RootComponent = CollisionComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);

	RespawnComponent = CreateDefaultSubobject<URespawnComponent>(TEXT("RespawnComponent"));
	RespawnComponent->SetRespawnDelay(RespawnDelay);
	RespawnComponent->SetSpawnActor(this);
}

void AHealthItem::BeginPlay()
{
	Super::BeginPlay();

}

void AHealthItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHealthItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// If the overlapped actor is the player, restore their health and hide the health item
	if (OtherActor->IsA<ABaseCharacter>())
	{
		ABaseCharacter* MyCharacter = Cast<ABaseCharacter>(OtherActor);
		if (MyCharacter)
		{
			MyCharacter->GetHealthComponent()->Heal(HealAmount);
			SetActorHiddenInGame(true);
			CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
			RespawnComponent->StartTimer();
		}
	}
}