#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double lab20_v19_z1_a(double,double);
void lab20_v19_z1_c(double,double*,double*,double*,double*,double*,double*);

int main(){
system("chcp 1251");
{


    double a, b, result;
        printf("Завдання а\nВведіть значення a: ");
        scanf("%lf", &a);
        printf("Введіть значення b: ");
        scanf("%lf", &b);
lab20_v19_z1_a(a,b);
double res=lab20_v19_z1_a(a,b);
printf("Результат завдання a_a: %lf\n",res);
    }
    {
 double a,a2,a4,a5,a10,a20,a21;
    printf("завдання a_c\n");
    printf("Введіть a ");
    scanf("%lf",&a);

    lab20_v19_z1_c(a,&a2,&a4,&a5,&a10,&a20,&a21);
    printf("Результат завдання a_c:\n");
    printf("a2=%-lf\n",a2);
    printf("a4=%-lf\n",a4);
    printf("a5=%-lf\n",a5);
    printf("a10=%-lf\n",a10);
    printf("a20=%-lf\n",a20);
    printf("a21=%-lf\n",a21);

    }
    {
        int n;

    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Масив порожній або неправильного розміру.\n");
        return 1;
    }

    int arr[n];

    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = processArray(arr, n);
    if (result == 1) {
        return 1;
    }

    printf("Масив після заміни:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    }
       return 0;
}


double lab20_v19_z1_a(double a,double b)
{
return ((2*b-3+6.8*a)/(pow(a, 3)+b+1))-((2*pow(b, 3))/(pow(a, 2)+pow(a, 4)+5.7));
}
void lab20_v19_z1_c(double a,double*a2,double*a4,double*a5,double*a10,double*a20,double*a21)
{

    *a2=a*a;
    *a4=*a2**a2;
    *a5=*a4*a;
    *a10=*a5**a5;
    *a20=*a10**a10;
    *a21=*a20*a;

}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int processArray(int arr[], int n) {
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
        return 1;
    }

    swap(&arr[maxEven], &arr[lastOdd]);

    return 0;
}

