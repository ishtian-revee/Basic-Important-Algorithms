#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
# include <windows.h>
#define sleep(x) Sleep(1000 * x)

void *func(void *var);

int main(int argc, char *argv){

    pthread_t thread1, thread2;
    char *msg1 = "First Message";
    char *msg2 = "Second Message";
    int return1, return2;

    // creating 2 threads
    return1 = pthread_create(&thread1, NULL, func, (void *) msg1);
    return2 = pthread_create(&thread2, NULL, func, (void *) msg2);

    printf("\nMain function after pthread_create(): \n\n");

    // joining with the first or main thread which is main()
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("First thread return 1: %d\n", return1);
    printf("Second thread return 2: %d\n", return2);

    return 0;
}

void *func(void *var){

    char *msg;
    // casting because message strings are in char * in main()
    msg = (char *) var;

    int i;
    for(i=0; i<10; i++){

        printf("%s %d\n", msg, i);
        sleep(1);   // sleep for 1 second
    }

    return NULL;
}
