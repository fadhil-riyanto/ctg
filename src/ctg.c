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
#include <string.h>

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
        struct pthread_args_addition paag_thread_copy;
        paag_thread_copy = *paag;

        // handle acces revc_data after ctrl + c
        if(want_exit == 1) {
                printf("%s\n", "exiting sub thread ... ");
                pthread_exit(NULL);
        }else {
                if(paag_thread_copy.recv_data->update_id != NULL) {
                        char buff[4096];
                        printf("[RECEIVED]  @%s wrote %s\n", \
                                paag_thread_copy.recv_data->message.from.username, \
                                paag_thread_copy.recv_data->message.text);
                        // sprintf(buff, "set_name %s", paag_thread_copy.recv_data->message.sticker.set_name);
                        // send_message(paag_thread_copy.maindt, paag_thread_copy.recv_data->message.chat.id, paag_thread_copy.recv_data->message.message_id, buff, "html", false);

                }
                pthread_exit(NULL);
        }
        
}

char *init(ctg_utils_t *maindt)
{
        static volatile int pthread_counter = 0;
        void *thread_status;
        int thread_status_join;
        unsigned long int update_id = 0;
        pthread_t thread_alloc[maindt->thread];
        struct pthread_args_addition paag;

        tg_json_getupdates_t *data = malloc(sizeof(tg_json_getupdates_t));
        paag.maindt = maindt;
        
        signal(SIGINT, sig_callback);

        for(;;) {
                if(want_exit == 1) {
                        printf("%s\n", "exiting main thread ... ");
                        free(data);
                        for(int ii = 0; ii < pthread_counter; ii++) {
                                pthread_join(thread_alloc[ii], NULL);
                                printf("thread %d has been joined\n", ii);
                        }
                        
                        curl_global_cleanup();
                        exit(0);
                } else {
                        if(pthread_counter > maindt->thread) {
                                printf("%s", "joining old thread");
                                for(int pp = 0; pp < maindt->thread; pp++) {
                                        thread_status_join = pthread_join(thread_alloc[pp], &thread_status);
                                        if(thread_status_join) {
                                                printf("error, pthread_join %d return code %d\n", pp, thread_status_join);
                                                printf("%s\n", "exiting main thread ... ");
                                                free(data);
                                                curl_global_cleanup();
                                                exit(-1);
                                        } else {
                                                printf("thread %d resetted!\n", pp);
                                        }
                                }
                                pthread_counter = 0;

                        }
                        data = get_updates(maindt, data, update_id, 1);
                        update_id = data->update_id + 1;
                        paag.recv_data = data;

                        
                        //printf("val :%d\n", data->message.entities[0].offset);

                        pthread_create(&thread_alloc[pthread_counter], NULL, (void*) handle_update, &paag);
                        pthread_counter += 1;
                }
        }
        return "";
}

