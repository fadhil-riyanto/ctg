#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* delete_index1(char *string) {

        
        int last_offset = 0, looplen = 0, total_split_len = 0; 
        char *alive_string = malloc(sizeof(char) * strlen(string));

        char ress[strlen(string) + 1];

        int literate = 0;
        int literatechar = 0;
        for (int i = 0; i < strlen(string); i++) {
                if (string[i] == ' ') {
                        if (literate == 0) {
                                char tempchar[strlen(string)];
                                char *rawcstring = string;
                                int cint_count_string = 0;
                                for(; *rawcstring; *rawcstring++) {
                                        tempchar[cint_count_string] = *rawcstring;
                                        cint_count_string += 1;
                                }
                                tempchar[cint_count_string] = '\0';
                                for(int a = 0; a <= strlen(string); a++) {
                                        tempchar[a] = tempchar[ ( a + 1) + i];
                                }
                                strcpy(alive_string, tempchar);
                                return alive_string;
                        }
                        literate += 1;
                } 
                literatechar += 1;
        }
        if (literatechar == strlen(string)) {
                if (literate == 0) {
                        strcpy(alive_string, string);
                        return alive_string;
                }
                
        }
}

char* split(char *string, char del, int offset, int *len_all, bool get_len) {
        int last_offset = 0, looplen = 0, total_split_len = 0; 
        char *init = "";
        int len = strlen(init);
        char *temp = malloc(sizeof(char) * strlen(string));
        strcpy(temp, init);
        char ress[strlen(string) + 1];
        for (int i = 0; i < strlen(string); i++) {
                if (string[i] == del) {
                        for (int a = last_offset; a < i; a++) {
                                if (string[a] == del) {
                                        total_split_len += 1;
                                } else {
                                        temp[len] = string[a];
                                        len += 1;
                                }
                        }
                        temp[len] = '\0';
                        if (get_len != true) {
                                if (looplen == offset) {
                                        *len_all = looplen;
                                        return temp;
                                } 
                        }
                        for(int rr = 0; rr < strlen(string); rr++) {
                                temp[rr] = 0;
                        }
                        len = 0;
                        looplen += 1;
                        last_offset = i;
                }
        }
        for (int i = last_offset; i < strlen(string); i++) {
                if (string[i] != '\0' && string[i] != del) {
                        temp[len] = string[i];
                        len += 1;
                }
        }
        temp[len] = '\0';

        len = 0;
        *len_all = looplen;
        looplen += 1;
        
        return temp;
}

// different context
typedef struct {
        char *command;
        char *content;
} parse_command_res_t;

void parse(char *botusername, char *raw, parse_command_res_t *retparse)
{
        
        char rawchar[strlen(raw)];
        char *rawc = raw;
        bool bot_own;

        int cint_count = 0;
        for(; *raw; *raw++) {
                rawchar[cint_count] = *raw;
                cint_count += 1;
        }
        rawchar[cint_count] = '\0';
        if(rawchar[0] == '/') {
                printf("%s\n", "is command");
                int total;
                printf("data > \"%s\"\n", rawc);
                char *datasplit = split(rawc, ' ', 0, &total, false);
                printf("data > %s\n", datasplit);
                free(split(datasplit, '@', 0, &total, true));
                
                char *bot_username_command = split(datasplit, '@', 1, &total, true);
                
                if (total >= 1 && (strcmp(botusername, bot_username_command) == 0)) {
                        bot_own = true;
                } else {
                        bot_own = false;
                }
                //printf("bool > %s\n", bot_own ? "true" : "false");
                

                if (bot_own == true) { 
                        // get content
                        char *rescrop = delete_index1(rawc);
                        printf("raw: %s\n", rawc);
                        retparse->content = rescrop;

                        // get command
                        char *commandbot = split(datasplit, '@', 0, &total, false);

                        // convert to char[]
                        char tempchar[strlen(commandbot)];
                        char *rawcstring = commandbot;
                        int cint_count_string = 0;
                        for(; *rawcstring; *rawcstring++) {
                                tempchar[cint_count_string] = *rawcstring;
                                cint_count_string += 1;
                        }
                        tempchar[cint_count_string] = '\0';


                        // delete slash
                        char data[strlen(commandbot)];
                        for(int i = 0; i <= strlen(data); i++) {
                                data[i] = tempchar[i+1];
                        }

                        char *alive_command = malloc(sizeof(char) * strlen(commandbot) - 1);
                        strcpy(alive_command, data);
                        retparse->command = alive_command;
                        // free(rescrop);
                        free(commandbot);
                        // free(alive_command);

                }
                free(datasplit);
                free(bot_username_command);
                


                
                // printf("%s\n", bot_username_command);
                // printf("%s\n", botusername);
                // printf("%d", strcmp(botusername, bot_username_command));
                // if (total == 1 && strcmp(bot_username_command, bot_username_command)) {
                //         bot_own = true;
                // }
                // printf("%s", strcmp(botusername, bot_username_command) ? "true" : "false");
                // free(split(raw, ' ', 0, &total, true));
                // for (int i = 0; i < total; i++) {
                //         split(raw, ' ', i, &total, false);
                // }
        }

        // int total;
        // free(split(raw, ' ', 5, &total, true));

        // for (int i = 0; i < total; i++) {

        // }
        

}

void parse_cleanup(parse_command_res_t *retparse) 
{
        free(retparse->command);
        free(retparse->content);
}

int main() 
{

        parse_command_res_t rawres;
        char *command = "/test@fadhil_riyanto_bot";
        parse("fadhil_riyanto_bot", command, &rawres);

        printf("content : %s\n", rawres.content);
        printf("command : %s\n", rawres.command);
        parse_cleanup(&rawres);
}
