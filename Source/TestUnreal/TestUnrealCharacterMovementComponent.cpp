#include "TestUnrealCharacterMovementComponent.h"

PRAGMA_DISABLE_OPTIMIZATION
void UTestUnrealCharacterMovementComponent::ServerMove_HandleMoveData(const FCharacterNetworkMoveDataContainer& MoveDataContainer)
{
	Super::ServerMove_HandleMoveData(MoveDataContainer);
	if (LastMoveReceivedFrame == GFrameCounter)
	{
		MovesReceivedSinceLastTick++;
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Emerald, FString::Printf(TEXT("~~ Server handling multiple move datas! #%i on %i"), MovesReceivedSinceLastTick, GFrameCounter));
		UE_LOG(LogTemp, Display, TEXT("~~Server handling multiple move datas! #%i on %i"), MovesReceivedSinceLastTick, GFrameCounter);
	}
	else
	{
		MovesReceivedSinceLastTick = 1;
		if (GFrameCounter - LastMoveReceivedFrame > 1)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Emerald, FString::Printf(TEXT("~~ Server handling move data gap! %i -> %i"), LastMoveReceivedFrame, GFrameCounter));
			UE_LOG(LogTemp, Display, TEXT("~~ Server handling move data gap! %i -> %i"), LastMoveReceivedFrame, GFrameCounter);
		}
		else
		{
			//UE_LOG(LogTemp, Display, TEXT("~~ Server first move data for frame %i"), GFrameCounter);
		}

		LastMoveReceivedFrame = GFrameCounter;
	}
}

void UTestUnrealCharacterMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Display, TEXT("TICK"));
	/*
	UPrimitiveComponent* primitive = GetPawnOwner()->GetComponentByClass(UPrimitiveComponent::GetClass());*/
}
PRAGMA_ENABLE_OPTIMIZATION
