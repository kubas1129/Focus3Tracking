// Copyright (c) 2022 HTC Corporation. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"

DECLARE_LOG_CATEGORY_EXTERN(LogViveOpenXRSettings, Log, All);

#include "ViveOpenXRRuntimeSettings.generated.h"


UCLASS(config = Engine, defaultconfig)
class VIVEOPENXRRUNTIMESETTINGS_API UViveOpenXRRuntimeSettings : public UObject
{
public:
  GENERATED_BODY()

    UPROPERTY(GlobalConfig, EditAnywhere, Category = "Controller", Meta = (ConfigRestartRequired = true, DisplayName = "Enable Cosmos Controller", 
        Tooltip = "The OpenXR extension XR_HTC_vive_cosmos_controller_interaction enables the use of HTC Vive Cosmos Controllers interaction profiles in OpenXR. \nNOTE: You need to restart the engine to apply new settings after clicking \"Enable Cosmos Controller\"."))
        bool bEnableCosmosController = true;

    UPROPERTY(GlobalConfig, EditAnywhere, Category = "Controller", Meta = (ConfigRestartRequired = true, DisplayName = "Enable Focus3 Controller", 
        Tooltip = "The OpenXR extension XR_HTC_vive_focus3_controller_interaction enables the use of HTC Vive Focus3 Controllers interaction profiles in OpenXR. \nNOTE: You need to restart the engine to apply new settings after clicking \"Enable Focus3 Controller\""))
        bool bEnableFocus3Controller = false;

    UPROPERTY(GlobalConfig, EditAnywhere, Category = "Facial Tracking", Meta = (ConfigRestartRequired = true, DisplayName = "Enable Facial Tracking", 
        Tooltip = "To help software developers create an application with actual facial expressions on 3D avatars with the OpenXR facial tracing extension XR_HTC_facial_trackin. \nNOTE: You need to restart the engine to apply new settings after clicking \"Enable Facial Tracking\"."))
        bool bEnableFacialTracking = false;
    
    UPROPERTY(GlobalConfig, EditAnywhere, Category = "Scene Understanding", Meta = (ConfigRestartRequired = true, DisplayName = "Enable Scene Understanding", 
        Tooltip = "Demonstrate configuring, calculating and generating mesh of surrouding environments by the OpenXR scene understanding extension XR_MSFT_scene_understanding. \nNOTE: You need to restart the engine to apply new settings after clicking \"Enable Scene Understanding\"."))
        bool bEnableSceneUnderstanding = false;
};
