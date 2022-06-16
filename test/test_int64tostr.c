#include <stdio.h>
#include <sys/types.h>
#include <inttypes.h>


void i64toa(char *buf, u_int64_t data) 
{
        sprintf(buf, "%" PRId64, data);
}

int main()
{
        int64_t test = -1001410961692;
        char buffer[100];
        i64toa(buffer, test);
        
        printf("%s", buffer);
}