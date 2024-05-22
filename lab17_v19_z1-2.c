#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    system("chcp 1251");
    {


    int n;


    printf("������ ������� �������� ������: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("����� ������� ��� ������������� ������.\n");
        return 1;
    }

    int arr[n];

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
        return 1;
    }


    swap(&arr[maxEven], &arr[lastOdd]);


    printf("����� ���� �����:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    }
    {
            int n;

    printf("������ ����� ������� (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("������������ ����� �������.\n");
        return 1;
    }

    int matrix[n][n];

    printf("������ �������� �������:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int countPositive = 0;


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
                countPositive++;
            }
        }
    }

    printf("ʳ������ �������� �������� ��� �������� ���������: %d\n", countPositive);

    }
    return 0;
}
