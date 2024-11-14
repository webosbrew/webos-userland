/*
 * Copyright (c) 2008-2018 LG Electronics, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0



 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.

 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef NDL_DIRECTMEDIA2_MEDIA_TYPES_H_
#define NDL_DIRECTMEDIA2_MEDIA_TYPES_H_


#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#endif

    /**
     * stream type
     */
    typedef enum {
        NDL_ESP_AUDIO_ES,
        NDL_ESP_VIDEO_ES,
    } NDL_ESP_STREAM_T;

    /**
     * video codec
     */
    typedef enum {
        NDL_ESP_VIDEO_NONE,
        NDL_ESP_VIDEO_CODEC_H262,
        NDL_ESP_VIDEO_CODEC_H264,
        NDL_ESP_VIDEO_CODEC_H265,
        NDL_ESP_VIDEO_CODEC_MPEG,
        NDL_ESP_VIDEO_CODEC_MVC,
        NDL_ESP_VIDEO_CODEC_SVC,
        NDL_ESP_VIDEO_CODEC_VP8,
        NDL_ESP_VIDEO_CODEC_VP9,
        NDL_ESP_VIDEO_CODEC_RM,
        NDL_ESP_VIDEO_CODEC_AVS,
        NDL_ESP_VIDEO_CODEC_MJPEG
    } NDL_ESP_VIDEO_CODEC;

    /**
     * audio codec
     */
    typedef enum {
        NDL_ESP_AUDIO_NONE,
        NDL_ESP_AUDIO_CODEC_MP2,
        NDL_ESP_AUDIO_CODEC_MP3,
        NDL_ESP_AUDIO_CODEC_AC3,
        NDL_ESP_AUDIO_CODEC_EAC3,
        NDL_ESP_AUDIO_CODEC_AAC,
        NDL_ESP_AUDIO_CODEC_HEAAC,
        NDL_ESP_AUDIO_CODEC_PCM_44100_2CH,  // 16bit only
        NDL_ESP_AUDIO_CODEC_PCM_48000_2CH,  // 16bit only
    } NDL_ESP_AUDIO_CODEC;

    /**
     * scan type
     */
    typedef enum {
        SCANTYPE_PROGRESSIVE,
        SCANTYPE_INTERLACED
    } NDL_ESP_SCAN_TYPE;

    /**
     * Ease type
     */
    typedef enum {
        EASE_TYPE_LINEAR,
        EASE_TYPE_INCUNBIC,
        EASE_TYPE_OUTCUBIC
    } NDL_ESP_EASE_TYPE;

    /**
     * 3D type
     */
    typedef enum {
        E3DTYPE_NONE,
        E3DTYPE_CHECKERBOARD,
        E3DTYPE_COLUMN_ALTERNATION,
        E3DTYPE_ROW_ALTERNATION,
        E3DTYPE_SIDE_BY_SIDE,
        E3DTYPE_TOP_BOTTOM,
        E3DTYPE_FRAME_ALTERNATION,
    } NDL_ESP_3D_TYPE;

    /**
     * video info
     */
    typedef enum {
        HDR_TYPE_NONE = 0,
        HDR_TYPE_HDR10,
        HDR_TYPE_DOLBY,
        HDR_TYPE_VP9,
        HDR_TYPE_HLG,
        HDR_TYPE_TOTAL,
    } HDR_TYPE;

    typedef enum {
        VALID_HDR_PQ = 16,
        VALID_HDR_HLG = 18,
    } TRANSFER_CHARACTERISTICS;

    typedef struct {
        uint32_t size;                /* size of the structure in bytes */
        uint32_t width;               /* Video Width */
        uint32_t height;              /* Video Height */
        uint32_t framerateNum;        /* framerate numerator */
        uint32_t framerateDen;        /* framerate denominator */
        uint32_t PARwidth;            /* Width of PAR( Pixel Aspect Ratio) */
        uint32_t PARheight;           /* Height of PAR( Pixel Aspect Ratio) */
        NDL_ESP_SCAN_TYPE SCANTYPE;   /* 0 is progressive, 1 is interaced */
        NDL_ESP_3D_TYPE E3DTYPE;      /* 3D Type */

        bool hasHdrInfo;              /* true : HDR, false : No HDR */
        HDR_TYPE hdrType;           /* HDR Type*/

        /* SEI */
        uint16_t displayPrimariesX[3];/* 0~50000 Only for HEVC V2,
                                         HDR static metadata mastering display information*/
        uint16_t displayPrimariesY[3];/* 0~50000 Only for HEVC V2*/
        uint16_t whitePointX;         /* 0~50000 Only for HEVC V2*/
        uint16_t whitePointY;         /* 0~50000 Only for HEVC V2*/
        uint32_t minDisplayMasteringLuminance;/* Only for HEVC V2 */
        uint32_t maxDisplayMasteringLuminance;/* Only for HEVC V2 */
        uint32_t maxContentLightLevel;
        uint32_t maxPicAverageLightLevel;

        /* VUI */
        uint8_t transferCharacteristics;  /* 10,12,14,16  Only for HEVC V2 (HDR EOTF)*/
        uint8_t colorPrimaries;           /* 0~255 Only for HEVC V2*/
        uint8_t matrixCoeffs;             /* the matrix coefficients used in deriving
                                             luma and chroma signals*/
        bool videoFullRangeFlag;
    } NDL_ESP_VIDEO_INFO_T;

#ifdef __cplusplus
}
#endif

#endif	// NDL_DIRECTMEDIA2_MEDIA_TYPES_H_
