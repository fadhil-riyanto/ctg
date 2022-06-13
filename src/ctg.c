// SPDX-License-Identifier: GPL-2.0

/*
 *  ctg.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "curl_fn.h"
#include "ctg.h"
#include "curl_obj.h"
#include "tg_method.h"
#include  <signal.h>
#include "debug_fn.h"

static volatile int want_exit = 0;

void sig_callback(int sig)
{
        want_exit = 1; // change status to 1
}

void *handle_update(tg_json_getupdates_t *recv_data) 
{
        // handle acces revc_data after ctrl + c
        if(want_exit == 1) {
                free(recv_data);
                pthread_exit(NULL);
        }else {
                printf("hai nama saya %s\n", recv_data->message.from.username);
                pthread_exit(NULL);
        }
        
}

char *init(ctg_utils_t *maindt)
{
        tg_json_getupdates_t *data = malloc(sizeof(tg_json_getupdates_t) * 9999);;
        pthread_t threads;
        signal(SIGINT, sig_callback);
        for(;;) {

                data = get_updates(maindt, data, 730076242,1);

                // create thread
                
                int rc = pthread_create(&threads, NULL, handle_update, data);

                // DEBUGW("data->update_id is %d\n", data->update_id);
                
                // DEBUGW("data->message.message_id is %d\n", data->message.message_id);
                // DEBUGW("data->message.date is %lu\n", data->message.date);
                // DEBUGW("data->message.text is %s\n", data->message.text);

                // DEBUGW("data->message->from.id is %lu\n", data->message.from.id);
                // DEBUGW("data->message->from.is_bot is %s\n", (data->message.from.is_bot) ? "true" : "false");
                // DEBUGW("data->message->from.first_name is %s\n", data->message.from.first_name);
                // DEBUGW("data->message->from.last_name is %s\n", data->message.from.last_name);
                // DEBUGW("data->message->from.username is %s\n", data->message.from.username);
                // DEBUGW("data->message->from.language_code is %s\n", data->message.from.language_code);

                // DEBUGW("data->message->chat.id is %lu\n", data->message.chat.id);
                // DEBUGW("data->message->chat.first_name is %s\n", data->message.chat.first_name);
                // DEBUGW("data->message->chat.last_name is %s\n", data->message.chat.last_name);
                // DEBUGW("data->message->chat.username is %s\n", data->message.chat.username);
                // DEBUGW("data->message->chat.type is %s\n", data->message.chat.type);

                if(want_exit == 1) {
                        DEBUGP("exiting ... ");
                        free(data);
                        exit(0);
                }
        }
        //free(data);
        return "";

}

