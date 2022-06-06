// SPDX-License-Identifier: GPL-2.0

/*
 *  tg_method.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <json-c/json.h>
#include "fetchres.h"
/* #include "curl_fn.h" */
#include "curl_obj.h"
#include "ctg.h"

tg_json_fetch_res_t* get_update(int offset, int limit)
{
        chdata_t *ks;
        ctg_utils_t *ctgu;
        ks = ch_init();
        curl_req(ks);
}