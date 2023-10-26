#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    int age;
    double salary;
};

void inputEmployees(struct Employee employees[], int n) {
    printf("Enter the details of %d employees:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Age: ");
        scanf("%d", &employees[i].age);
        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
    }
}

void displayEmployees(struct Employee employees[], int n) {
    printf("Employee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", employees[i].id);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2lf\n", employees[i].salary);
    }
}

double averageSalary(struct Employee employees[], int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += employees[i].salary;
    }
    return result/n;
}

void youngestEmployee(struct Employee employees[], int n) {
    struct Employee minAge[1] = {employees[0]};
    for (int i = 0; i < n; i++) {
        if (employees[i].age < minAge[0].age) minAge[0] = employees[i];
    }

    printf("Youngest Employee:\n");
    printf("ID: %d\n", minAge[0].id);
    printf("Age: %d\n", minAge[0].age);
    printf("Salary: %.2lf\n", minAge[0].salary);
}

int salaryInRange(struct Employee employees[], int n, double minSalary, double maxSalary) {
    int inRange = 0;
    for (int i = 0; i < n; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) inRange++;
    }
    return inRange;
}

void salaryRaise(struct Employee employees[], int n, double increase) {
    for (int i = 0; i < n; i++) {
        employees[i].salary *= (1+increase);
    }
}
