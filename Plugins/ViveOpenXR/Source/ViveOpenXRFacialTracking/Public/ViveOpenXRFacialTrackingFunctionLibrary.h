// Copyright (c) 2022 HTC Corporation. All Rights Reserved.

#pragma once

#include "Engine/Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ViveFacialExpressionEnums.h"
#include "ViveOpenXRFacialTrackingFunctionLibrary.generated.h"


UENUM(BlueprintType, Category = "ViveOpenXR|OpenXR|FacialTracking")
enum class EXrFacialTrackingType : uint8
{
  None = 0  UMETA(Hidden),
  Eye = 1,
  Lip = 2
};

UCLASS(ClassGroup = OpenXR)
class VIVEOPENXRFACIALTRACKING_API UViveOpenXRFacialTrackingFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Is Facial Tracking Enabled", Keywords = "ViveOpenXR Facial Tracking"), Category = "ViveOpenXR|OpenXR|FacialTracking")
    static void GetIsFacialTrackingEnabled(bool& result);

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create Facial Tracker", Keywords = "ViveOpenXR Facial Tracking"), Category = "ViveOpenXR|OpenXR|FacialTracking")
    static bool CreateFacialTracker(EXrFacialTrackingType trackingType);

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Destroy Facial Tracker", Keywords = "ViveOpenXR Facial Tracking"), Category = "ViveOpenXR|OpenXR|FacialTracking")
    static bool DestroyFacialTracker();

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Eye Facial Expressions", Keywords = "ViveOpenXR Facial Tracking"), Category = "ViveOpenXR|OpenXR|FacialTracking")
    static bool GetEyeFacialExpressions(bool& isActive, TMap<EEyeShape, float>& blendshapes);

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Lip Facial Expressions", Keywords = "ViveOpenXR Facial Tracking"), Category = "ViveOpenXR|OpenXR|FacialTracking")
    static bool GetLipFacialExpressions(bool& isActive, TMap<ELipShape, float>& blendshapes);
};
