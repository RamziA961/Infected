// Fill out your copyright notice in the Description page of Project Settings.


//#include "AI_Agents/ZombieAgentController.h"
//
//#include "BehaviorTree/BehaviorTree.h"
//#include "BehaviorTree/BehaviorTreeComponent.h"
//#include "BehaviorTree/BlackboardComponent.h"
//
//
//AZombieAgentController::AZombieAgentController()
//{
//	BehviorTreeComponent = CreateDefaultSubObject<UBehaviorTreeComponent>(TEXT("ZombieAgentBehaviorTreeComponent"));
//	BlackboardComponent = CreateDefaultSubObject<UBlackboardComponent>(TEXT("ZombieAgentBlackBoardComponent"));
//	
//}
//
//AZombieAgentController::BeginPlay() 
//{
//	Super::BeginPlay();
//
//	if (IsValid(BehaviorTree.Get()))
//	{
//		RunBehaviorTree(BehaviorTree.Get());
//		BehaviorTreeComponent->StartTree(*BehaviorTree.Get());
//		
//	}
//}
//
//AZombieAgentController::OnPossess(AIPawn* InPawn) 
//{
//	if (IsValid(Blackboard.Get()) && IsValid(BehaviorTree.Get()))
//	{
//		Blackboard->InitializeBlackboard(*BehaviorTree.Get()->BlackboardAsset.Get());
//	}
//}