// "WaveVR SDK
// © 2017 HTC Corporation. All Rights Reserved.
//
// Unless otherwise required by copyright law and practice,
// upon the execution of HTC SDK license agreement,
// HTC grants you access to and use of the WaveVR SDK(s).
// You shall fully comply with all of HTC’s SDK license agreement terms and
// conditions signed by you and all SDK and API requirements,
// specifications, and documentation provided by HTC to You."


#ifndef wvr_ctrller_render_model_h_
#define wvr_ctrller_render_model_h_

#include "wvr_stdinc.h"
#include "wvr_types.h"

#include "begin_code.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Vertex buffer of component in controller model.
 */
typedef struct WVR_VertexBuffer {
    float *buffer;      /**< Vertex buffer. */
    uint32_t size;      /**< Vertex buffer size. */
    uint32_t dimension; /**< 2 is represents the vertex data in this buffer is 2D, 3 means 3D. */
} WVR_VertexBuffer_t;

/**
 * @brief Index buffer of component in controller model.
 */
typedef struct WVR_IndexBuffer {
    uint32_t *buffer; /**< Index buffer. */
    uint32_t size;    /**< Index buffer size. */
    uint32_t type;    /**< Number about how many vertices composing a face. 1 : Point, 2 : Line, 3 : Triangle. */
} WVR_IndexBuffer_t;

/**
 * @brief Controller component information.
 */
typedef struct WVR_CtrlerCompInfo {
    WVR_VertexBuffer_t vertices;  /**< Positions.(Size should be same with normal and tex coord buffers) */
    WVR_VertexBuffer_t normals;   /**< Normals. (Size should be same with vertices and tex coord buffers) */
    WVR_VertexBuffer_t texCoords; /**< Texture coordinates. (Size should be same with vertex and normal buffers) */
    WVR_IndexBuffer_t indices;    /**< Face indices. */
    int32_t texIndex;             /**< Index of the texture in texture table. Default is -1. */
    float localMat[16];           /**< Pose of this component of ctrler model space. */
    char name[64];                /**< Name of this component. */
    bool defaultDraw;             /**< Is this component draw at begin. */
} WVR_CtrlerCompInfo_t;

/**
 * @brief Texture information.
 */
typedef struct WVR_CtrlerTexBitmap { //AndroidBitmap.
    uint8_t *bitmap; /**< Raw data. */
    uint32_t width;  /**< Width of bitmap. */
    uint32_t height; /**< Height of bitmap. */
    uint32_t stride; /**< Bytes per row. */
    int32_t format;  /**< 0 is none, 1 is RGBA_8888, 4 is RGB565, 7 is RGBA_4444. 8 is OnlyAlpha 8bits. (Same with enum AndroidBitmapFormat in NDK)*/
} WVR_CtrlerTexBitmap_t;

/**
 * @brief Information about touchpad plane of controller model.
 */
typedef struct WVR_TouchPadPlane {
    WVR_Vector3f_t u;       /**< U axis of touchpad plane. */
    WVR_Vector3f_t v;       /**< V axis of touchpad plane. */
    WVR_Vector3f_t w;       /**< W axis of touchpad plane. */
    WVR_Vector3f_t center;  /**< Center of touchpad plane in controller model. Unit:(m) */
    float floatingDistance; /**< Distance between touchpad effect and touchpad plane. Unit:(m) */
    float radius;           /**< Radius of touchpad plane. Unit:(m) */
    bool valid;             /**< Is this information simulated or load from config from device service. */
} WVR_TouchPadPlane_t;

/**
 * @brief Information about battery levels of controller model.
 */
typedef struct WVR_BatteryLevelTable {
    WVR_CtrlerTexBitmap_t *texTable; /**< Array that are used to kept textures of each battery level. */
    int32_t *minLvTable;             /**< Lower bounds of each battery level. */
    int32_t *maxLvTable;             /**< Upper bounds of each battery level. */
    uint32_t size;                   /**< Size of battery levels. */
} WVR_BatteryLevelTable_t;

/**
 * @brief Table about all components of controller model.
 */
typedef struct WVR_CtrlerCompInfoTable {
    WVR_CtrlerCompInfo_t *table; /**< Components of this controller model. */
    uint32_t size;               /**< Size of controller model. */
} WVR_CtrlerCompInfoTable_t;

/**
 * @brief Record all textures of controller model.
 */
typedef struct WVR_CtrlerTexBitmapTable {
    WVR_CtrlerTexBitmap_t *table; /**< Textures of this controller model. They usually are appearance of controller model.*/
    uint32_t size;                /**< Size of controller model. */
} WVR_CtrlerTexBitmapTable_t;

/**
 * @brief Structure about all necessary information of controller model.
 */
typedef struct WVR_CtrlerModel {
    WVR_CtrlerCompInfoTable_t compInfos;    /**< Component information */
    WVR_CtrlerTexBitmapTable_t bitmapInfos; /**< Texture information */
    WVR_TouchPadPlane_t touchpadPlane;      /**< Touchpad information */
    WVR_BatteryLevelTable_t batteryLevels;  /**< Battery information */
    char name[256];                         /**< Name of controller model.*/
    bool loadFromAsset;                     /**< Default model from asset or device.*/
} WVR_CtrlerModel_t;

/**
 * @brief Pose structure.
 */
typedef struct WVR_CtrlerModelAnimPoseData {
    WVR_Vector3f_t position; /**< Position information of the node.*/
    WVR_Vector3f_t rotation; /**< Euler angle information of the node.*/
    WVR_Vector3f_t scale; /**< Scale information of the node.*/
} WVR_CtrlerModelAnimPoseData_t;

/**
 * @brief Node animation data structure(Right hand coordinate). Each pose is in controller model space.
 */
typedef struct WVR_CtrlerModelAnimNodeData {
    char name[256]; /**< Name of component.*/
    uint32_t type; /**< Animation type of this node. 0 : 0-1 pressed button. 1 : 1D analog button. 2 : 2D analog thumbstick.*/
    uint32_t blueEffect; /**< Use blue effect of not. 0 : we didn't use blue effect. 1 : we use blue effect.*/
    WVR_CtrlerModelAnimPoseData_t origin; /**< Animation data for default pose.*/
    WVR_CtrlerModelAnimPoseData_t pressed; /**< Animation data for pressed pose.*/
    WVR_CtrlerModelAnimPoseData_t minX; /**< Animation data about left bound. Use only at type 2.*/
    WVR_CtrlerModelAnimPoseData_t maxX; /**< Animation data about right bound. Use only at type 2.*/
    WVR_CtrlerModelAnimPoseData_t minY; /**< Animation data about down bound. Use only at type 2.*/
    WVR_CtrlerModelAnimPoseData_t maxY; /**< Animation data about up bound. Use only at type 2.*/
} WVR_CtrlerModelAnimNodeData_t;

/**
 * @brief Node animation data structure.
 */
typedef struct WVR_CtrlerModelAnimData {
    char name[256]; /**< Name of controller model.*/
    WVR_CtrlerModelAnimNodeData_t *animDatas; /**< Node animation datas of this controller.*/
    uint32_t size;/**< Number of animation datas.*/
} WVR_CtrlerModelAnimData_t;

/**
 * @brief Use this function to get the controller model for the currently connected device. If the controller model does not exist,
 *        it will return the default model in the SDK.
 *
 * Note: It is not recommended to call this function in the render thread or any thread that will block frame update.
 *
 * @param ctrlerType Device type: WVR_DeviceType_Controller_Right or WVR_DeviceType_Controller_Left.(refer to @ref WVR_DeviceType)
 * @param ctrlerModel (Output) A double pointer for receiving the controller model structure.
 *                    The SDK will allocate the data structure for the controller animation and write the address into ctrlModelAnimData.
 * @retval WVR_SUCCESS The controller model was successfully retrieved from the currently connected device.
 * @retval WVR_Error_CtrlerModel_InvalidModel The SDK can’t get the controller model information from the connected controller device or asset.
 * @retval WVR_Error_CtrlerModel_DeviceDisconnected The SDK can’t get the controller model information since the controller you want to get is not connected.
 * @retval WVR_Error_CtrlerModel_Unknown The SDK can’t get the controller model information since the system has not yet been initialized.
 * @retval WVR_Error_InvalidArgument If ctrlerModel is nullptr or pointer in *ctrlerModel isn’t nullptr.
 * @version API Level 5
 */
extern WVR_EXPORT WVR_Result WVR_GetCurrentControllerModel(WVR_DeviceType ctrlerType, WVR_CtrlerModel_t **ctrlerModel, bool isOneBone = true);

/**
 * @brief Use this function to deallocate the memory used for the controller model.
 *
 * Delete the controller received from WVR_GetCurrentControllerModel.
 *
 * @param ctrlerModel An allocated object about controller model. The object will be destroyed and the structure cleared(ctrlerModel will be set nullptr).
 * @version API Level 5
 */
extern WVR_EXPORT void WVR_ReleaseControllerModel(WVR_CtrlerModel_t **ctrlerModel);

/**
 * @brief Use this function is to get emitter information of the current controller model of the currently connected device.
 *
 * The emitter information is determined from the controller model that is currently connected. If the controller model of the
 * connected device does not exist, it will use the default model in the SDK.
 *
 * Note: It is not recommended to call this function in the render thread or any thread that will block frame update.
 *
 * @param ctrlerType Device type: WVR_DeviceType_Controller_Right or WVR_DeviceType_Controller_Left.(refer to @ref WVR_DeviceType)
 * @param emitterPose (Output) An array of 16 elements for getting the emitter pose in the controller space (same order as the OpenGL matrix).
 * @retval WVR_SUCCESS The emitter pose was successfully retrieved from the currently connected device.
 * @retval WVR_Error_CtrlerModel_InvalidModel The SDK can’t get the emitter information from the connected controller device or asset.
 * @retval WVR_Error_CtrlerModel_DeviceDisconnected The SDK can’t get the emitter information since the controller you want to get is not connected.
 * @retval WVR_Error_CtrlerModel_Unknown The SDK can’t get the emitter information since the system has not yet been initialized.
 * @version API Level 5
 */
extern WVR_EXPORT WVR_Result WVR_GetCurrentControllerEmitter(WVR_DeviceType ctrlerType, float emitterPose[16]);

/**
 * @brief Use this function to get the controller animation for the currently connected device. 
 *
 * Note: It is not recommended to call this function after we get controller model.
 *
 * @param ctrlerType Device type: WVR_DeviceType_Controller_Right or WVR_DeviceType_Controller_Left.(refer to @ref WVR_DeviceType)
 * @param ctrlModelAnimData (Output) A double pointer for receiving the controller animation data structure.
 *                           The SDK will allocate the data structure for the animation data and write it into the structure.
 * @retval WVR_SUCCESS The controller animation data was successfully retrieved from the currently connected device.
 * @retval WVR_Error_CtrlerModel_DeviceDisconnected The SDK can’t get the controller animation since the controller you want to get is not connected.
 * @retval WVR_Error_CtrlerModel_Unknown The SDK can’t get the controller animation since the system has not yet been initialized.
 * @retval WVR_Error_InvalidArgument If ctrlModelAnimData is nullptr or pointer in *ctrlModelAnimData isn’t nullptr.
 * @retval WVR_Error_CtrlerModel_NoAnimationData The controller animation data isn't existed.
 * @version API Level 7
 */
extern WVR_EXPORT WVR_Result WVR_GetCtrlerModelAnimNodeData(WVR_DeviceType ctrlerType, WVR_CtrlerModelAnimData_t **ctrlModelAnimData);


/**
 * @brief Use this function to deallocate the memory used for the controller animation.
 *
 * Delete the animation data received from WVR_GetCtrlerModelAnimNodeData.
 *
 * @param ctrlModelAnimData An allocated object about animation data. The object will be destroyed and the structure cleared(ctrlModelAnimData will be set nullptr).
 * @version API Level 7
 */
extern WVR_EXPORT void WVR_ReleaseCtrlerModelAnimNodeData(WVR_CtrlerModelAnimData_t **ctrlModelAnimData);



//----------------- Struct Function --------------

#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* wvr_ctrller_render_model_h_ */
