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

ctg_utils_t ctgu;


tg_json_fetch_res_t* get_updates(int offset, int limit)
{
        key_value_t data_param[2]; // create params
        insert_key_value(data_param, "tes faddhils", "set"); 
	insert_key_value(data_param, "tes 2", "set2");

        char *urlparam = http_build_query(data_param, sizeof(data_param) / sizeof(data_param[0]));
        printf("%s ", urlparam);
        free(urlparam);
        
}