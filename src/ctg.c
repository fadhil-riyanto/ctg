// SPDX-License-Identifier: GPL-2.0

/*
 *  ctg.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <stdio.h>
#include <stdlib.h>
#include "curl_fn.h"
#include "curl_obj.h"

void somefn()
{
        chdata_t *ks;
        ks = ch_init();
        curl_req(ks);


}