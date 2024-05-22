#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
  system("chcp 1251");

    {
   printf("Індекси \n");

    int n;

    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Масив порожній або неправильного розміру.\n");
        return 1;
    }


    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return 1;
    }

    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxEven = -1;
    int lastOdd = -1;
    int maxEvenValue = -2147483648;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            if (arr[i] >= maxEvenValue) {
                maxEvenValue = arr[i];
                maxEven = i;
            }
        } else {
            lastOdd = i;
        }
    }

    if (maxEven == -1 || lastOdd == -1) {
        printf("Умови задачі не визначені: відсутні парні або непарні елементи в масиві.\n");
        free(arr);
        return 1;
    }

    swap(&arr[maxEven], &arr[lastOdd]);

    printf("Масив після заміни:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    }
    {
   printf("Вказівники \n");
    int n;


    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Масив порожній або неправильного розміру.\n");
        return 1;
    }


    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return 1;
    }

    printf("Введіть елементи масиву:\n");
    for (int *p = arr; p < arr + n; p++) {
        scanf("%d", p);
    }

    int *maxEven = NULL;
    int *lastOdd = NULL;
    int maxEvenValue = -2147483648;

    for (int *p = arr; p < arr + n; p++) {
        if (*p % 2 == 0) {
            if (*p >= maxEvenValue) {
                maxEvenValue = *p;
                maxEven = p;
            }
        } else {
            lastOdd = p;
        }
    }

    if (maxEven == NULL || lastOdd == NULL) {
        printf("Умови задачі не визначені: відсутні парні або непарні елементи в масиві.\n");
        free(arr);
        return 1;
    }

    swap(maxEven, lastOdd);

    printf("Масив після заміни:\n");
    for (int *p = arr; p < arr + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    free(arr);
    }
    return 0;
}
