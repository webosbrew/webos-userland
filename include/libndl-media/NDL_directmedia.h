/**
 * @defgroup NDL_directmedia NDL_directmedia
 * @brief NDL DirectMedia API
 */

/**
 * @ingroup NDL_directmedia
 * @file NDL_directmedia.h
 * @brief NDL DirectMedia API
 */
#ifndef NDL_DIRECTMEDIA_API_VERSION
# define NDL_DIRECTMEDIA_API_VERSION 1
#endif

#if (NDL_DIRECTMEDIA_API_VERSION == 1)
# include "NDL_directmedia_v1.h"
#elif (NDL_DIRECTMEDIA_API_VERSION == 2)
# include "NDL_directmedia_v2.h"
#else
# error "unknown NDL_DIRECTMEDIA_API_VERSION"
#endif
