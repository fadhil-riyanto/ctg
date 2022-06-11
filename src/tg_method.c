// SPDX-License-Identifier: GPL-2.0

/*
 *  tg_method.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <json-c/json.h>
#include "utils.c"
#include "stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include "curl_obj.h"
#include "fetchres.h"
#include "ctg.h"
#include "http_func.h"
#include <math.h>

/* debug */
#include "debug_fn.h"

void init_telegram()
{

}

tg_json_getupdates_t* get_updates(ctg_utils_t *maindt, int offset, int limit)
{
        key_value_t data_param[2]; // create params
        chdata_t *ks;
        char buff[5000];

        

        // convert to string
        char *offset_str = int_to_string_alloc(offset);
        char *limit_str = int_to_string_alloc(limit);

        insert_key_value(data_param, "offset", offset_str); 
	    insert_key_value(data_param, "limit", limit_str);

        char *urlparam = http_build_query(data_param, sizeof(data_param) / sizeof(data_param[0]));
        sprintf(buff, "https://api.telegram.org/bot%s/%s?%s", maindt->bot_token, "getUpdates", urlparam);
        
        DEBUGP("url: %s\n", buff);
        ks = ch_init();
        curl_req(ks, buff);

        if(ks->curlerr == true) {
                DEBUGP("%s", "curl error while getting data. trying again ... ");
        }
        free(urlparam);
        free(offset_str);
        free(limit_str);

        json_object *raw = json_tokener_parse(ks->data);
        json_object *index_null;
        json_object *is_ok = json_object_object_get(raw, "ok");
        if(json_object_get_boolean(is_ok) != true) {
                DEBUGP("\n%s", "telegram result returned false");
        } else {
                tg_json_getupdates_t *getupdates_res = malloc(sizeof(*getupdates_res));

                /* get the result */
                json_object *result = json_object_object_get(raw, "result");
                index_null = json_object_array_get_idx(result, 0);

                /* get update_id [root] */
                json_object *updateid = json_object_object_get(index_null, "update_id");
                getupdates_res->update_id = json_object_get_int(updateid);

                /* get [root].message */
                json_object *messagecl = json_object_object_get(index_null, "message");

                /* get [root].message.message_id */
                json_object *message_id = json_object_object_get(messagecl, "message_id");
                getupdates_res->message.message_id = json_object_get_int(message_id);

                /* get [root].message.from.id */
                messagecl = json_object_object_get(index_null, "message");
                json_object *fromcl = json_object_object_get(messagecl, "from");
                json_object *from_id = json_object_object_get(fromcl, "id");
                
                // DEBUGP("%s\n", json_object_to_json_string_ext(from_id, JSON_C_TO_STRING_PRETTY));
                DEBUGP("%s\n", json_object_get_string(from_id));
                DEBUGP("%ld\n", (uint64_t)json_object_get_uint64(from_id));
                // getupdates_res->message.from.id = json_object_get_int(from_id);
                return getupdates_res;
        }
        free(ks);
        
        
}
