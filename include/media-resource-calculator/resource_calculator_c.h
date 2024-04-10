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

#ifndef RESOURCE_CALCULATOR_C_H_
#define RESOURCE_CALCULATOR_C_H_

#ifdef __cplusplus
extern "C" {
#endif

enum MRCVideoCodec {
    kVideoEtc = (1 << 0),
    kVideoH264 = (1 << 1),
    kVideoH265 = (1 << 2),
    kVideoMPEG = (1 << 3), // MPEG1/2
    kVideoMVC = (1 << 4),
    kVideoSVC = (1 << 5),
    kVideoVP9 = (1 << 6),
    kVideoRM = (1 << 7),
    kVideoAVS = (1 << 8),
    kVideoVP8 = (1 << 9),
    kVideoMJPEG = (1 << 10),
    kVideoMPEG4 = (1 << 11),
    kVideoJPEG = (1 << 12),
};

enum MRCScanType {
    kScanProgressive,
    kScanInterlaced,
};

enum MRC3DType {
    k3DNone,
    k3DSequential,
    k3DMultiStream,
};

enum MRCAudioCodec {
    kAudioEtc = (1 << 0),
    kAudioMPEG = (1 << 1),
    kAudioPCM = (1 << 2),
    kAudioDTS = (1 << 3),
    kAudioDTSE = (1 << 4),
    kAudioMPEGH = (1 << 5),
    kAudioAC4 = (1 << 6),
    kAudioATMOS = (1 << 7),
    kAudioDescription = (1 << 8),
};

typedef struct MRCResource {
    char *type;
    int quantity;
} MRCResource;

// null-terminated array of MRCResource pointer
typedef MRCResource** MRCResourceList;
typedef MRCResourceList* MRCResourceListOptions;

// codecs are combination of bitmasks defined in enum MRCVideoCodec.
// Zero width or height is considered as 4K resolution.
// Zero frameRate is considered as max frameRate for each codec.
MRCResourceList MRCCalcVdecResources(int codecs,
                                     int width,
                                     int height,
                                     int frameRate,
                                     enum MRCScanType scanType,
                                     enum MRC3DType _3dType);

MRCResourceListOptions MRCCalcVdecResourceOptions(int codecs,
                                                  int width,
                                                  int height,
                                                  int frameRate,
                                                  enum MRCScanType scanType,
                                                  enum MRC3DType _3dType);

MRCResourceList MRCCalcAdecResources(int codecs,
                                     int version,
                                     int channel);

MRCResourceList MRCCalcMiscResources(int useSecureVideoPath, int useSecureReformatter);

void MRCDeleteResourceList(MRCResourceList resourceList);

#ifdef __cplusplus
}
#endif

#endif // RESOURCE_CALCULATOR_C_H_