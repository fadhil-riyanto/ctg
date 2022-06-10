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
#include "ctg.h"
#include "curl_obj.h"
#include "tg_method.h"


char *init(ctg_utils_t *maindt)
{
        get_updates(maindt, 0,1);
        return "okok";

}