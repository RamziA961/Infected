// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

    MaxHealth = 100;
    Health = MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

    AActor* Owner = GetOwner();

    if (Owner)
    {

    }
}


void UHealthComponent::TakeDamage(float DamageAmount)
{
    Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);

    // Check if health is below zero
    if (Health <= 0)
    {
        // Trigger death event
    }
}

void UHealthComponent::Heal(float HealAmount)
{
    Health += HealAmount;

    // Ensure health does not exceed max health
    Health = FMath::Clamp(Health, 0.0f, MaxHealth);
}

