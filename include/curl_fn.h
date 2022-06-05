// SPDX-License-Identifier: GPL-2.0

/*
 *  curl_obj.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <stddef.h>

void curl_req(char *url);
static size_t curl_cb(void *contents, size_t size, size_t nmemb, void *userp);
