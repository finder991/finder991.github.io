#include <stdio.h>
#include <stdlib.h>


struct Salary {
    char fullName[100];
    int hoursWorked;
    double hourlyRate;
};

double calculateMonthlySalary(struct Salary employee) {
    return employee.hoursWorked * employee.hourlyRate;
}

int main() {
    system("chcp 1251");
    int n;
    printf("Введіть кількість працівників: ");
    scanf("%d", &n);

    struct Salary *employees = (struct Salary *)malloc(n * sizeof(struct Salary));


    for (int i = 0; i < n; i++) {
        printf("\nВведіть дані для працівника %d:\n", i + 1);
        printf("Прізвище, ім'я, по-батькові: ");
        getchar(); // очистка буфера
        fgets(employees[i].fullName, sizeof(employees[i].fullName), stdin);
        printf("Кількість годин, відпрацьованих за місяць: ");
        scanf("%d", &employees[i].hoursWorked);
        printf("Тариф за годину роботи: ");
        scanf("%lf", &employees[i].hourlyRate);
    }


    printf("\nМісячна зарплата для кожного працівника:\n");
    for (int i = 0; i < n; i++) {
        double monthlySalary = calculateMonthlySalary(employees[i]);
        printf("%s - %.2lf грн\n", employees[i].fullName, monthlySalary);
    }

    double maxSalary = 0;
    printf("\nПрізвища працівників з максимальною місячною зарплатою:\n");
    for (int i = 0; i < n; i++) {
        double monthlySalary = calculateMonthlySalary(employees[i]);
        if (monthlySalary > maxSalary) {
            maxSalary = monthlySalary;
        }
    }
    for (int i = 0; i < n; i++) {
        double monthlySalary = calculateMonthlySalary(employees[i]);
        if (monthlySalary == maxSalary) {
            printf("%s", employees[i].fullName);
            break; // виводимо тільки перше прізвище
        }
    }

    free(employees);

    return 0;
}
