#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>
#include <pthread.h>

/*
 sudo nice -n <nice> <command>  Run with some nice
 sudo renice -n <nice> -p <pid>  Change nice of running cmd
*/

int main()
{
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    int nicity = nice(-20);

    for (int i = 0; i < 10000; ++i)
    {
        printf("PID:  %d\nTID:  %p\nNice: %d\n\n", pid, (void *)tid, nicity);
        sleep(1);
    }
}
