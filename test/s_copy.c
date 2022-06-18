#include <stdio.h>
#include <string.h>


struct nama {
        int umur;
        char *nama;
};

// struct inicopy {
//         char *nama;
// };

int main() 
{
        struct nama nm;
        struct nama nm2;
        nm.umur = 9;
        nm.nama = "fadhil";

        nm2 = nm;
        // struct inicopy iic;
        // memcpy(&nm, &iic, sizeof(nm));

        printf("%d", nm2.umur);
}