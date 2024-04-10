/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2013 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file        dile_vdec_direct.h
 *
 *  Device Interface Layer for Direct Vdec
 *
 *  @author        keunbae.choi(keunbae.choi\@lge.com)
 *  @version    1.1
 *  @date        2013.12.14
 *  @note
 *  @see
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef    __DILE_VDEC_DIRECT_H__
#define    __DILE_VDEC_DIRECT_H__

/******************************************************************************
    Control Constants
******************************************************************************/

/******************************************************************************
    File Inclusions
******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
    Constant Definitions
******************************************************************************/

/******************************************************************************
    Macro Definitions
******************************************************************************/

/******************************************************************************
    Type Definitions
******************************************************************************/

#ifndef DILE_STATUS_T

typedef enum{
    DILE_OK = 0,
    DILE_NOT_OK = -1,
} _DILE_STATUS_T;

#define DILE_STATUS_T _DILE_STATUS_T

#endif

/**
 * DILE VDEC DIRECT 3D Type.
 *
 */
typedef enum
{
    DILE_VDEC_DIRECT_3D_TYPE_NONE,    // 2D
    DILE_VDEC_DIRECT_3D_TYPE_SIDEBYSIDE,
    DILE_VDEC_DIRECT_3D_TYPE_TOPANDBOTTOM,

    DILE_VDEC_DIRECT_3D_TYPE_MAX,
} DILE_VDEC_DIRECT_3D_TYPE_T;

/**
 * DILE VDEC DIRECT SCAN Type.
 *
 */
typedef enum
{
    DILE_VDEC_DIRECT_SCAN_TYPE_PROGRESSIVE,
    DILE_VDEC_DIRECT_SCAN_TYPE_INTERLACED,
} DILE_VDEC_DIRECT_SCAN_TYPE_T;

/**
 * DILE VDEC DIRECT Source Information.
 *
 */
typedef struct
{
    int                                width;
    int                                height;
    DILE_VDEC_DIRECT_SCAN_TYPE_T    scanType;
    int                                frameRate;
    int                                pixelX;
    int                                pixelY;
} DILE_VDEC_DIRECT_SRC_INFO_T;

/******************************************************************************
    Function Declaration
******************************************************************************/
/**
 *  Set Display Engine ID
 *
 *    @param    deid        [in]    display engine ID
 *    @return    succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_VDEC_DIRECT_SetDEId(int deid);

/**
 *    Set video resource type
 *
 *    @param    fourcc        [in]    video source type
 *    @param    width        [in]    width
 *    @param    height        [in]    height
 *    @param    trid_type    [in]    3D type
 *    @param    videoIndex    [in]    video Indext
 *    @return    succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_VDEC_DIRECT_Open(unsigned int fourcc, int width, int height, DILE_VDEC_DIRECT_3D_TYPE_T trid_type, int videoIndex);

/**
 *    Video playback
 *
 *    @param    data        [in]    pointer of buffer
 *    @param    size        [in]    buffer size
 *    @return    succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_VDEC_DIRECT_Play(void *data, int size);

/**
 *    Video playback with calling callback function
 *
 *    @param    data        [in]    pointer of buffer
 *    @param    size        [in]    buffer size
 *  @param  buffID      [in]    buffer identification for callback function
 *    @return    succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_VDEC_DIRECT_PlayWithCallback(void *data, int size, unsigned long long buffID);

/**
 *    Set callback function
 *
 *  @param  callback    [in]    the name of callback function
 *    @return    succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_VDEC_DIRECT_SetCallback(void(*callback)(unsigned long long buffID));

/**
 *    Stop video playback
 *
 *    @return    succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_VDEC_DIRECT_Stop(void);

/**
 *    Release video resource
 *
 *    @return    succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_VDEC_DIRECT_Close(void);

/**
 *    Get Video Source Information
 *
 *    @param    pInfo        [out]    video source information
 *    @return    succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_VDEC_DIRECT_GetVideoInfo(DILE_VDEC_DIRECT_SRC_INFO_T *pInfo);

#ifdef __cplusplus
}
#endif

#endif /* __DILE_VDEC_DIRECT_H__ */
