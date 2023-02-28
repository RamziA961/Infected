// Fill out your copyright notice in the Description page of Project Settings.

//#pragma once
//
//#include "CoreMinimal.h"
//#include "AIController.h"
//#include "ZombieAgentController.generated.h"
//
//class UBehaviourTreeComponent;
//
///**
// * 
// */
//UCLASS()
//class ZOMBIESURVIVAL_API AZombieAgentController : public AAIController
//{
//	GENERATED_BODY()
//
//
//public:
//	AZombieAgentController();
//
//
//protected:
//	virtual void BeginPlay() override;
//	virtual void BeginPossess(APawn* InPawn) override;
//
//private:
//	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Catergory = "AI", meta = { AllowPrivateAccess = true })
//		TObjectPtr<UBehaviourTree> BehaviorTree;
//
//	UPROPERTY(VisibileAnywhere, BlueprintReadOnly, Catergory = "AI", meta = { AllowPrivateAccess = true })
//		TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;
//
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Catergory = "AI", meta = { AllowPrivateAccess = true })
//		TObjectPtr<UBlackboardComponent> BlackboardComponent;
//	
//};
