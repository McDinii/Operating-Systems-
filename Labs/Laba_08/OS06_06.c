#include <stdio.h>
#include <unistd.h>

int main() {
    // Длинный цикл
    for (int i = 0; i < 1000; ++i) {
	printf("Iteration %d\n", i);
        sleep(1);
    }
    return 0;
}
