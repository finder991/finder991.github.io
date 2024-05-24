#include <stdio.h>
#include <stdarg.h>

double calculate(int count, ...) {
    va_list args;
    va_start(args, count);

    double sum = 0.0;
    for (int i = 1; i <= count / 2; i++) {
        double numerator = va_arg(args, double);
        double denominator = va_arg(args, double);
        sum += numerator / denominator;
    }

    va_end(args);
    return sum;
}

double calculate2(int count, ...) {
    va_list args;
    va_start(args, count);

    double sum = 0.0;
    for (int i = 1; i <= count / 2; i++) {
        double numerator = va_arg(args, double);
        double denominator = va_arg(args, double);
        sum += numerator / denominator;
    }

    va_end(args);
    return sum;
}
double calculate3(int count, ...) {
    va_list args;
    va_start(args, count);

    double sum = 0.0;
    for (int i = 0; i < count; i += 2) {
        double numerator = va_arg(args, double);
        double denominator = va_arg(args, double);
        sum += numerator / denominator;
    }

    va_end(args);
    return sum;
}


int main() {
    system("chcp 1251");
    {
    printf("Завдання 1: \n");
    double result1 = calculate(4, 2.0, 1.0, 4.0, 3.0);
    double result2 = calculate(6, 2.0, 1.0, 4.0, 3.0, 6.0, 5.0);
    double result3 = calculate(8, 2.0, 1.0, 4.0, 3.0, 6.0, 5.0, 8.0, 7.0);


    printf("Результат 1: %f\n", result1);
    printf("Результат 2: %f\n", result2);
    printf("Результат 3: %f\n", result3);

       printf("Завдання 2: \n");
    }
    {
    double (*calc_ptr)(int, ...) = &calculate2;

    double result1 = calc_ptr(4, 2.0, 1.0, 4.0, 3.0);
    double result2 = calc_ptr(6, 2.0, 1.0, 4.0, 3.0, 6.0, 5.0);
    double result3 = calc_ptr(8, 2.0, 1.0, 4.0, 3.0, 6.0, 5.0, 8.0, 7.0);

    printf("Результат 1: %f\n", result1);
    printf("Результат 2: %f\n", result2);
    printf("Результат 3: %f\n", result3);

    printf("Завдання 3: \n");

    }
    {
 {
    double result = calculate3(8, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
    printf("Результат: %f\n", result);
}
    }
    return 0;
}
