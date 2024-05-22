#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    system("chcp 1251");
    int n;

    printf("������ ������� �������� ������: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("����� ������� ��� ������������� ������.\n");
        return 1;
    }

    int arr[n];

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
        return 1;
    }
    swap(maxEven, lastOdd);

     printf("����� ���� �����:\n");
    for (int *p = arr; p < arr + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}
