#pragma once

#include <player-factory/common.hpp>
#include <player-factory/pipeline.hpp>

namespace mediapipeline {

class CustomPipeline : public Pipeline {
public:
  bool loadSpi_getInfo(MEDIA_CUSTOM_CONTENT_INFO_T* contentInfo);
  void sendSegmentEvent();
  void setContentInfo(MEDIA_CUSTOM_SRC_TYPE_T srcType, MEDIA_CUSTOM_CONTENT_INFO_T* contentInfo);
};

}
