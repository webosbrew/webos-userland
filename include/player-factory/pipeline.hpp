#pragma once

namespace mediapipeline {

class Pipeline {
public:
    bool setUpdateInterval(int32_t currentTimeInterval, int32_t bufferRangeInterval);
    bool informationMonitorStop();
    bool informationMonitorStart(uint32_t timeInterval);
};
}
