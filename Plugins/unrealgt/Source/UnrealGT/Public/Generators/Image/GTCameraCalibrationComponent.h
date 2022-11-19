// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GTGeneratorReference.h"

#include "GTCameraCalibrationComponent.generated.h"

/**
 * Can bes used to get calibration parameters from image generators.
 * Set CameraOneReference to retrieve data for one camera.
 * Set CameraOneReference and CameraTwoReference to generate stereo calibration parameters.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALGT_API UGTCameraCalibrationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGTCameraCalibrationComponent();

    UPROPERTY(EditAnyWhere, Category = Cameras)
    FGTGeneratorReference CameraOneReference;

    UPROPERTY(EditAnyWhere, Category = Cameras)
    FGTGeneratorReference CameraTwoReference;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
