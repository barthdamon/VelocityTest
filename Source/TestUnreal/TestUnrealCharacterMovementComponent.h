#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "TestUnrealCharacterMovementComponent.generated.h"

/**
 *
 */
UCLASS(Blueprintable, BlueprintType)
class UTestUnrealCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:

	int32 MovesReceivedSinceLastTick;
	int32 LastMoveReceivedFrame;

	virtual void ServerMove_HandleMoveData(const FCharacterNetworkMoveDataContainer& MoveDataContainer) override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
