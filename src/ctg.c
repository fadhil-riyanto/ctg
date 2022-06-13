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
#include <stdbool.h>

static volatile int want_exit = 0;

struct pthread_args_addition {
        tg_json_getupdates_t    *recv_data;
        ctg_utils_t             *maindt;
};

void sig_callback()
{
        printf("SIGINT detected. please wait for exiting ..\n");
        want_exit = 1; // change status to 1
}

void *handle_update(struct pthread_args_addition *paag) 
{
        // handle acces revc_data after ctrl + c
        if(want_exit == 1) {
                printf("%s\n", "exiting sub thread ... ");
                pthread_exit(NULL);
        }else {
                if(paag->recv_data->update_id != NULL) {
                        send_message(paag->maindt, paag->recv_data->message.chat.id, "hello from ctg!!", "html", false);
                        printf("[RECEIVED]  @%s wrote %s\n", paag->recv_data->message.from.username, paag->recv_data->message.text);

                }
                pthread_exit(NULL);
        }
        
}

char *init(ctg_utils_t *maindt)
{
        tg_json_getupdates_t *data = malloc(sizeof(tg_json_getupdates_t));
        pthread_t threads;
        struct pthread_args_addition paag;
        paag.maindt = maindt;
        

        unsigned long int update_id = 0;
        signal(SIGINT, sig_callback);

        for(;;) {
                if(want_exit == 1) {
                        printf("%s\n", "exiting main thread ... ");
                        free(data);
                        pthread_join(threads, NULL);
                        exit(0);
                } else {
                        data = get_updates(maindt, data, update_id, 1);
                        update_id = data->update_id + 1;
                        paag.recv_data = data;

                        // create thread
                        
                        pthread_create(&threads, NULL, (void*) handle_update, &paag);
                }
                

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

                
        }
        //free(data);
        return "";

}

