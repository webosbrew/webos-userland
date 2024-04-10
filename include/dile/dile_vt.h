/******************************************************************************
 *   LCD TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2011 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file dile_vt.h
 *
 *  DILE VT (VT:Video Texture)
 *
 *  @author     JinHyuk Hong (jinhyuk.hong\@lge.com)
 *  @version    1.0
 *  @date       	2013.11.29
 *  @note
 *  @see
 */


#ifndef _DILE_VT_H_
#define _DILE_VT_H_

/*---------------------------------------------------------
    #include ÆÄÀÏµé
    (File Inclusions)
---------------------------------------------------------*/


/*----------------------------------------------------------------------------------------
	Extern Function Prototype Declaration
----------------------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef void* DILE_VT_HANDLE_T;

/**
 * @brief This enumeration describes the supported number of plane corresponding to plane type of video frame buffer.
 */
typedef enum
{
	DILE_VT_VIDEO_FRAME_BUFFER_PLANE_INTERLEAVED = 1,
	DILE_VT_VIDEO_FRAME_BUFFER_PLANE_SEMI_PLANAR,
	DILE_VT_VIDEO_FRAME_BUFFER_PLANE_PLANAR
} DILE_VT_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T;

/**
 * @brief This enumeration describes the supported pixel format of video frame buffer.
 */
typedef enum
{
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_PLANAR = 0,
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_SEMI_PLANAR,
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_INTERLEAVED,
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_PLANAR,
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_SEMI_PLANAR,
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_INTERLEAVED,
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_PLANAR,
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_SEMI_PLANAR,
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_INTERLEAVED,
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_RGB,
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_ARGB
} DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T;

/**
 * @brief This enumeration describes the supported video window.
 */
typedef enum
{
	DILE_VT_VIDEO_INVALID_WINDOW	= -1,
	DILE_VT_VIDEO_WINDOW_0 			= 0,
	DILE_VT_VIDEO_WINDOW_1			= 1,
	DILE_VT_VIDEO_WINDOW_2			= 2
} DILE_VT_VIDEO_WINDOW_TYPE_T;

/**
 * @brief This enumeration describes flags for state of video frame output device setting.
 */
typedef enum
{
	DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_NOFX				= 0x00000000,
	DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_ENABLED				= 0x00000001,
	DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FREEZED				= 0x00000002,
	DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_APPLIED_PQ			= 0x00000004,
	DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FRAMERATE_DIVIDE	= 0x00000010
} DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T;

/**
 * @brief This enumeration describes the event type about notified information of video texture.
 */
typedef enum
{
	DILE_VT_VIDEO_FRAME_BUFFER_AVAILABLE		= 0,
	DILE_VT_VIDEO_FRAME_BUFFER_UNAVAILABLE		= 1,
	DILE_VT_DIMENSION_CHANGED					= 2
} DILE_VT_EVENT_TYPE_T;

/**
 * @brief This enumeration describes the flags controlling mirror mode.
 */
typedef enum
{
	DILE_VT_NONE_MIRROR			= 0x00000000,
	DILE_VT_HORIZONTAL_MIRROR	= 0x00000001,
	DILE_VT_VERTICAL_MIRROR		= 0x00000010,
	DILE_VT_EPI_MIRROR			= 0x00000020,
	DILE_VT_ALL					= 0x00000031
} DILE_VT_MIRROR_FLAGS_T;

/**
 * @brief This enumeration describes display type.
 */
typedef enum
{
	DILE_VT_PLASMA_DISPLAY		= 0,
	DILE_VT_LCD_DISPLAY,
	DILE_VT_OLED_DISPLAY
} DILE_VT_DISPLAY_TYPE_T;

/**
 * @brief This enumeration describes the dump location of video memory.
 */
typedef enum
{
	DILE_VT_SCALER_OUTPUT = 0,
	DILE_VT_DISPLAY_OUTPUT
} DILE_VT_DUMP_LOCATION_TYPE_T;

/**
 * @brief This enumeration describes the type of video.
 */
typedef enum
{
	DILE_VT_VIDEO_INTERLACED	= 0,
	DILE_VT_VIDEO_PROGRESSIVE
} DILE_VT_VIDEO_TYPE_T;

/**
 * @brief This structure describes a rectangle specified by a point and a dimension.
 */
typedef struct
{
	unsigned short x;
	unsigned short y;
	unsigned short w;
	unsigned short h;
} DILE_VT_RECT_T;

/**
 * @brief This structure describes the information of display panel.
 */
typedef struct {
	DILE_VT_DISPLAY_TYPE_T		displayType;
	unsigned int				width;
	unsigned int				height;
} DILE_VT_DISPLAY_INFO_T;

/**
 * @brief This structure describes the information of graphic resolution.
 */
typedef struct {
	unsigned int	width;
	unsigned int	height;
} DILE_VT_GRAPHIC_INFO_T;

/**
 * @brief This structure describes the information of dependent to board.
 */
typedef struct {
	DILE_VT_DISPLAY_INFO_T	displayInfo;
	DILE_VT_GRAPHIC_INFO_T	graphicInfo;
	DILE_VT_MIRROR_FLAGS_T	mirrorModeFlags;
} DILE_VT_BOARD_INFO_T;


/**
 * @brief This structure describes the capability of video device.
 */
typedef struct
{
	unsigned int	numOfVideoWindow;
} DILE_VT_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame buffer.
 */
typedef struct {
	unsigned int								numOfVideoFrameBuffer;
	DILE_VT_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T	numOfPlane;
} DILE_VT_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame output device.
 */
typedef struct
{
	unsigned char	bSupportedControlEnabled;
	unsigned char	bSupportedControlFreezed;
	unsigned char	bSupportedControlFramerateDivide;
	unsigned char	bSupportedControlPQ;
} DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the limitation of video frame output device.
 */
typedef struct {
	DILE_VT_RECT_T 	maxResolution;
	unsigned char	bLeftTopAlign;
	unsigned char	bSupportInputVideoDeInterlacing;
	unsigned char	bSupportDisplayVideoDeInterlacing;
	unsigned char	bSupportScaleUp;
	unsigned int	scaleUpLimitWidth;
	unsigned int	scaleUpLimitHeight;
	unsigned char	bSupportScaleDown;
	unsigned int	scaleDownLimitWidth;
	unsigned int	scaleDownLimitHeight;
} DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T;

/**
 * @brief This structure describes the constant property of video frame buffer.
 * These member values are unique properties of video frame buffer. it is not able to be changed.
 */
typedef struct
{
	DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned int	stride;
	unsigned int	width;
	unsigned int	height;
	unsigned int**	ppPhysicalAddress;
} DILE_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T;

/**
 * @brief This structure describes state information of video frame output device.
 */
typedef struct
{
	unsigned char	bEnabled;
	unsigned char	bFreezed;
	unsigned char	bAppliedPQ;
	unsigned int	framerateDivide;
} DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T;

/**
 * @brief This structure describes information of input video.
 */
typedef struct {
	DILE_VT_VIDEO_TYPE_T		type;
	DILE_VT_RECT_T				region;
	unsigned char				bIs3DVideo;
} DILE_VT_INPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes information of output video.
 */
typedef struct {
	DILE_VT_VIDEO_TYPE_T		type;
	DILE_VT_RECT_T				maxRegion;
	DILE_VT_RECT_T				activeRegion;
} DILE_VT_OUTPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes output information of video frame output device.
 */
typedef struct {
	unsigned int	stride;
	DILE_VT_RECT_T	maxRegion;
	DILE_VT_RECT_T	activeRegion;
} DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T;

/**
 * @brief This structure describes property information of video frame output device.
 */
typedef struct
{
	DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T stateInfo;
	unsigned int framerate;
	DILE_VT_DUMP_LOCATION_TYPE_T dumpLocation;
	DILE_VT_RECT_T outputRegion;
	unsigned char bBlockState;
} DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T;

/**
 * The type of event handler.
 */
typedef void (*DILE_VT_EVENT_HANDLER_T)(DILE_VT_HANDLE_T handle, DILE_VT_EVENT_TYPE_T eventType, void *eventData, void *userData);

#ifndef DILE_STATUS_T

typedef enum{
	DILE_OK = 0,
	DILE_NOT_OK = -1,
} _DILE_STATUS_T;

#define DILE_STATUS_T _DILE_STATUS_T

#endif

/*----------------------------------------------------------------------------------------
    Type Definitions - end
----------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------
    Type Definitions for VTV - start
----------------------------------------------------------------------------------------*/
typedef void* DILE_VTV_HANDLE_T;

typedef struct {
    unsigned int width;
    unsigned int height;
} DILE_VTV_RESOLUTION_T;

typedef struct {
    unsigned char   bSupportInputVideoDeInterlacing;
    unsigned char   bSupportDisplayVideoDeInterlacing;
    unsigned char   bSupportScaleUp;
    unsigned char   bSupportScaleDown;
    unsigned int    scaleUpLimitWidth;
    unsigned int    scaleUpLimitHeight;
    unsigned int    scaleDownLimitWidth;
    unsigned int    scaleDownLimitHeight;
    DILE_VTV_RESOLUTION_T inputBufferMaxResolution;
    DILE_VTV_RESOLUTION_T outputBufferMaxResolution;
    unsigned int    nNumOfInputBuffer;
    unsigned int    nNumOfOutputBuffer;
    unsigned int    nNumOfPlane;
} DILE_VTV_DEVICE_CAPABILITY_INFO_T;

typedef struct
{
    DILE_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
    unsigned int    stride;
    unsigned int    width;
    unsigned int    height;
    unsigned int    yFrame[5];
    unsigned int    uFrame[5];
    unsigned int    vFrame[5];
} DILE_VTV_VFB_PROPERTY_INFO_T;

typedef struct {
    DILE_VTV_VFB_PROPERTY_INFO_T inputBufferInfo;
    DILE_VTV_VFB_PROPERTY_INFO_T outputBufferInfo;
    unsigned int    inputBufferIndex;
    unsigned int    outputBufferIndex;
    unsigned int    vendorData; /**< reserved for chip vendor */
} DILE_VTV_CALLBACK_INFO_T;

typedef void (*DILE_VTV_CALLBACK)(DILE_VTV_CALLBACK_INFO_T *pInfo);

DILE_VTV_HANDLE_T DILE_VTV_Init(void);
DILE_STATUS_T DILE_VTV_Finalize(DILE_VTV_HANDLE_T handle);
DILE_STATUS_T DILE_VTV_GetDeviceCapability(DILE_VTV_HANDLE_T handle, DILE_VTV_DEVICE_CAPABILITY_INFO_T *pCapabilityInfo);
DILE_STATUS_T DILE_VTV_RegisterCallback(DILE_VTV_HANDLE_T handle, DILE_VTV_CALLBACK cbFunc);
DILE_STATUS_T DILE_VTV_GetInputBufferResolution(DILE_VTV_HANDLE_T handle, DILE_VTV_RESOLUTION_T *pResolution);
DILE_STATUS_T DILE_VTV_SetInputBufferResolution(DILE_VTV_HANDLE_T handle, DILE_VTV_RESOLUTION_T *pResolution);
DILE_STATUS_T DILE_VTV_GetOutputBufferResolution(DILE_VTV_HANDLE_T handle, DILE_VTV_RESOLUTION_T *pResolution);
DILE_STATUS_T DILE_VTV_SetOutputBufferResolution(DILE_VTV_HANDLE_T handle, DILE_VTV_RESOLUTION_T *pResolution);
DILE_STATUS_T DILE_VTV_GetOutputBufferIndex(DILE_VTV_HANDLE_T handle, unsigned int *pIndex);
DILE_STATUS_T DILE_VTV_SetOutputBufferIndex(DILE_VTV_HANDLE_T handle, unsigned int index, unsigned int vendorData);
DILE_STATUS_T DILE_VTV_GetInputBufferFreeze(DILE_VTV_HANDLE_T handle, unsigned int bufferIndex, unsigned int *pbFreeze);
DILE_STATUS_T DILE_VTV_SetInputBufferFreeze(DILE_VTV_HANDLE_T handle, unsigned int bufferIndex, unsigned int bFreeze);

/*----------------------------------------------------------------------------------------
    Type Definitions for VTV - end
----------------------------------------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------
    Initialize / Finalize Operation
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Initializes Video module related to.
 *			Call Chipset driver initialization function and create resources for Video module related to VT.
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_Init(void);

/**
 *	@brief	Initializes Video module related to.
 *			Call Chipset driver initialization function and create resources for Video module related to VT according to bufferNum.
 * 	@param	bufferNum 						[IN]		buffer number
 *	@return if success DILE_OK, else DILE_NOT_OK.
 *	@author jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_InitEx(unsigned int bufferNum);

/**
 *	@brief	Finalize Video module related to VT.
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_Finalize(void);

/**
 *	@brief	Set FRC mode. Save the mode in global variable and it is requested to VT driver right before DILE_VT_Init/InitEx.
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	 dain.jeong (dain.jeong@lge.com)
 */
DILE_STATUS_T DILE_VT_EnableFRCMode(unsigned int bEnableFRC);

/*----------------------------------------------------------------------------------------
    Create / Destroy Operation
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Create dile_vt handle after call to HAL_VT APIs in order to initialize Chipset driver.
 * 	@param	videoWindowID 						[IN]		video window ID
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_VT_HANDLE_T DILE_VT_Create(DILE_VT_VIDEO_WINDOW_TYPE_T videoWindowID);


/*----------------------------------------------------------------------------------------
    Create / Destroy Operation
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Create dile_vt handle after call to HAL_VT APIs in order to initialize Chipset driver and create resources for
 *                  Video module related to VT according to bufferNum.
 * 	@param	videoWindowID 						[IN]		video window ID
 * 	@param	bufferNum 						[IN]		buffer number
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jaehak.lee (jaehak.lee@lge.com)
 */
DILE_VT_HANDLE_T DILE_VT_CreateEx(DILE_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned int bufferNum);


/**
 *	@brief	Destroy dile_vt handle after call to HAL_VT APIs in order to finalize Chipset driver.
 * 	@param	handle								[IN]		the handle for DILE_VT
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_Destroy(DILE_VT_HANDLE_T handle);

/*----------------------------------------------------------------------------------------
    Provide capability of Device & Video Frame Buffer
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Gets the capability of VIDEO Device.
 * 	@param	handle						[IN]		the handle for DILE_VT
 * 	@param	pDeviceCapabilityInfo			[OUT]	the capability of video device
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetDeviceCapability(DILE_VT_HANDLE_T handle, DILE_VT_DEVICE_CAPABILITY_INFO_T *pDeviceCapabilityInfo);

/**
 *	@brief	Gets the capability of Video Frame Buffer.
 * 	@param	handle							[IN]		the handle for DILE_VT
 * 	@param	pVideoFrameBufferCapabilityInfo		[OUT]	the capability of video device
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoFrameBufferCapability(DILE_VT_HANDLE_T handle, DILE_VT_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T *pVideoFrameBufferCapabilityInfo);

/**
 *	@brief	Gets the capability of Video Frame Output Device.
 * 	@param	handle								[IN]		the handle for DILE_VT
 * 	@param	pVideoFrameOutputDeviceCapabilityInfo	[OUT]	the capability of VFOD
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoFrameOutputDeviceCapability(DILE_VT_HANDLE_T handle, DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T *pVideoFrameOutputDeviceCapabilityInfo);

/**
 *	@brief	Gets the limitation of Video Frame Output Device.
 * 	@param	handle								[IN]		the handle for DILE_VT
 * 	@param	pVideoFrameOutputDeviceLimitationInfo	[OUT]	the limitation of video frame output device
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoFrameOutputDeviceLimitation(DILE_VT_HANDLE_T handle, DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T *pVideoFrameOutputDeviceLimitationInfo);
/*----------------------------------------------------------------------------------------
    Register event handler
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Register a event handler that handle for change of video states.
 *			(whether video frame buffer is available or unavailable, etc)
 * 	@param	handle						[OUT]	the handle for DILE_VT
 * 	@param	eventHandler					[OUT]	callback function
 * 	@param	pUserData					[OUT]	user data
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_SetEventHandler(DILE_VT_HANDLE_T handle, DILE_VT_EVENT_HANDLER_T eventHandler, void *pUserData);

/*----------------------------------------------------------------------------------------
    Provide information of video frame buffer
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Get properties of video frame buffer corresponding to videoWindowID.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	pVideoFrameBufferCapability				[IN]		the capability of video frame buffer
 *	@param	pVideoFrameBufferProperty				[OUT]	property information of video frame buffer
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetAllVideoFrameBufferProperty(DILE_VT_HANDLE_T handle, DILE_VT_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T *pVideoFrameBufferCapability, DILE_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T *pVideoFrameBufferProperty);

/**
 *	@brief	Get properties of current video frame buffer corresponding to handle.
 *			Current video frame buffer means as followings.
 *			The current video frame buffer corresponding to pIndexOfCurrentVideoFrameBuffer is same with video frame buffer that last write operation is completed.
 *			This buffer may be 1~2 frame delayed buffer compared to video frame being displayed on the screen.
 *			If your chip can only support single video frame buffer, the value is always 0.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	pVideoFrameBufferProperty				[OUT]	property information of video frame buffer
 *	@param	pIndexOfCurrentVideoFrameBuffer		[OUT]	index of current video frame buffer
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetCurrentVideoFrameBufferProperty(DILE_VT_HANDLE_T handle, DILE_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T *pVideoFrameBufferProperty, unsigned int *pIndexOfCurrentVideoFrameBuffer);

/**
 *	@brief	Get secure video state of video frame buffer corresponding to handle.
 *			Vdec driver can know SVP state of own.
			And VT driver can know which vdec is mapped to videoWindowID.
			Therefore, If VT driver can get vdec's SVP state, VT driver can provide the SVP state information to VT client through this interface.
 *	@param	videoWindowID					[IN]		video window ID
 *	@param	pIsSecureVideo					[OUT]	state of secure video corresponding to videoWIndowID
 *	@return if success DILE_OK, else DILE_NOT_OK.
 *	@author jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoFrameBufferSecureVideoState(DILE_VT_HANDLE_T handle, unsigned char *pIsSecureVideo);
/*----------------------------------------------------------------------------------------
    Provide control interface and information of Video Frame Output Device
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Get state information of video frame output device corresponding to videoWindowID.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	pVideoFrameOutputDeviceState			[OUT]	state info of video frame output device
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoFrameOutputDeviceState(DILE_VT_HANDLE_T handle, DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T *pVideoFrameOutputDeviceState);

/**
 *	@brief	Set state of video frame corresponding to videoInputID.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	videoFrameOutputDeviceStateFlags		[IN]		flags to state of video frame output device
 *	@param	pVideoFrameOutputDeviceState			[IN]		state info of video frame output device
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_SetVideoFrameOutputDeviceState(DILE_VT_HANDLE_T handle, DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T videoFrameOutputDeviceStateFlags, DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T *pVideoFrameOutputDeviceState);

/**
 *	@brief	Get framerate of video frame output device corresponding to videoWindowID.
 *	@param	handle				[IN]		the handle for DILE_VT
 *	@param	pFramerate			[OUT]	framerate of VFOD
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoFrameOutputDeviceFramerate(DILE_VT_HANDLE_T handle, unsigned int *pFramerate);

/**
 *	@brief	Get dump location of VFOD corresponding to handle.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	pDumpLocation						[OUT]	dump location of VFOD
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoFrameOutputDeviceDumpLocation(DILE_VT_HANDLE_T handle, DILE_VT_DUMP_LOCATION_TYPE_T *pDumpLocation);

/**
 *	@brief	Set dump location of VFOD corresponding to handle.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	pDumpLocation						[IN]		dump location of VFOD
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_SetVideoFrameOutputDeviceDumpLocation(DILE_VT_HANDLE_T handle, DILE_VT_DUMP_LOCATION_TYPE_T dumpLocation);

/**
 *	@brief	Get output information of VFOD corresponding to handle.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	dumpLocation							[IN]		dump location of VFOD
 *	@param	pOutputInfo							[OUT]	output information of VFOD
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoFrameOutputDeviceOutputInfo(DILE_VT_HANDLE_T handle, DILE_VT_DUMP_LOCATION_TYPE_T dumpLocation, DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T *pOutputInfo);

/**
 *	@brief	Set output region information of VFOD corresponding to handle.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	dumpLocation							[IN]		dump location of VFOD
 *	@param	pOutputRegion						[IN]		output region of VFOD
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_SetVideoFrameOutputDeviceOutputRegion(DILE_VT_HANDLE_T handle, DILE_VT_DUMP_LOCATION_TYPE_T dumpLocation, DILE_VT_RECT_T *pOutputRegion);

/**
 *	@brief	Get block state of video frame output device corresponding to handle.
 *	@param	videoWindowID					[IN]		video window ID
 *	@param	pbBlockState						[OUT]	block state of VFOD corresponding to handle
 *	@return if success DILE_OK, else DILE_NOT_OK.
 *	@author jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoFrameOutputDeviceBlockState(DILE_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned char *pbBlockState);

/**
 *	@brief	Set block state of video frame output device corresponding to handle.
 *	@param	videoWindowID					[IN]		video window ID
 *	@param	bBlockState 						[IN]		block state
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_SetVideoFrameOutputDeviceBlockState(DILE_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned char bBlockState);

/**
 *	@brief	Get property information of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID					[IN]		video window ID
 *	@param	pVideoFrameOutputDeviceProperty 	[OUT]	property information of VFOD corresponding to videoWindowID
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoFrameOutputDeviceProperty(DILE_VT_VIDEO_WINDOW_TYPE_T videoWindowID, DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T *pVideoFrameOutputDeviceProperty);

/**
 *	@brief	Set property information of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID					[IN]		video window ID
 *	@param	pVideoFrameOutputDeviceProperty 	[IN]		property information of VFOD corresponding to videoWindowID
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author 	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_SetVideoFrameOutputDeviceProperty(DILE_VT_VIDEO_WINDOW_TYPE_T videoWindowID, DILE_VT_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T *pVideoFrameOutputDeviceProperty);

/*----------------------------------------------------------------------------------------
    Getting board information
----------------------------------------------------------------------------------------*/

/**
 *	@brief	Getting informations related to H/W (display panel resolution, graphic resolution, mirror mode, etc)
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	pBoardInfo							[OUT]	board information
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetBoardInfo(DILE_VT_HANDLE_T handle, DILE_VT_BOARD_INFO_T *pBoardInfo);

/*----------------------------------------------------------------------------------------
	Provide VFOD vsync state
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Wait for to be completed what the video frame buffer is being written new data by VFOD corresponding to handle.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@return 	if success DILE_OK, else DILE_NOT_OK.
 *	@author 	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_WaitVsync(DILE_VT_HANDLE_T handle);

/*----------------------------------------------------------------------------------------
    Additional Features
----------------------------------------------------------------------------------------*/

/**
 *	@brief	Get input video information corresponding to handle.  (input video original region is resolution of input video.)
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	pInputVideoInfo						[OUT]	input video information
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetInputVideoInfo(DILE_VT_HANDLE_T handle, DILE_VT_INPUT_VIDEO_INFO_T *pInputVideoInfo);

/**
 *	@brief	Get output video information corresponding to handle.
 *			Output video resolution may change when aspect ratio information is changed.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	pOutputVideoInfo						[OUT]	output video information
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetOutputVideoInfo(DILE_VT_HANDLE_T handle, DILE_VT_OUTPUT_VIDEO_INFO_T *pOutputVideoInfo);

/**
 *	@brief	Get video mute status of video path corresponding to handle.
 *	@param	handle								[IN]		the handle for DILE_VT
 *	@param	pbOnOff								[OUT]	video mute status (Mute On : 1, Mute Off : 0)
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_GetVideoMuteStatus(DILE_VT_HANDLE_T handle, unsigned char *pbOnOff);

/**
 *	@brief	Before getting video memory from HAL_VT, This API must be called to assure multi process safety.
 *			The maximum waiting time(ms) for obtaining the vt resources.
 *			If you don't set this value, dile_vt will use internal waitTime according to internal policy.
 *	@param	pWaitTime							[IN]		wait time (milisecond or NULL)
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_Start(unsigned int *pWaitTime);

/**
 *	@brief	After getting video memory from HAL_VT, This API must be called to assure multi process safety.
 *	@return	if success DILE_OK, else DILE_NOT_OK.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DILE_STATUS_T DILE_VT_Stop(void);

/*----------------------------------------------------------------------------------------
    Debug Menu
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Debug menu to verify DILE VT module.
 *	@param	void
 *	@return	void
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
void DILE_VT_Debug(void);

#ifdef __cplusplus
}
#endif
#endif
