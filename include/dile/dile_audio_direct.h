/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file		dile_audio_direct.h
 *
 *  Device Interface Layer for Direct Audio
 *
 *  @author		keunbae.choi(keunbae.choi\@lge.com)
 *  @version	1.1
 *  @date		2013.12.14
 *  @note
 *  @see
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef	__DILE_AUDIO_DIRECT_H__
#define	__DILE_AUDIO_DIRECT_H__

/******************************************************************************
    File Inclusions
******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
    Constant Definitions
******************************************************************************/

/******************************************************************************
    Macro Definitions
******************************************************************************/

/******************************************************************************
    Type Definitions
******************************************************************************/

#ifndef DILE_STATUS_T

typedef enum
{
	DILE_OK = 0,
	DILE_NOT_OK = -1,
} _DILE_STATUS_T;

#define DILE_STATUS_T _DILE_STATUS_T

#endif

/**
 * DILE AUDIO Channel.
 *
 */
typedef enum
{
	DILE_AUDIO_DIRECT_MAIN = 0,
	DILE_AUDIO_DIRECT_SUB,

	DILE_AUDIO_DIRECT_CHANNEL_MAX = 2
} DILE_AUDIO_DIRECT_CHANNEL_T;

/**
 * DILE AUDIO Decoder Index.
 *
 */
typedef enum
{
	DILE_AUDIO_DIRECT_ADEC0			= 0,
	DILE_AUDIO_DIRECT_ADEC1			= 1,
	DILE_AUDIO_DIRECT_ADEC2			= 2,
	DILE_AUDIO_DIRECT_ADEC3			= 3,
	DILE_AUDIO_DIRECT_MIXER0		= 4,	/* G-Streamer Mixer  0 */
	DILE_AUDIO_DIRECT_MIXER1		= 5,	/* G-Streamer Mixer  1 */
	DILE_AUDIO_DIRECT_MIXER2		= 6,	/* G-Streamer Mixer  2 */
	DILE_AUDIO_DIRECT_MIXER3		= 7,	/* G-Streamer Mixer  3 */
	DILE_AUDIO_DIRECT_MIXER4		= 8,	/* G-Streamer Mixer  4 */
	DILE_AUDIO_DIRECT_MIXER5		= 9,	/* DILE AUDIO Mixer  0 */
	DILE_AUDIO_DIRECT_MIXER6		= 10,	/* ALSA AUDIO Mixer  0 */
	DILE_AUDIO_DIRECT_MIXER7		= 11,	/* ALSA AUDIO Mixer  1 */
	DILE_AUDIO_DIRECT_MIXER_MAX		= DILE_AUDIO_DIRECT_MIXER7,
} DILE_AUDIO_DIRECT_INDEX_T;

/**
 * DILE AUDIO DIRECT Codec Type.
 *
 */
typedef enum
{
	DILE_AUDIO_DIRECT_SRC_TYPE_UNKNOWN,			///< 0
	DILE_AUDIO_DIRECT_SRC_TYPE_PCM,				///< 1
	DILE_AUDIO_DIRECT_SRC_TYPE_AC3,				///< 2(AC3, E-AC3(DD+))
	DILE_AUDIO_DIRECT_SRC_TYPE_AAC,				///< 3(AAC, HE-AAC)
	DILE_AUDIO_DIRECT_SRC_TYPE_MP3,				///< 5
} DILE_AUDIO_DIRECT_SRC_TYPE_T;

/**
 * AUDIO Sampling Frequency Index.
 */
typedef enum
{
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_NONE		=	     0,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_4_KHZ,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_8_KHZ,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_11_025KHZ,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_12_KHZ,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_16_KHZ,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_22_05KHZ,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_24_KHZ,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_32_KHZ,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_44_1KHZ,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_48_KHZ,
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_64_KHZ,
} DILE_AUDIO_DIRECT_SAMPLING_FREQ_T;

/**
 * DILE AUDIO Data Info
 *
*/
typedef struct
{
	DILE_AUDIO_DIRECT_CHANNEL_T			audioChannel;
	DILE_AUDIO_DIRECT_SRC_TYPE_T		audioSource;
	DILE_AUDIO_DIRECT_SAMPLING_FREQ_T	samplingFreq;
	unsigned int						numberOfChannel;
	unsigned int						bitPerSample;
} DILE_AUDIO_DIRECT_DATA_INFO_T;
/******************************************************************************
    Function Declaration
******************************************************************************/
/**
 *	Set audio resource
 *
 *	@param	audioChannel		[in]	audio Channel
 *	@param	audioIndex			[in]	audio Index
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_Open(DILE_AUDIO_DIRECT_CHANNEL_T audioChannel, DILE_AUDIO_DIRECT_INDEX_T audioIndex);

/**
 *	Set audio source information
 *
 *	@param	audioDataInfo		[in]	audio data information
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_Start(DILE_AUDIO_DIRECT_DATA_INFO_T audioDataInfo);

/**
 *	Send audio data into buffer
 *
 *	@param	audioChannel		[in]	audio Channel
 *	@param	pBuff				[in]	pointer of buffer
 *	@param	bufSize				[in]	buffer size
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_Write(DILE_AUDIO_DIRECT_CHANNEL_T audioChannel, void *pBuff, unsigned int bufSize);

/**
 *	Stop audio playback
 *
 *	@param	audioChannel		[in]	audio Channel
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_Stop(DILE_AUDIO_DIRECT_CHANNEL_T audioChannel);

/**
 *	Release audio resource
 *
 *	@param	audioChannel		[in]	audio Channel
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_Close(DILE_AUDIO_DIRECT_CHANNEL_T audioChannel);

/**
 *	Pause audio playback
 *
 *	@param	audioChannel		[in]	audio Channel
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_Pause(DILE_AUDIO_DIRECT_CHANNEL_T audioChannel);

/**
 *	Resume audio playback
 *
 *	@param	audioChannel		[in]	audio Channel
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_Resume(DILE_AUDIO_DIRECT_CHANNEL_T audioChannel);

/**
 *	Flush audio buffer
 *
 *	@param	audioChannel		[in]	audio Channel
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_Flush(DILE_AUDIO_DIRECT_CHANNEL_T audioChannel);

/**
 *	Check remaining audio data in buffer
 *
 *	@param	audioChannel		[in]	audio Channel
 *	@param	pMaxBufSize			[out]	total buffer size
 *	@param	pFreeBufSize		[out]	remaining audio data
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_GetBufferInfo(DILE_AUDIO_DIRECT_CHANNEL_T audioChannel, unsigned int *pMaxBufSize, unsigned int *pFreeBufSize);

/**
 *	Check remaining audio raw data in buffer
 *
 *	@param	audioChannel		[in]	audio Channel
 *	@param	pMaxBufSize			[out]	total buffer size
 *	@param	pFreeBufSize		[out]	remaining audio data
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_GetRawBufferInfo(DILE_AUDIO_DIRECT_CHANNEL_T audioChannel, unsigned int *pMaxBufSize, unsigned int *pFreeBufSize);

/**
 *	reduce audio delay
 *
 *	@param	audioChannel		[in]	audio Channel
 *	@param	bOnOff				[in]	On/Off
 *	@param	upperThreshold		[in]	Maximum value
 *	@param	lowerThreshold		[in]	Minimum value
 *	@return	succeeded - DILE_OK, if not - DILE_NOT_OK.
 */
DILE_STATUS_T DILE_AUDIO_DIRECT_SetNoDelayParam(DILE_AUDIO_DIRECT_CHANNEL_T audioChannel, unsigned int bOnOff, unsigned int upperThreshold, unsigned int lowerThreshold);

#ifdef __cplusplus
}
#endif

#endif /* __DILE_AUDIO_DIRECT_H__ */
