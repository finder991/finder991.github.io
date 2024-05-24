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
    printf("������ ������� ����������: ");
    scanf("%d", &n);

    struct Salary *employees = (struct Salary *)malloc(n * sizeof(struct Salary));


    for (int i = 0; i < n; i++) {
        printf("\n������ ��� ��� ���������� %d:\n", i + 1);
        printf("�������, ��'�, ��-�������: ");
        getchar(); // ������� ������
        fgets(employees[i].fullName, sizeof(employees[i].fullName), stdin);
        printf("ʳ������ �����, ������������� �� �����: ");
        scanf("%d", &employees[i].hoursWorked);
        printf("����� �� ������ ������: ");
        scanf("%lf", &employees[i].hourlyRate);
    }


    printf("\n̳����� �������� ��� ������� ����������:\n");
    for (int i = 0; i < n; i++) {
        double monthlySalary = calculateMonthlySalary(employees[i]);
        printf("%s - %.2lf ���\n", employees[i].fullName, monthlySalary);
    }

    double maxSalary = 0;
    printf("\n������� ���������� � ������������ ������� ���������:\n");
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
            break; // �������� ����� ����� �������
        }
    }

    free(employees);

    return 0;
}
