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

#ifndef NDL_DIRECTMEDIA2_ESPLAYER_API_H_
#define NDL_DIRECTMEDIA2_ESPLAYER_API_H_

#include <stdint.h>
#include <stddef.h>
#include "ndl-directmedia2/media-common.h"
#include "ndl-directmedia2/states.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* NDL_EsplayerHandle;
    typedef void NDL_EsplayerCallback(NDL_ESP_EVENT event, void* playerdata, void* userdata);
    typedef NDL_ESP_STREAM_BUFFER* NDL_EsplayerBuffer;

    /**
     * Create an esplayer
     *
     * @param callback  client function to be called on events
     * @param userdata  data to be passed to callback
     * @return          esplayer handle
     */
    NDL_EsplayerHandle NDL_EsplayerCreate(const char* appid, NDL_EsplayerCallback callback, void* userdata);

    /**
     * Destroy the esplayer
     */
    void NDL_EsplayerDestroy(NDL_EsplayerHandle player);

    /**
     * Get connectionId(mediaId)
     *
     * @param buff        OUT    return connectionId(unique) for applicatoin to handle media command (16 characters)
     * @param buff_len    IN     allocated buffer length (the length should be at least 17)
     * @return            0      on success
     */
    int NDL_EsplayerGetConnectionId(NDL_EsplayerHandle player, char* buf, size_t buf_len);

    /**
     * Load the resources based on meta data
     *
     * @param meta  esplayer configuration data, such as stream information
     * @return      0 on success
     */
    int NDL_EsplayerLoad(NDL_EsplayerHandle player, NDL_ESP_META_DATA* meta);

    /**
     * Load the resources based on meta data and additional parameters
     *
     * @param meta  esplayer configuration data, such as stream information
     * @return      0 on success
     */
    int NDL_EsplayerLoadEx(NDL_EsplayerHandle player, NDL_ESP_META_DATA* meta, NDL_ESP_PTS_UNITS units);

    /**
     * Unload the resources
     * @return      0 on success
     */
    int NDL_EsplayerUnload(NDL_EsplayerHandle player);

    /**
     * Start playing
     *
     * @return      0 on success
     */
    int NDL_EsplayerPlay(NDL_EsplayerHandle player);

    /**
     * Pause
     *
     * @return      0 on success
     */
    int NDL_EsplayerPause(NDL_EsplayerHandle player);

    /**
     * Write an element stream.
     *
     * @param buff  element stream data, should contain 1 audio or video frame data exactly
     * @return      the number of bytes written
     *              NDL_ESP_RESULT_FEED_FULL means OMX buffer is full
     */
    int NDL_EsplayerFeedData(NDL_EsplayerHandle player, NDL_EsplayerBuffer buff);

    /**
     * Show the first frame in the stream buffer.
     *
     * @return      0 on success
     */
    int NDL_EsplayerStepFrame(NDL_EsplayerHandle player);

    /**
     * Flush the steam buffer.
     *
     * @param type  stream type (audio or video)
     * @return      0 on success
     */
    int NDL_EsplayerFlush(NDL_EsplayerHandle player);

    /**
     * Get audio/video decoder buffer level.
     * @param type  stream type (audio or video)
     * @return      current buffer level
     */
    int NDL_EsplayerGetBufferLevel(NDL_EsplayerHandle player, NDL_ESP_STREAM_T type, uint32_t * level);

    /**
     * Get the esplayer state.
     */
    NDL_ESP_STATUS NDL_EsplayerGetStatus(NDL_EsplayerHandle player);

    /**
     * Get the esplayer current media time.
     */
    int NDL_EsplayerGetMediatime(NDL_EsplayerHandle player, int64_t* start_time, int64_t* current_time);

    /**
     * Set playback rate.
     *
     * @return      0 on success
     */
    int NDL_EsplayerSetPlaybackRate(NDL_EsplayerHandle player, int rate);

    /**
     * Reload audio resources.
     *
     * @return      0 on success
     */
    int NDL_EsplayerReloadAudio(NDL_EsplayerHandle player, NDL_ESP_META_DATA* meta);

    /**
     * Set Display Window
     * @param       left,top,width,height : destination window size
     * @param       isFullScreen : 1(true), 0(false)
     * @return      0 on success
     */
    int NDL_EsplayerSetVideoDisplayWindow(NDL_EsplayerHandle player,
            long left, long top, long width, long height, int isFullScreen);

    /**
     * Set Custom Display Window
     * @param       source window
     * @param       destination window size
     * @param       isFullScreen : 1(true), 0(false)
     * @return      0 on success
     */
    int NDL_EsplayerSetVideoCustomDisplayWindow(NDL_EsplayerHandle player,
            long src_left, long src_top, long src_width, long src_height,
            long dst_left, long dst_top, long dst_width, long dst_height,
            int isFullScreen);

    /**
     * Set Application State
     * @return      0 on success
     */
    int NDL_EsplayerSetAppForegroundState(NDL_EsplayerHandle player, NDL_ESP_APP_STATE appState);


    /**
     * Start audio or video mute
     * @param mute     1 : start audio mute, 0 : stop audio mute
     * @return         0 on success
     */
    int NDL_EsplayerMuteAudio(NDL_EsplayerHandle player, int mute);

    /**
     * Stop audio or video mute
     * @param audio    1 : start video mute, 0 : stop video mute
     * @return         0 on success
     */
    int NDL_EsplayerMuteVideo(NDL_EsplayerHandle player, int mute);


    /**
     * Set Contents 3D type
     * @return      0 on success
     */
    int NDL_EsplayerSet3DType(NDL_EsplayerHandle player, NDL_ESP_3D_TYPE e3DType);

    /**
     * Set trick mode (slow/step/fast/rew)
     *   it should be called between flush and feed
     *   it makes a/v sync handler not to wait for
     * @param enable   1 : start trick mode, 0 : stop trick mode
     * @return         0 on success
     */
    int NDL_EsplayerSetTrickMode(NDL_EsplayerHandle player, int enable);


    /**
     * Set playback volume & ease/fade effect
     * @param volume    playback volume(0-100)
     * @param duration    Ease Duration(msec)
     * @param type    Ease Mode(0 : Linear mode, 1 : Incubic mode, 2: OutCubic mode)
     * @return    0 on success
     */
    int NDL_EsplayerSetVolume(NDL_EsplayerHandle player, int volume, int duration, NDL_ESP_EASE_TYPE type);

#ifdef __cplusplus
}
#endif

#endif //#ifdef NDL_DIRECTMEDIA2_ESPLAYER_API_H_
