#include <stdio.h>
#include <pthread.h>


void *cb(int *a) {
        printf("hi im pthread %d\n", a);
}
int main() {
        pthread_t threads;

        for (int a = 0; a < 50; a++) {
                pthread_create(threads, NULL, (void*) cb, (int *)a);
        }
        while(1){}
}

