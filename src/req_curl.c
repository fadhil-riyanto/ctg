// SPDX-License-Identifier: GPL-2.0

/*
 *  req_curl.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include "curl_obj.h"
#include "curl_fn.h"
#include "debug_fn.h"
#include <asm-generic/errno-base.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <string.h>
#include "debug_fn.h"

chdata_t* ch_init(){
        chdata_t *chdata;
        chdata = malloc(sizeof(*chdata));

        CURL *ch;
        ch = curl_easy_init();
        if(!ch){
                free(chdata);
                return NULL;
        }
        chdata->ch = ch;
        chdata->data = malloc(sizeof(char));
        chdata->size = 0;
        return chdata;
}

static size_t curl_cb(void *contents, size_t size, size_t nmemb, void *userp) 
{
        size_t sizeall = size * nmemb;
        chdata_t *cdata = (chdata_t *) userp;

        char *resize_memory_asal = realloc(cdata->data, cdata->size + sizeall + 1);
        if(!resize_memory_asal)
        {
                DEBUGE("%s", "error no memory\n");
                return -ENOMEM;
        }
        
        cdata->data = resize_memory_asal;
        memcpy(&(cdata->data[cdata->size]), contents, sizeall);
        cdata->size += sizeall;
        cdata->data[cdata->size] = 0;
        return sizeall;
}

void curl_req(chdata_t *chdata, char *url)
{
        CURL *ch = chdata->ch;
        CURLcode response;

        curl_global_init(CURL_GLOBAL_ALL);
        ch = curl_easy_init();
        curl_easy_setopt(ch, CURLOPT_URL, url);
        curl_easy_setopt(ch, CURLOPT_WRITEFUNCTION, curl_cb);
        curl_easy_setopt(ch, CURLOPT_WRITEDATA, chdata);
        response = curl_easy_perform(ch);
        if(response != CURLE_OK){ 
                chdata->curlerr = true;
                DEBUGP("curl error\n");
        }else{
                chdata->curlerr = false;
                DEBUGP("data: %s\n", chdata->data);
        }
        curl_easy_cleanup(ch);
        curl_global_cleanup();
}

