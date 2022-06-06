// SPDX-License-Identifier: GPL-2.0

/*
 *  fetcher.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

/* we use pool btw */

/* 
 * the algorithm looks this
 * we use infinite loop, with delay 1 sec
 * then, i checking to api, weth offset the last id
 * last id is 0
 * after checking, we will get real last id
 * we use the last id for request again
 * after that, the json response will used for handle triggers
 */

#include <json-c/json.h>
#include "fetchres.h"
/* #include "curl_fn.h" */
#include "curl_obj.h"

