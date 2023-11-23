#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int main()
{
    pid_t pid = getpid();
    pthread_t tid = pthread_self();

    for (int i = 0; i < 1000000; ++i)
    {
        printf("PID: %d\nTID: %lu\n\n", pid, (unsigned long)tid);
        sleep(1);
    }

    return 0;
}
