#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int message_count = 1000;
    int sleep_duration = 10;

    pid_t pid = getpid();

    for (int i = 1; i <= message_count; i++) {
        printf("%d-%d\n", pid, i);
        fflush(stdout);
        sleep(sleep_duration);
    }

    return 0;
}
