#pragma once

#include <string>
#include <cstdint>

#include <boost/shared_ptr.hpp>

namespace mediapipeline {
    class Player;
}

namespace smp {
    class ProgramInfo;
    class SourceInfo;
    class VideoTrack;

    namespace util {
        bool isPlatformFhd(const std::string& platform);
        bool isPlatformMStar(const std::string& platform);
        bool isPlatformSIC(const std::string& platform);
        bool isPlatformRealtek(const std::string& platform);
        bool isPlatformSupportSoftwareAudioDecoder(std::string platform);

        bool isSupportedAudio(std::string audio, int32_t version, int32_t channel);
        bool isSupportedVideo(std::string video, int32_t width, int32_t height, int32_t frameRate, int64_t bitRate);
        bool isSupportedVideo(std::string video, int32_t width, int32_t height, int32_t frameRate, int64_t bitRate, std::string decodeType);

        bool getMaxVideoResolution(std::string video, int32_t* width, int32_t* height, int32_t* frameRate);
        bool getMaxVideoResolution(std::string video, int32_t* width, int32_t* height, int32_t* frameRate, std::string decodeType);
    }
}

class StarfishMediaAPIs
{
public:
    StarfishMediaAPIs(const char *uid = nullptr);
    ~StarfishMediaAPIs();

    bool Exit();
    std::string Feed(const char *payload);
    bool flush();
    bool flush(const char *payload);
    int64_t getCurrentPlaytime();
    bool getVideoRenderQueueLength(int &length);
    bool getAudioBufferSize(int &total, int &used);
    const char *getMediaID();
    const char *getVolume();
    bool Load(const char *payload, void(callback)(int type, int64_t numValue, const char *strValue));
    bool Load(const char *payload, void(callback)(int type, int64_t numValue, const char *strValue, void *data), void *data);
    bool notifyBackground();
    bool notifyForeground();
    bool Pause();
    bool Play();
    bool pushEOS();
    void setCurrentPlaytime(int64_t playtime);
    bool Seek(const char *millis);
    bool setAudioMute(const char *message);
    void setDrmOperation(const char* message);
    bool setHdrInfo(const char* message);
    bool SetPlayRate(const char* message);
    bool SetProperty(const char* message);
    bool setTimeToDecode(const char *);
    bool setVolume(const char *);
    bool setWindowId(const char* message);
    bool Stop();
    bool takeSnapshot(const char *message);
    bool Unload();
#ifdef __G_MAIN_H__
    void setExternalContext(GMainContext *);
    void unsetExternalContext();
#endif
private:
    char unknown[76];
public:
    boost::shared_ptr<mediapipeline::Player> player;
private:
    // Must include big enough storage size. On some system it has 300 bytes, 4KB here should be fairly enough
    char padding[4096];
};

enum PF_EVENT_T
{
    PF_EVENT_TYPE_FRAMEREADY = 0x0,
    PF_EVENT_TYPE_STR_STREAMING_INFO_PERI = 0x1,
    PF_EVENT_TYPE_INT_BUFFER_RANGE_INFO = 0x2,
    PF_EVENT_TYPE_INT_DURATION = 0x3,
    PF_EVENT_TYPE_STR_VIDEO_INFO = 0x4,
    PF_EVENT_TYPE_STR_VIDEO_TRACK_INFO = 0x5,
    PF_EVENT_TYPE_STR_AUDIO_INFO = 0x7,
    PF_EVENT_TYPE_STR_AUDIO_TRACK_INFO = 0x8,
    PF_EVENT_TYPE_STR_SUBT_TRACK_INFO = 0x9,
    PF_EVENT_TYPE_STR_BUFF_EVENT = 0xa,
    PF_EVENT_TYPE_STR_SOURCE_INFO = 0xb,
    PF_EVENT_TYPE_INT_NUM_PROGRAM = 0xd,
    PF_EVENT_TYPE_INT_NUM_VIDEO_TRACK = 0xe,
    PF_EVENT_TYPE_INT_NUM_AUDIO_TRACK = 0xf,
    PF_EVENT_TYPE_STR_RESOURCE_INFO = 0x11,
    PF_EVENT_TYPE_INT_ERROR = 0x12,
    PF_EVENT_TYPE_STR_ERROR = 0x13,
    PF_EVENT_TYPE_STR_STATE_UPDATE__PRELOADCOMPLETED = 0x15,
    PF_EVENT_TYPE_STR_STATE_UPDATE__LOADCOMPLETED = 0x16,
    PF_EVENT_TYPE_STR_STATE_UPDATE__UNLOADCOMPLETED = 0x17,
    PF_EVENT_TYPE_STR_STATE_UPDATE__TRACKSELECTED = 0x18,
    PF_EVENT_TYPE_STR_STATE_UPDATE__SEEKDONE = 0x19,
    PF_EVENT_TYPE_STR_STATE_UPDATE__PLAYING = 0x1a,
    PF_EVENT_TYPE_STR_STATE_UPDATE__PAUSED = 0x1b,
    PF_EVENT_TYPE_STR_STATE_UPDATE__ENDOFSTREAM = 0x1c,
    PF_EVENT_TYPE_STR_CUSTOM = 0x1d,
    PF_EVENT_TYPE_INT_NEED_DATA = 0x26,
    PF_EVENT_TYPE_INT_ENOUGH_DATA = 0x27,
    PF_EVENT_TYPE_INT_SVP_VDEC_READY = 0x2b,
    PF_EVENT_TYPE_INT_BUFFERLOW = 0x2c,
    PF_EVENT_TYPE_STR_BUFFERFULL = 0x2d,
    PF_EVENT_TYPE_STR_BUFFERLOW = 0x2e,
    PF_EVENT_TYPE_DROPPED_FRAME = 0x30,
    PF_EVENT_USER_DEFINED = 0x270,
};