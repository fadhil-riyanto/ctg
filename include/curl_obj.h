// SPDX-License-Identifier: GPL-2.0

/*
 *  curl_obj.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <curl/curl.h>
#if !defined(CURL_MAX_BUFFER)
        #define CURL_MAX_BUFFER 20480
#endif
#if !defined (chdata_t) || !defined (chdata)
        typedef struct chdata {
               CURL             *ch;
               char             *data; 
               size_t           size;
        } chdata_t;
        
#endif
