#include <stdio.h>
#include <math.h>
#include <string.h>

int remove_second_and_last_digit(int n) {
    char str[20];
    sprintf(str, "%d", n);
    int len = strlen(str);

    if (len < 2) {

        return -1;
    }

    char result[20];
    int j = 0;

    for (int i = 0; i < len; ++i) {
        if (i != 1 && i != len - 1) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    return atoi(result);
}
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
double next_u(double u_prev, double u_prev_prev, double v_prev_prev) {
    return (u_prev + u_prev_prev * v_prev_prev) / (1 + u_prev_prev * u_prev_prev + v_prev_prev);
}

// ������� ��� ���������� ���������� ����� ����������� v
double next_v(double v_prev, double u_prev_prev, double v_prev_prev) {
    return (v_prev - 1) / (u_prev_prev + v_prev_prev * v_prev_prev);
}



double series_sum(int n, double x) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (factorial(2 * i) * pow(x, 2 * i));
    }
    return sum;
}
int main() {

    system("chcp 1251");
    {


    int n;
    printf("������ ���������� �����: ");
    scanf("%d", &n);

    int b = remove_second_and_last_digit(n);
    if (b == -1) {
        printf("����� ����� ������� ��� �������.\n");
        return 1;
    }

    double sqrt_b = sqrt((double)b);
    printf("����� � ����� %d ���� ��������� ����� �� �������� �����: %.2f\n", b, sqrt_b);
    }
    {
    int n;
    double x;


    printf("������ ���������� ����� n: ");
    scanf("%d", &n);
    printf("������ ����� ����� x: ");
    scanf("%lf", &x);


    printf("���� ����: %.10f\n", series_sum(n, x));

    }
    {
   int n;
    double u[100], v[100]; // ������ ��� ��������� ����� �������������

    // �������� ���������� ����
    printf("������ �������� u1: ");
    scanf("%lf", &u[1]);
    printf("������ �������� u2: ");
    scanf("%lf", &u[2]);
    printf("������ �������� v1: ");
    scanf("%lf", &v[1]);
    printf("������ �������� v2: ");
    scanf("%lf", &v[2]);

    // �������� �������� n
    printf("������ ���������� ����� n (>3): ");
    scanf("%d", &n);

    // ���������� ����� �������������
    for(int i = 3; i <= n; i++) {
        u[i] = next_u(u[i-1], u[i-2], v[i-2]);
        v[i] = next_v(v[i-1], u[i-2], v[i-2]);
    }

    // ��������� ����������
    for(int i = 1; i <= n; i++) {
        printf("u[%d] = %f\n", i, u[i]);
        printf("v[%d] = %f\n", i, v[i]);
    }
    }
    return 0;
}
