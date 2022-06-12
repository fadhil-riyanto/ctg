
#include <stdio.h>
void pppp()
{
        char data[100];
        sprintf(data, "%s", "12");
        printf("%d", sizeof(data));
}

int main()
{
        pppp();
        pppp();
}