#pragma once

#include <player-factory/common.hpp>
#include <player-factory/pipeline.hpp>

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>

namespace mediapipeline {

struct PipelineGStreamerElements
{
  void* pipeline;
  void* videoSrc;
  uint32_t videoBufferSettings[4];
  void* audioSrc;
  uint32_t audioBufferSettings[4];
  void* videoQueue;
  void* videoDecoder;
  void* videoParse;
  void* videoSink;
  void* videoSinkQueue;
  void* audioQueue;
  void* audioDecoder;
  void* audioReformatter;
  void* audioParse;
  void* audioSink;
  void* audioSinkQueue;
  void* audioResampler;
  void* audioConverter;
};

class CustomPipeline : public Pipeline {
public:
  inline PipelineGStreamerElements* GetGStreamerElements(const std::array<uint32_t, 4>& target,
                                                         const int searchOffset = 2048)
  {
    const auto memory = reinterpret_cast<uint8_t*>(this);

    for (int i = 0; i < searchOffset; ++i)
    {
      if (std::memcmp(memory + i, target.data(), sizeof(uint32_t) * 4) == 0)
      {
        return reinterpret_cast<PipelineGStreamerElements*>(
            memory + i - offsetof(PipelineGStreamerElements, videoBufferSettings));
      }
    }

    return nullptr;
  }

  bool loadSpi_getInfo(MEDIA_CUSTOM_CONTENT_INFO_T* contentInfo);
  void sendSegmentEvent();
  void setContentInfo(MEDIA_CUSTOM_SRC_TYPE_T srcType, MEDIA_CUSTOM_CONTENT_INFO_T* contentInfo);
};

}
