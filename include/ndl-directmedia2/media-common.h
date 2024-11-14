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

#ifndef NDL_DIRECTMEDIA2_MEDIA_COMMON_H_
#define NDL_DIRECTMEDIA2_MEDIA_COMMON_H_

#include "media-types.h"

/**
 * PTS Units
 */
typedef enum {
    NDL_ESP_PTS_TICKS,
    NDL_ESP_PTS_MICROSECS,
} NDL_ESP_PTS_UNITS;

/**
 * The stream buffer format.
 */
typedef struct {
    uint8_t* data;
    uint32_t data_len;  // total data length
    uint32_t offset;    // current offset
    NDL_ESP_STREAM_T stream_type;
    int64_t timestamp;   // PTS in stream
    uint32_t flags; // OMX buffer flag to set END_OF_STREAM. 0x0001 => EOS.
} NDL_ESP_STREAM_BUFFER;

/**
 * The format to configure OMX IL Codecs.
 */
// TODO : will use more specific name..later.
typedef struct {
    /**
     * video codec
     * set to NDL_ESP_VIDEO_NONE, if the stream contains no video data
     */
    NDL_ESP_VIDEO_CODEC video_codec;

    /**
     * audio codec
     * set to NDL_ESP_AUDIO_NONE, if the stream contains no audio data
     */
    NDL_ESP_AUDIO_CODEC audio_codec;

    //TODO : Need to be added...
    //   !Consider OMX IL Component Configuration for MSTAR & SIC.

    // Only use for RPI
    /* config for video */
    uint32_t framerate;
    uint32_t width;
    uint32_t video_encoding;
    uint32_t height;
    void*    extradata;
    uint32_t extrasize;

    /* config for audio */
    uint32_t channels;
    uint32_t samplerate;
    uint32_t blockalign;
    uint32_t bitrate;
    uint32_t bitspersample;
} NDL_ESP_META_DATA;

/**
 * The notification events that the callback function should handle.
 *
 * NDL_ESP_FIRST_FRAME_PRESENTED
 *  will be sent upon rendering of first video frame after flush or at the very beginning of playback
 *  and upon rendering of first video frame after resume from pause
 *  it will be triggered by video decoder only if a stream contains both audio and video
 *  it will be triggered by audio decoder if a stream contains audio only
 *
 * NDL_ESP_LOW_THRESHOLD_CROSSED_VIDEO, NDL_ESP_LOW_THRESHOLD_CROSSED_AUDIO
 *
 */
typedef enum {
    NDL_ESP_FIRST_FRAME_PRESENTED,
    NDL_ESP_LOW_THRESHOLD_CROSSED_VIDEO,
    NDL_ESP_HIGH_THRESHOLD_CROSSED_VIDEO,
    NDL_ESP_STREAM_DRAINED_VIDEO,
    NDL_ESP_LOW_THRESHOLD_CROSSED_AUDIO,
    NDL_ESP_HIGH_THRESHOLD_CROSSED_AUDIO,
    NDL_ESP_STREAM_DRAINED_AUDIO,
    NDL_ESP_END_OF_STREAM,
    NDL_ESP_VIDEO_INFO,   // corresponding data type : NDL_ESP_VIDEO_INFO_T
    NDL_ESP_RESOURCE_RELEASED_BY_POLICY,
    NDL_ESP_VIDEOCONFIG_DECODED,
    NDL_ESP_AUDIOCONFIG_DECODED,
    NDL_ESP_VIDEO_PORT_CHANGED,
    NDL_ESP_AUDIO_PORT_CHANGED,
} NDL_ESP_EVENT;

#define NDL_ESP_FLAG_END_OF_STREAM 1

// TODO : Need to be added more error type.
#define NDL_ESP_RESULT_SUCCESS      0
#define NDL_ESP_RESULT_FAIL         (-1)

/**
 * lwm_omx_esp_feed_data can return following error numbers
 */
#define NDL_ESP_RESULT_FEED_FULL    (-1)
#define NDL_ESP_RESULT_FEED_CODEC_ERROR    (-1001)
#define NDL_ESP_RESULT_FEED_INVALID_INPUT  (-1002)
#define NDL_ESP_RESULT_FEED_INVALID_STATE  (-1003)

/**
 * lwm_omx_esp_load can return following error numbers
 */
#define NDL_ESP_RESULT_VIDEO_UNSUPPORTED     (-2000)
#define NDL_ESP_RESULT_VIDEO_CODEC_ERROR     (-2001)
#define NDL_ESP_RESULT_VIDEO_RENDER_ERROR    (-2002)
#define NDL_ESP_RESULT_VIDEO_TUNNEL_ERROR    (-2003)
#define NDL_ESP_RESULT_VIDEO_BUFFER_ERROR    (-2004)
#define NDL_ESP_RESULT_VIDEO_STATE_ERROR     (-2005)
#define NDL_ESP_RESULT_AUDIO_UNSUPPORTED     (-2100)
#define NDL_ESP_RESULT_AUDIO_CODEC_ERROR     (-2101)
#define NDL_ESP_RESULT_AUDIO_RENDER_ERROR    (-2102)
#define NDL_ESP_RESULT_AUDIO_TUNNEL_ERROR    (-2103)
#define NDL_ESP_RESULT_AUDIO_BUFFER_ERROR    (-2104)
#define NDL_ESP_RESULT_AUDIO_STATE_ERROR     (-2105)
#define NDL_ESP_RESULT_CLOCK_ERROR           (-2200)
#define NDL_ESP_RESULT_CLOCK_TUNNEL_ERROR    (-2203)
#define NDL_ESP_RESULT_CLOCK_BUFFER_ERROR    (-2204)
#define NDL_ESP_RESULT_CLOCK_STATE_ERROR     (-2205)
#define NDL_ESP_RESULT_SET_STATE_ERROR       (-2300)

// connectionId(mediaId) buffer size
#define CONNECTION_ID_BUFFER_SIZE   17

#endif // NDL_DIRECTMEDIA2_MEDIA_COMMON_H_
