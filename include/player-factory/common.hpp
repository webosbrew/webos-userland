#pragma once

#include <stdint.h>

typedef enum {
  MEDIA_CUSTOM_SRC_TYPE_ES = 7
} MEDIA_CUSTOM_SRC_TYPE_T;

typedef struct MEDIA_CUSTOM_CONTENT_INFO {
  int32_t mediaTransportType;
  int32_t mediaSourceType;
  int32_t container;
  uint64_t size;
  uint32_t videoCodec;
  uint32_t audioCodec;
  int32_t esCh;
  int64_t ptsToDecode;
  int32_t restartStreaming;
  int32_t separatedPTS;
  uint8_t svpVersion;
  int32_t preBufferTime;
  int32_t useBufferCtrl;
  int32_t userBufferCtrl;
  int32_t bufferingMinTime;
  int32_t bufferingMaxTime;
  uint8_t bufferMinPercent;
  uint8_t bufferMaxPercent;
  uint8_t padding[2];
  uint8_t videoDataInfo[104];
  uint8_t audioDataInfo[56];
  uint16_t unknown;
  uint32_t delayOffset;
  uint32_t drmType;
  char* drmTypeExtension;
  char* drmClientID;
  uint32_t startBPS;
  uint32_t unknown2;
  uint32_t unknown3;
  int32_t unknown4;
  int32_t unknown5;
  uint32_t startTime;
  uint8_t unknown6[20];
  int32_t unknown7;
} MEDIA_CUSTOM_CONTENT_INFO_T;
