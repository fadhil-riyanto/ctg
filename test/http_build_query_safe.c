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
                return NULL; // maybe no memory
        }

        for(i = 0; i < len_arr; i++) {
                size_t key_len, val_len;

                key_len = strlen(data[i].key);
                val_len = strlen(data[i].value);

                need_len += (key_len * 3) + (val_len * 3) + 3;
                if(alloc <= need_len) {
                        alloc += (alloc * 2) + need_len;
                        tmp = realloc(buffer, alloc);
                        if(!tmp) {
                                free(buffer);
                                return NULL;
                        }
                        buffer = tmp; // paste new memory
                }

                urlencode(&buffer[total], data[i].key, key_len, false);
                // encode the key first
                total += strlen(&buffer[total]); 
                // get offset
                buffer[total++] = '='; // increment 1 of last offset
                urlencode(&buffer[total], data[i].value, val_len, false);

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

#include <limits.h>
#define INT_DECIMAL_STRING_SIZE(int_type) ((CHAR_BIT*sizeof(int_type)-1)*10/33+3)

char *int_to_string_alloc(int x) {
  int i = x;
  char buf[INT_DECIMAL_STRING_SIZE(int)];
  char *p = &buf[sizeof buf] - 1;
  *p = '\0';
  if (i >= 0) {
    i = -i;
  }
  do {
    p--;
    *p = (char) ('0' - i % 10);
    i /= 10;
  } while (i);
  if (x < 0) {
    p--;
    *p = '-';
  }
  size_t len = (size_t) (&buf[sizeof buf] - p);
  char *s = malloc(len);
  if (s) {
    memcpy(s, p, len);
  }
  return s;
}

int main() 
{
       
        key_value_t data[2];
        char *string, *returnstr;
        char *test = int_to_string_alloc(8);

        char buff[5000];

        // convert to string
        char *offset_str = int_to_string_alloc(922892);
        char *limit_str = int_to_string_alloc(1);

        insert_key_value(data, "offset", offset_str); 
	insert_key_value(data, "limit", limit_str);

        returnstr = http_build_query(data, 2);

        sprintf(buff, "https://api.telegram.org/bot%s/%s?%s", "tokenenenenen", "getUpdates", returnstr);
        printf("%s", buff);
        free(returnstr);

}