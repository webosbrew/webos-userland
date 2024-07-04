/**
 * @ingroup lgncopenapi
 * @file lgnc_directvideo.h
 * @brief DirectVideo API for playing video stream
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Video format
 */
enum LGNC_VDEC_FMT_T {
    LGNC_VDEC_FMT_MAX = 10,
    LGNC_VDEC_FMT_H264 = 2
};

/**
 * @brief Video 3D type
 */
enum LGNC_VDEC_3D_TYPE_T {
    /**
     * @brief Side by side
     */
    LGNC_VDEC_3D_TYPE_LR_HALF = 2,
    LGNC_VDEC_3D_TYPE_NONE = 0,
    /**
     * @brief Top and bottom
     */
    LGNC_VDEC_3D_TYPE_TB_HALF = 3,
    LGNC_VDEC_3D_TYPE_2DTO3D = 1,
    LGNC_VDEC_3D_TYPE_MAX = 4
};

typedef enum LGNC_VDEC_3D_TYPE_T LGNC_VDEC_3D_TYPE_T;

typedef struct LGNC_VDEC_DATA_INFO LGNC_VDEC_DATA_INFO_T;

typedef enum LGNC_VDEC_FMT_T LGNC_VDEC_FMT_T;

/**
 * @brief Video information
 */
struct LGNC_VDEC_DATA_INFO {
    /**
     * @brief Video width
     */
    int width;
    /**
     * @brief Video height
     */
    int height;
    /**
     * @brief Video format
     */
    LGNC_VDEC_FMT_T vdecFmt;
    /**
     * @brief 3D type
     */
    LGNC_VDEC_3D_TYPE_T trid_type;
};

typedef struct LGNC_VDEC_DATA_INFO LGNC_VDEC_DATA_INFO_T;

/**
 * @brief Close video playback
 * @return 0 If succeeded
 */
int LGNC_DIRECTVIDEO_Close();

/**
 * @brief Open video playback
 * @param info Video information
 * @return 0 If succeeded
 */
int LGNC_DIRECTVIDEO_Open(const LGNC_VDEC_DATA_INFO_T *info);

/**
 * @brief Play video buffer
 * @param data Video buffer
 * @param size Size of video buffer
 * @return 0 If succeeded
 */
int LGNC_DIRECTVIDEO_Play(const void *data, unsigned int size);

/**
 * @brief Set video display window on the screen
 * @param x X position of the video
 * @param y Y position of the video
 * @param w Width of the video
 * @param h Height of the video
 * @return 0 If succeeded
 */
int _LGNC_DIRECTVIDEO_SetDisplayWindow(int x, int y, int w, int h);

/**
 * @brief Set video display window on the screen
 * @param x X position of the video
 * @param y Y position of the video
 * @param w Width of the video
 * @param h Height of the video
 * @return 0 If succeeded
 * @since webOS 1.4.0
 */
int _LGNC_DIRECTVIDEO_SetCustomDisplayWindow(int x, int y, int w, int h);

#ifdef __cplusplus
}
#endif