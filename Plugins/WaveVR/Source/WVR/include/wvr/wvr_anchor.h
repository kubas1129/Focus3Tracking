#ifndef wvr_anchor_h_
#define wvr_anchor_h_

#include "wvr_stdinc.h"
#include "wvr_types.h"

#include "begin_code.h"
#ifdef __cplusplus
extern "C" {
#endif

#define WVR_MAX_SPATIAL_ANCHOR_NAME_SIZE 256
#define WVR_DEFINE_HANDLE(object) typedef uint64_t object;

WVR_DEFINE_HANDLE(WVR_SpatialAnchor)

typedef struct WVR_SpatialAnchorName {
    char    name[WVR_MAX_SPATIAL_ANCHOR_NAME_SIZE];
} WVR_SpatialAnchorName;

typedef struct WVR_SpatialAnchorCreateInfo {
    WVR_Pose_t                  pose;
    WVR_SpatialAnchorName       anchorName;
} WVR_SpatialAnchorCreateInfo;

extern WVR_EXPORT WVR_Result WVR_CreateSpatialAnchor(
    const WVR_SpatialAnchorCreateInfo*      createInfo,
    WVR_SpatialAnchor*                      anchor);

extern WVR_EXPORT WVR_Result WVR_DestroySpatialAnchor(
    WVR_SpatialAnchor           anchor);

extern WVR_EXPORT WVR_Result WVR_EnumerateSpatialAnchors(
    uint32_t                    anchorCapacityInput,
    uint32_t*                   anchorCountOutput,
    WVR_SpatialAnchor*          anchors);

typedef enum WVR_SpatialAnchorTrackingState {
    WVR_SpatialAnchorTrackingState_Tracking,
    WVR_SpatialAnchorTrackingState_Paused,
    WVR_SpatialAnchorTrackingState_Stopped
} WVR_SpatialAnchorTrackingState;

typedef struct WVR_SpatialAnchorState {
    WVR_SpatialAnchorTrackingState      trackingState;
    WVR_Pose_t                          pose;
    WVR_SpatialAnchorName               anchorName;
} WVR_SpatialAnchorState;

extern WVR_EXPORT WVR_Result WVR_GetSpatialAnchorState(
    WVR_SpatialAnchor           anchor,
    WVR_SpatialAnchorState*     anchorState);

#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* wvr_anchor_h_ */
