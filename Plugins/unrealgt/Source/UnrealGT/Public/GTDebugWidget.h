// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#if WITH_EDITOR

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

class SViewport;
class FSceneViewport;
class FCommonViewportClient;
class UGTDataGeneratorComponent;
class FGTDebugViewportClient;
class STextComboBox;

/**
 *
 */
class UNREALGT_API SGTDebugWidget : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SGTDebugWidget)
    {
    }
    SLATE_END_ARGS()

    /** Slate widget construction */
    void Construct(const FArguments& InArgs);

    TSharedPtr<FSceneViewport> GetViewport() const;

    TSharedPtr<SViewport> GetViewportWidget() const;

    void SetDataGenerator(UGTDataGeneratorComponent* DataGenerator);

    void OnDataGeneratorPathUpdated(TSharedPtr<FString> NewPath, ESelectInfo::Type SelectType);

    virtual void Tick(
        const FGeometry& AllottedGeometry,
        const double InCurrentTime,
        const float InDeltaTime) override;

private:
    /** Level viewport client */
    TSharedPtr<FGTDebugViewportClient> ViewportClient;

    /** Slate viewport for rendering and I/O */
    TSharedPtr<FSceneViewport> Viewport;

    /** Viewport widget*/
    TSharedPtr<SViewport> ViewportWidget;

    TSharedPtr<STextComboBox> GeneratorComboBox;

    TArray<TSharedPtr<FString>> GeneratorComponentPaths;

    void UpdateGeneratorPathList();
};

#endif
