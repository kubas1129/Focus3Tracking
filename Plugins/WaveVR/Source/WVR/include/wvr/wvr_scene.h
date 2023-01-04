#ifndef wvr_scene_h_
#define wvr_scene_h_

#include "wvr_stdinc.h"
#include "wvr_types.h"

#include "begin_code.h"
#ifdef __cplusplus
extern "C" {
#endif

/*
 * 1. Start/Stop scene CMP to manage the system resource of the scene perception.
 */
extern WVR_EXPORT WVR_Result WVR_StartScene();

extern WVR_EXPORT void WVR_StopScene();

/*
 * 2. Start the scene perception by calling WVR_StartScenePerception. (STATE: EMPTY -> OBSERVING or PAUSED -> OBSERVING)
 *    Stop the scene perception by calling WVR_StopScenePerception. (STATE: OBSERVING -> PAUSED)
 */

typedef enum WVR_ScenePerceptionTarget {
    WVR_ScenePerceptionTarget_2dPlane = 0,
    WVR_ScenePerceptionTarget_3dObject = 1,
    WVR_ScenePerceptionTarget_VisualMesh = 2,
    WVR_ScenePerceptionTarget_ColliderMesh = 3,
    WVR_ScenePerceptionTarget_Max = 0x7FFFFFFF
} WVR_ScenePerceptionTarget;

// 2-1 WVR_StartScenePerception
extern WVR_EXPORT WVR_Result WVR_StartScenePerception(WVR_ScenePerceptionTarget target);

// 2-2 WVR_StopScenePerception
extern WVR_EXPORT WVR_Result WVR_StopScenePerception(WVR_ScenePerceptionTarget target);

/*
 * 3. Get the perception state by calling WVR_GetScenePerceptionState to check STATE is COMPLETED to know the result is ready.
 */
typedef enum WVR_ScenePerceptionState {
    WVR_ScenePerceptionState_Empty = 0,
    WVR_ScenePerceptionState_Observing = 1,
    WVR_ScenePerceptionState_Paused = 2,
    WVR_ScenePerceptionState_Completed = 3,
    WVR_ScenePerceptionState_Max = 0x7FFFFFFF
} WVR_ScenePerceptionState;

extern WVR_EXPORT WVR_Result WVR_GetScenePerceptionState(
    WVR_ScenePerceptionTarget      target,
    WVR_ScenePerceptionState*      state);

/*
 * 4-1. Get scene planes after perception process is finished
 */
typedef enum WVR_ScenePlaneLabel {
    WVR_ScenePlaneLabel_Unknown = 0,
    WVR_ScenePlaneLabel_Floor = 1,
    WVR_ScenePlaneLabel_Ceiling = 2,
    WVR_ScenePlaneLabel_Wall = 3,
    WVR_ScenePlaneLabel_Desk = 4,
    WVR_ScenePlaneLabel_Couch = 5,
    WVR_ScenePlaneLabel_Door = 6,
    WVR_ScenePlaneLabel_Window = 7,
    WVR_ScenePlaneLabel_Stage = 8,
    WVR_ScenePlaneLabel_Max = 0x7FFFFFFF        // app sets WVR_ScenePlaneLabel_Max meaning no filer.
} WVR_ScenePlaneLabel;

typedef enum WVR_ScenePlaneType {
    WVR_ScenePlaneType_Unknown = 0,
    WVR_ScenePlaneType_HorizontalUpwardFacing = 1,
    WVR_ScenePlaneType_HorizontalDownwardFacing = 2,
    WVR_ScenePlaneType_Vertical = 3,
    WVR_ScenePlaneType_Max = 0x7FFFFFFF         // app sets WVR_ScenePlaneType_Max meaning no filer.
} WVR_ScenePlaneType;

#define WVR_UUID_SIZE   16

typedef struct WVR_Uuid {
    uint8_t     data[WVR_UUID_SIZE];
} WVR_Uuid;

typedef struct WVR_SceneMesh {
    uint64_t    meshBufferId;
} WVR_SceneMesh;

typedef struct WVR_Extent2Df {
    float    width;
    float    height;
} WVR_Extent2Df;

typedef struct WVR_ScenePlane {
    WVR_Uuid                    uuid;
    WVR_Uuid                    parentUuid;
    WVR_SceneMesh               mesh;
    WVR_Pose_t                  pose;
    WVR_Extent2Df               extent;
    WVR_ScenePlaneType          planeType;
    WVR_ScenePlaneLabel         planeLabel;
} WVR_ScenePlane;

typedef struct WVR_ScenePlaneFilter {
    WVR_ScenePlaneType      planeType;
    WVR_ScenePlaneLabel     planeLabel;
} WVR_ScenePlaneFilter;

// Get scene planes using WVR_GetScenePlanes
extern WVR_EXPORT WVR_Result WVR_GetScenePlanes(
    const WVR_ScenePlaneFilter*             planeFilter,        // app sets nullptr if no need filter.
    uint32_t                                planeCapacityInput,
    uint32_t*                               planeCountOutput,
    WVR_ScenePlane*                         planes);

/*
 * 4-3. Get scene meshes after perception process is finished
 */

// Get scene meshes using WVR_GetSceneMeshes
extern WVR_EXPORT WVR_Result WVR_GetSceneMeshes(
    WVR_ScenePerceptionTarget           target,
    uint32_t                            meshCapacityInput,
    uint32_t*                           meshCountOutput,
    WVR_SceneMesh*                      meshes);

/*
 * 5. Get mesh data using WVR_GetSceneMeshBuffer
 */
typedef struct WVR_SceneMeshBuffer {
    uint32_t                    vertexCapacityInput;
    uint32_t*                   vertexCountOutput;
    WVR_Vector3f*               vertexBuffer;
    uint32_t                    indexCapacityInput;
    uint32_t*                   indexCountOutput;
    uint32_t*                   indexBuffer;
} WVR_SceneMeshBuffer;

extern WVR_EXPORT WVR_Result WVR_GetSceneMeshBuffer(
    uint64_t                    meshBufferId,
    WVR_SceneMeshBuffer*        sceneMeshBuffer);

#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* wvr_scene_h_ */