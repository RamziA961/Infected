
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ABaseCharacter.generated.h"


class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class USoundBase;

UCLASS(config = Game)
class ZOMBIESURVIVAL_API AABaseCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Input Map */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputMappingContext* DefaultMappingContext;

public:
	// Sets default values for this character's properties
	AABaseCharacter();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		USkeletalMeshComponent* Mesh1P;


	/** First person camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* LookAction;

	/** Jump Input Action: IA_JUMP Data asset */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* JumpAction;

	/** Move Input Action: IA_Move Data asset */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* MoveAction;

	/** Bool for AnimBP to switch to another animation set */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
		bool bWeaponEquipped;

	/** Setter to set the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
		void SetWeaponEquiped(bool weaponEquipped);

	/** Getter for the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
		bool GetWeaponEquipped();

	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

protected: 

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
};
