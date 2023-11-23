#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARRAY_SIZE (256 * 1024 * 1024 / sizeof(int))    // 256 МБ памяти под int-массив

int main() {
    // Выделение памяти
    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));

    // Инициализация массива
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

    // Вывод адреса выделенной памяти
    printf("Адрес выделенной памяти: %p\n", array);

    // Приостановка выполнения на длительный интервал времени
    sleep(3600);

    // Освобождение памяти
    free(array);

    return 0;
}
