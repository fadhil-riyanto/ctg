#include <stdio.h>
#include <json-c/json.h>

int main()
{
        char *json = "{\"chat_id\":-66666666666666666}";
        json_object *raw = json_tokener_parse(json);
        json_object *chid_raw = json_object_object_get(raw, "chat_id");

        long long chat_id = json_object_get_int64(chid_raw);
        printf("%lld\n", (long long)chat_id); // 0 in my machine

        // test assign u_int64_t
        u_int64_t test_assign = -1001410961692;
        printf("%lld", (long long)test_assign); // just test

        json_object_put(raw);
}