// Fill out your copyright notice in the Description page of Project Settings.

#include "Triggers/GTGeneratorTrigger.h"

#include <Engine/World.h>
#include <TimerManager.h>

#include "Generators/GTDataGeneratorComponent.h"

// Sets default values for this component's properties
UGTGeneratorTrigger::UGTGeneratorTrigger()
{
}

void UGTGeneratorTrigger::Trigger()
{
    FDateTime TimeStamp = FDateTime::Now();
    for (const FGTGeneratorReference& GeneratorReference : DataGenerators)
    {
        UGTDataGeneratorComponent* GeneratorComponent = GeneratorReference.GetComponent(GetOwner());
        if (GeneratorComponent)
        {
            GeneratorComponent->GenerateData(TimeStamp);
        }
    }
}


// Called when the game starts
void UGTGeneratorTrigger::BeginPlay()
{
    Super::BeginPlay();
}
