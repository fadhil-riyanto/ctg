// SPDX-License-Identifier: GPL-2.0

/*
 *  tostring.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tostring(int interger)
{
        // count the digits
        int real_num = interger;
        int count = 0;
        do {
                interger /= 10;
                ++count;
        } while (interger != 0);

        char *str_ret = (char *)malloc((sizeof(char) * count) + sizeof(char)); 
        str_ret[(sizeof(char) * count)  + 1] = '\0';
        // add 1 char for termination chars

        sprintf(str_ret, "%d", real_num);
        return str_ret;
}

int main()
{
        char *data = tostring(888);
        printf(data);
        free(data);

}