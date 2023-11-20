#include <stdio.h>
#include <stdlib.h>
#define ROWS 100
#define COLS 100
#include <locale.h>

void fillArray(int arr[][COLS], int rows, int cols) {
    int i, j;
    int choice;

    printf("Вы хотите заполнить массив случайными значениями? (1-нет/2-да): ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        printf("Введите %d x %d элементов массива:\n", rows, cols);
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                printf("arr[%d][%d]: ", i, j);
                scanf_s("%d", &arr[i][j]);
            }
        }
    }
    else if (choice == 2) {
        srand(time(0));
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                arr[i][j] = rand() % 100;
            }
        }
    }
    else {
        printf("Неверный выбор!\n");
    }
}
int main() {
    setlocale(LC_ALL, "Rus");
    int arr[ROWS][COLS];
    int rows, cols;

    printf("Введите количество строк: ");
    scanf_s("%d", &rows);

    printf("Введите количество столбцов: ");
    scanf_s("%d", &cols);

    fillArray(arr, rows, cols);

    printf("\nМассив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int column_sums[COLS];
    for (int j = 0; j < cols; j++) {
        column_sums[j] = 0;
        for (int i = 0; i < rows; i++) {
            if (arr[i][j] < 0 && arr[i][j] % 2 != 0) {
                column_sums[j] += abs(arr[i][j]);
            }
        }
    }

    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (column_sums[j] > column_sums[j + 1]) {
                for (int k = 0; k < rows; k++) {
                    int temp = arr[k][j];
                    arr[k][j] = arr[k][j + 1];
                    arr[k][j + 1] = temp;
                }
                int temp_sum = column_sums[j];
                column_sums[j] = column_sums[j + 1];
                column_sums[j + 1] = temp_sum;
            }
        }
    }
    
        int sum = 0;
        printf("Столбцы в порядке роста характеристик:\n");
        for (int j = 0; j < cols; j++) {
            printf("Столбец %d: ", j + 1);
            for (int i = 0; i < rows; i++) {
                printf("%d ", arr[i][j]);
                if (arr[i][j] < 0) {
                    sum += arr[i][j];
                }
            }
            printf("\n");
            if (sum < 0) {
                printf("Сумма элементов в столбце %d: %d\n", j + 1, sum);
            }
        }
   

    return 0;
}