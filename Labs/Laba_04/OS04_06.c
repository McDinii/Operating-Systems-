#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

int main()
{
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    for (short i = 1; i <= 10000; ++i)
    {
        printf("%d. PID = %d      TID = %lu\n", i, pid, (unsigned long)tid);
        sleep(1);
    }
    exit(0);
}
