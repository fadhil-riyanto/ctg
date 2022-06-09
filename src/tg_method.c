// SPDX-License-Identifier: GPL-2.0

/*
 *  tg_method.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <json-c/json.h>
#include <stdio.h>
#include "curl_obj.h"
#include "fetchres.h"
#include "ctg.h"
#include "http_func.h"

/* debug */
#include "debug_fn.h"

tg_json_fetch_res_t* get_updates(ctg_utils_t *maindt, int offset, int limit)
{
        key_value_t data_param[2]; // create params
        chdata_t *ks;
        char buff[5000];

        insert_key_value(data_param, "tes faddhils", "set"); 
	insert_key_value(data_param, "tes 2", "set2");

        char *urlparam = http_build_query(data_param, sizeof(data_param) / sizeof(data_param[0]));
        sprintf(buff, "https://api.telegram.org/bot%s/%s?%s", maindt->bot_token, "getUpdates", urlparam);
        
        printf("%s", buff);
        ks = ch_init();
        curl_req(ks, buff);

        printf(ks->data);
        free(urlparam);
        
}