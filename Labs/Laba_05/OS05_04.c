#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <pthread.h>

int main()
{
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    size_t thread_id_size = sizeof(thread_id);
    int nicity = nice(0);
    
    printf("PID = %d\n", pid);

    // Get the thread ID using sysctl
    if (sysctlbyname("sysctl.proc_selfthreadid", &thread_id, &thread_id_size, NULL, 0) != -1)
    {
        printf("TID = %d\n", tid);
    }
    else
    {
        printf("[ERROR]: Failed to retrieve thread ID.\n");
    }

    printf("Nice = %d\n", nicity);

    int num_cpus;
    size_t num_cpus_size = sizeof(num_cpus);
    
    // Get the number of available CPUs using sysctl
    if (sysctl((int[]){CTL_HW, HW_AVAILCPU}, 2, &num_cpus, &num_cpus_size, NULL, 0) != -1)
    {
        printf("Total number of CPUs: %d\n", num_cpus);
    }
    else
    {
        printf("[ERROR]: Failed to retrieve the number of CPUs.\n");
    }

    exit(0);
}
