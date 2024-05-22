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
   printf("������� \n");

    int n;

    printf("������ ������� �������� ������: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("����� ������� ��� ������������� ������.\n");
        return 1;
    }


    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("������� �������� ���'��.\n");
        return 1;
    }

    printf("������ �������� ������:\n");
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
        printf("����� ������ �� ��������: ������ ���� ��� ������ �������� � �����.\n");
        free(arr);
        return 1;
    }

    swap(&arr[maxEven], &arr[lastOdd]);

    printf("����� ���� �����:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    }
    {
   printf("��������� \n");
    int n;


    printf("������ ������� �������� ������: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("����� ������� ��� ������������� ������.\n");
        return 1;
    }


    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("������� �������� ���'��.\n");
        return 1;
    }

    printf("������ �������� ������:\n");
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
        printf("����� ������ �� ��������: ������ ���� ��� ������ �������� � �����.\n");
        free(arr);
        return 1;
    }

    swap(maxEven, lastOdd);

    printf("����� ���� �����:\n");
    for (int *p = arr; p < arr + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    free(arr);
    }
    return 0;
}
