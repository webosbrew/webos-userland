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

#ifndef NDL_DIRECTMEDIA2_STATE_H_
#define NDL_DIRECTMEDIA2_STATE_H_


#ifdef __cplusplus
extern "C" {
#endif


    typedef enum {
        NDL_ESP_STATUS_IDLE,
        NDL_ESP_STATUS_LOADED,
        NDL_ESP_STATUS_PLAYING,
        NDL_ESP_STATUS_PAUSED,
        NDL_ESP_STATUS_UNLOADED,
        NDL_ESP_STATUS_FLUSHING,
        NDL_ESP_STATUS_STEPPING,
        NDL_ESP_STATUS_EOS,
        NDL_ESP_STATUS_COUNT,
    } NDL_ESP_STATUS;


    typedef enum {
        NDL_ESP_APP_STATE_INIT,
        NDL_ESP_APP_STATE_FOREGROUND,
        NDL_ESP_APP_STATE_BACKGROUND,
        NDL_ESP_APP_STATE_RESERVED,
    } NDL_ESP_APP_STATE;



#ifdef __cplusplus
}
#endif

#endif  // NDL_DIRECTMEDIA2_STATE_H_
