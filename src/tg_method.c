// SPDX-License-Identifier: GPL-2.0

/*
 *  tg_method.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <json-c/json.h>
#include <curl/curl.h>
#include "utils.c"
#include "stdlib.h"
#include <json-c/json_object.h>
#include <json-c/json_types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "curl_obj.h"
#include "fetchres.h"
#include "ctg.h"
#include "http_func.h"
#include <math.h>

/* debug */
#include "debug_fn.h"

tg_json_getupdates_t* get_updates(ctg_utils_t *maindt, tg_json_getupdates_t *getupdates_res, int offset, int limit)
{
        key_value_t data_param[2]; // create params
        chdata_t *ks;
        char buff[5000];

        // convert to string
        char *offset_str = int_to_string_alloc(offset);
        char *limit_str = int_to_string_alloc(limit);

        insert_key_value(data_param, "offset", offset_str); 
	insert_key_value(data_param, "limit", limit_str);
        reset_count_key_value();

        char *urlparam = http_build_query(data_param, sizeof(data_param) / sizeof(data_param[0]));
        sprintf(buff, "https://api.telegram.org/bot%s/%s?%s", maindt->bot_token, "getUpdates", urlparam);
        
        DEBUGP("url: %s\n", buff);
returnreq:
        ks = ch_init();
        curl_req(ks, buff);

        if(ks->curlerr == true) {
                DEBUGP("%s", "curl error while getting data. trying again ... ");
                goto returnreq;
        }
        
        free(urlparam);
        free(offset_str);
        free(limit_str);

        json_object *raw = json_tokener_parse(ks->data);
        
        json_object *index_null;
        json_object *is_ok = json_object_object_get(raw, "ok");
        if(json_object_get_boolean(is_ok) != true) {
                DEBUGE("%s\n", "telegram result returned false");
                exit(1);
        } 
        

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

        /* get [root].message.date and text */
        json_object *date = json_object_object_get(messagecl, "date");
        getupdates_res->message.date = json_object_get_int64(date);
        
        json_object *text = json_object_object_get(messagecl, "text");
        getupdates_res->message.text = json_object_get_string(text);

        /* get [root].message.entities[] */
        json_object *entities = json_object_object_get(messagecl, "entities");
        if(entities != NULL) {
                getupdates_res->message.entities[0].offset = 9;
                for (int i = 0; i < json_object_array_length(entities); i++) {
                        // get offset
                        json_object *entities_arr = json_object_array_get_idx(entities, i);
                        json_object *offset = json_object_object_get(entities_arr, "offset");
                        getupdates_res->message.entities[i].offset = json_object_get_int(offset);

                        // get limit
                        json_object *length = json_object_object_get(entities_arr, "length");
                        getupdates_res->message.entities[i].length = json_object_get_int(length);

                        // get type
                        json_object *type = json_object_object_get(entities_arr, "type");
                        getupdates_res->message.entities[i].type = json_object_get_string(type);
                }
        }

        /* get [root].message.sticker */
        json_object *sticker = json_object_object_get(messagecl, "sticker");
        
        // get width
        json_object *sticker_width = json_object_object_get(sticker, "width");
        getupdates_res->message.sticker.width = json_object_get_int(sticker_width);

        // get height
        json_object *sticker_height = json_object_object_get(sticker, "height");
        getupdates_res->message.sticker.height = json_object_get_int(sticker_height);

        // get emoji
        json_object *sticker_emoji = json_object_object_get(sticker, "emoji");
        getupdates_res->message.sticker.emoji = json_object_get_string(sticker_emoji);

        // get set_name
        json_object *sticker_set_name = json_object_object_get(sticker, "set_name");
        getupdates_res->message.sticker.set_name = json_object_get_string(sticker_set_name);

        // get is_animated
        json_object *sticker_is_animated = json_object_object_get(sticker, "is_animated");
        getupdates_res->message.sticker.is_animated = json_object_get_boolean(sticker_is_animated);

        // get is_video
        json_object *sticker_is_video = json_object_object_get(sticker, "is_video");
        getupdates_res->message.sticker.is_video = json_object_get_boolean(sticker_is_video);

        // thumb here

        // get file_id
        json_object *sticker_file_id = json_object_object_get(sticker, "file_id");
        getupdates_res->message.sticker.file_id = json_object_get_string(sticker_file_id);

        // get file_unique_id
        json_object *sticker_file_unique_id = json_object_object_get(sticker, "file_unique_id");
        getupdates_res->message.sticker.file_unique_id = json_object_get_string(sticker_file_unique_id);

        // get file_size
        json_object *sticker_file_size = json_object_object_get(sticker, "file_size");
        getupdates_res->message.sticker.file_size = json_object_get_int(sticker_file_size);

        /* get [root].message.from.id */
        messagecl = json_object_object_get(index_null, "message");
        json_object *fromcl = json_object_object_get(messagecl, "from");
        json_object *from_id = json_object_object_get(fromcl, "id");
        getupdates_res->message.from.id = json_object_get_int64(from_id);

        /* get [root].message.from.is_bot */
        json_object *is_bot = json_object_object_get(fromcl, "is_bot");
        getupdates_res->message.from.is_bot = json_object_get_boolean(is_bot);

        /* get [root].message.from.type */
        json_object *first_name = json_object_object_get(fromcl, "first_name");
        getupdates_res->message.from.first_name = json_object_get_string(first_name);
        
        /* get [root].message.from.first_name */
        json_object *last_name = json_object_object_get(fromcl, "last_name");
        getupdates_res->message.from.last_name = json_object_get_string(last_name);

        /* get [root].message.from.username */
        json_object *username = json_object_object_get(fromcl, "username");
        getupdates_res->message.from.username = json_object_get_string(username);

        /* get [root].message.from.username */
        json_object *language_code = json_object_object_get(fromcl, "language_code");
        getupdates_res->message.from.language_code = json_object_get_string(language_code);
        
        
        /* get [root].message.chat.id */
        messagecl = json_object_object_get(index_null, "message");
        json_object *chatcl = json_object_object_get(messagecl, "chat");
        json_object *chat_id = json_object_object_get(chatcl, "id");
        getupdates_res->message.chat.id = json_object_get_int64(chat_id);

        /* get [root].message.chat.first_name */
        first_name = json_object_object_get(chatcl, "first_name");
        getupdates_res->message.chat.first_name = json_object_get_string(first_name);

        /* get [root].message.chat.last_name */
        last_name = json_object_object_get(chatcl, "last_name");
        getupdates_res->message.chat.last_name = json_object_get_string(last_name);

        /* get [root].message.chat.username */
        username = json_object_object_get(chatcl, "username");
        getupdates_res->message.chat.username = json_object_get_string(username);

        /* get [root].message.chat.type */
        json_object *type = json_object_object_get(chatcl, "type");
        getupdates_res->message.chat.type = json_object_get_string(type);

        json_object_put(raw);

        free(ks->data);
        curl_easy_cleanup(ks->ch);
        free(ks);
        
        return getupdates_res;
}

void* send_message(ctg_utils_t *maindt, \
        int64_t chat_id, char *text, int reply_to_message_id, char *parse_mode, bool disable_web_page_preview) 
{
        key_value_t data_param[5];
        chdata_t *ks;
        char buff[5000];
        char strbuff[100];

        i64toa(strbuff, chat_id);

        insert_key_value(data_param, "chat_id", strbuff); 
        //insert_key_value(data_param, "reply_to_message_id", )
	insert_key_value(data_param, "text", text);
        insert_key_value(data_param, "parse_mode", parse_mode);
        insert_key_value(data_param, "disable_web_page_preview", (disable_web_page_preview) ? "true" : "false");
        
        reset_count_key_value();

        char *urlparam = http_build_query(data_param, sizeof(data_param) / sizeof(data_param[0]));
        sprintf(buff, "https://api.telegram.org/bot%s/%s?%s", maindt->bot_token, "sendMessage", urlparam);
        
        DEBUGP("url: %s\n", buff);
returnreq:
        ks = ch_init();
        curl_req(ks, buff);

        if(ks->curlerr == true) {
                DEBUGP("%s", "curl error while getting data. trying again ... ");
                goto returnreq;
        }
        
        free(urlparam);
}