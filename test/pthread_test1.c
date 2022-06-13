#include <pthread.h>
 #include <stdio.h>
 #define NUM_THREADS     5

typedef struct ppp {
        int a;
}ppp_t;

 void *PrintHello(void *threadid)
 {
        ppp_t 
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    pthread_exit(NULL);
 }

 int main (int argc, char *argv[])
 {
    
    int rc;
    long t;
    for(t=0; t<10; t++){
        pthread_t threads;
        printf("creating %d", t);
       rc = pthread_create(&threads, NULL, PrintHello, (void *)t);
       if (rc){
        
          exit(-1);
       }
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
 }