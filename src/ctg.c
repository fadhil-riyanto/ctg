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
#include "ctg.h"
#include "curl_obj.h"
#include "tg_method.h"
#include  <signal.h>
#include "debug_fn.h"
#include <stdbool.h>
#include <inttypes.h>

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
                        char buff[4096];
                        printf("%lld", (long long)paag->recv_data->message.chat.id);
                        //printf("%" PRIu64 "\n", paag->recv_data->message.chat.id);
                        printf("[RECEIVED]  @%s wrote %s\n", paag->recv_data->message.from.username, paag->recv_data->message.text);
                        // printf("exec send message");
                        sprintf(buff, "set_name %s", paag->recv_data->message.sticker.set_name);
                        send_message(paag->maindt, paag->recv_data->message.chat.id, paag->recv_data->message.message_id, buff, "html", false);

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
                        curl_global_cleanup();
                        exit(0);
                } else {
                        data = get_updates(maindt, data, update_id, 1);
                        update_id = data->update_id + 1;
                        paag.recv_data = data;

                        //printf("val :%d\n", data->message.entities[0].offset);

                        pthread_create(&threads, NULL, (void*) handle_update, &paag);
                }
        }
        return "";
}

