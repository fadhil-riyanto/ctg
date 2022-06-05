// SPDX-License-Identifier: GPL-2.0

/*
 *  curl_obj.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include "curl_obj.h"
#include "curl_fn.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <stdlib.h>
#include <stddef.h>

void curl_req(char *url) 
{
        chdata_t *chdata;
        CURLcode chcode;
        
        /* allocate memory */
        chdata->data = malloc(1);

        /* set to 0 */
        chdata->size = 0;

        chdata->ch = curl_easy_init();
        curl_easy_setopt(chdata->ch, CURLOPT_URL, url);
        curl_easy_setopt(chdata->ch, CURLOPT_WRITEFUNCTION, curl_cb);
        curl_easy_setopt(chdata->ch, CURLOPT_WRITEDATA, (void*) &chdata->data);
        chcode = curl_easy_perform(chdata->ch);
        if(chcode != CURLE_OK) {
                fprintf(stderr, "curl req failed: %s\n", curl_easy_strerror(chcode));
        }
         
}
static size_t curl_cb(void *contents, size_t size, size_t nmemb, void *userp) 
{

}