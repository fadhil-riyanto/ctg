// SPDX-License-Identifier: GPL-2.0

/*  
 *  test file: http_build_query.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include "fcntl.h"
#include "limits.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "stdlib.h"
#include <string.h>

typedef struct key_val {
        char *key;
        char *value;
} key_val_t;

int countinsert = 0;
void insert_key_val(key_val_t *keyval, char *key, char *value)
{
        keyval[countinsert].key = key;
        keyval[countinsert].value = value;

        countinsert += 1;
}

// int main()
// {
//         key_val_t data[100];
//         char *buffer0;
//         char *buffer1;
//         int i;
        
        
//         // insert_key_val(data, "data 0", "key 0");
//         // insert_key_val(data, "data 1", "key 1");
//         fprintf(stdout, "%s %s\n", (char *)data[0].key, (char *)data[0].value);
//         // insert_key_val(data, "tes", "tes");
//         // insert_key_val(data, "tes1", "tes1");
//         // insert_key_val(data, "tes2", "tes2");

//         // fprintf(stdout, "%s", (char *)data[2].key);
//         fprintf(stdout, "%s", (char *)data[0].key);
// }
/*
 * sumber : https://github.com/php/php-src/blob/23961ef382e1005db6f8c08f3ecc0002839388a7/ext/standard/url.c#L459-L555
 */
char *urlencode(char *alloc, const char *s, size_t len, bool raw)
{
	static const unsigned char hexchars[] = "0123456789ABCDEF";
	register unsigned char c;
	unsigned char *to;
	unsigned char const *from, *end;
	char *start;

	from = (const unsigned char *)s;
	end = (const unsigned char *)s + len;

	if (alloc == NULL) {
		start = malloc((len * 3ul) + 1ul);
	} else {
		start = alloc;
	}

	to = (unsigned char *)start;

	while (from < end) {
		c = *from++;

		if (!raw && c == ' ') {
			*to++ = '+';
		} else if ((c < '0' && c != '-' && c != '.') ||
				(c < 'A' && c > '9') ||
				(c > 'Z' && c < 'a' && c != '_') ||
				(c > 'z' && (!raw || c != '~'))) {
			to[0] = '%';
			to[1] = hexchars[c >> 4];
			to[2] = hexchars[c & 15];
			to += 3;
		} else {
			*to++ = c;
		}
	}
	*to = '\0';

	return start;
}
const char *http_build_query(key_val_t *data_arr_keyval, size_t len_arr)
{
	
        char *buffresd = (char*) malloc(sizeof(char) * 4094);
	char *data;
        for(int a = 0; a < len_arr; a++) {
		if (a == (len_arr - 1)) {
			sprintf(data, "%s=%s", data_arr_keyval[a].key, data_arr_keyval[a].value);
			strcat(buffresd , data);
		} else {
			sprintf(data, "%s=%s&", data_arr_keyval[a].key, data_arr_keyval[a].value);
			strcat(buffresd , data);
		}
                //fprintf(stdout,  "%s=%s&", data_arr_keyval[a].key, data_arr_keyval[a].value);
		
		
        }
	printf(buffresd);

        return buffresd;
}

int main()
{
        key_val_t data[2];
        insert_key_val(data, "tes", "set");
	insert_key_val(data, "tes2", "set2");
	//insert_key_val(data, "tes2", "set2");
        //insert_key_val(data, "fa", "dhi");
	//printf("%d\n", sizeof(data) / sizeof(data[0]));
	http_build_query(data, sizeof(data) / sizeof(data[0]));
        //fprintf(stdout, "%s", http_build_query(data, sizeof(data) / sizeof(data[0])));
}