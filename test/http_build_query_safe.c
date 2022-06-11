#include <assert.h>
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
} key_value_t;
int countinsert;

void insert_key_value(key_value_t *keyval, char *key, char *value)
{
        keyval[countinsert].key = key;
        keyval[countinsert].value = value;

        countinsert += 1;
}

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

char *http_build_query(key_value_t *data, size_t len_arr)
{
        // char *buffresd = (char*) malloc(sizeof(char) * 4094);
	// char *urlencodedata_key = (char*) malloc(sizeof(char) * 4094);
	// char *urlencodedata_value = (char*) malloc(sizeof(char) * 4094);
        // buffresd[0] = '\0';
	// char temp[300];
	// char *data;
	// data = temp;
        // for(int a = 0; a < len_arr; a++) {
	// 	urlencode(urlencodedata_key, data_arr_keyval[a].key, strlen(data_arr_keyval[a].key), false);
	// 	urlencode(urlencodedata_value, data_arr_keyval[a].value, strlen(data_arr_keyval[a].value), false);
	// 	if (a == (len_arr - 1)) {
	// 		sprintf(data, "%s=%s", urlencodedata_key, urlencodedata_value);
	// 		strcat(buffresd , data);
	// 	} else {
	// 		sprintf(data, "%s=%s&", urlencodedata_key, urlencodedata_value);
	// 		strcat(buffresd , data);
	//  	}
        // }
	// free(urlencodedata_key);
	// free(urlencodedata_value);
        // return buffresd;
        char *buffer, *tmp;
        size_t alloc = 4096;
        size_t total = 0;
        size_t need_len = 0;
        size_t i;

        buffer = malloc(alloc);
        if(!buffer) {
                return NULL;
        }

        for(i = 0; i < len_arr; i++) {
                size_t keylen, vallen;

                keylen = strlen(data[i].key);
                vallen = strlen(data[i].key);

                need_len += (keylen * 3) + (vallen * 3) + 3;
                if(alloc <= need_len) {
                        alloc = (alloc * 2) + need_len;
                        tmp = realloc(buffer, alloc);
                        if(!tmp) {
                                free(buffer);
                                return NULL;
                        }
                        buffer = tmp; // paste new memory
                }

                urlencode(&buffer[total], data[i].key, keylen, false);
                // encode the key first
                total += strlen(&buffer[total]); 
                // get offset
                buffer[total++] = '='; // increment 1 of last offset
                urlencode(&buffer[total], data[i].value, vallen, false);

                total += strlen(&buffer[total]);
                // get the last offset
                // check if the literation now < of arr len, - 1 means make 
                // array len same as array alloc. started from 0
                if (i < len_arr - 1)
			buffer[total++] = '&';
                
        }
        buffer[total] = '\0'; // add termination string
        return buffer;
}

int main() 
{
       
        key_value_t data[2];
        char *string, *returnstr;
        size_t i;
        size_t len = 1024UL * 5;

        insert_key_value(data, "keytest", "valtest");
        insert_key_value(data, "keytest1", "valtest1");

        returnstr = http_build_query(data, 2);
        printf("%s", returnstr);
        free(returnstr);

}