// SPDX-License-Identifier: GPL-2.0

/*
 *  curl_obj.h
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <curl/curl.h>
#include <stdbool.h>
#if !defined(CURL_MAX_BUFFER)
        #define CURL_MAX_BUFFER 20480
#endif
#if !defined (chdata_t) || !defined (chdata)
        typedef struct chdata {
               CURL             *ch;
               char             *data; 
               size_t           size;
               bool             curlerr;
        } chdata_t;
        
#endif


chdata_t* ch_init();
void curl_req(chdata_t *ks, char *url);

