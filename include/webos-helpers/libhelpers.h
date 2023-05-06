/**
 * @defgroup helpers helpers
 * @brief webOS common helper
 */

/**
 * @ingroup helpers
 * @file libhelpers.h
 */
#pragma once

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct LSHandle LSHandle;
typedef struct LSMessage LSMessage;
typedef unsigned long LSMessageToken;

typedef bool (*LSFilterFunc) (LSHandle *sh, LSMessage *reply, void *ctx);


/**
 * @brief Context for luna service calls
 */
typedef struct HContext {
    /**
     * @brief Callback function called on incoming message.
     */
    LSFilterFunc callback;
    void* userdata;
    void* unknown;
    /**
     * @brief Whether the call is multiple (like subscription), or one-shot.
     */
    int multiple;
    /**
     * @brief Whether the call is a public call or private call
     */
    int pub;
    LSMessageToken ret_token;
} HContext;

/**
 * @brief Send luna call
 * @param uri
 * @param payload
 * @param context
 * @return 0 if succeeded
 */
int HLunaServiceCall(const char *uri, const char *payload, HContext *context);

/**
 * @brief Unregister a service callback
 * @param context Same context used in HLunaServiceCall
 * @return 0 if succeeded
 */
int HUnregisterServiceCallback(HContext *context);

/**
 * @brief Get payload message from luna call response
 * @param msg
 * @return Payload message (JSON string)
 */
const char *HLunaServiceMessage(LSMessage *msg);

#ifdef  __cplusplus
}
#endif
