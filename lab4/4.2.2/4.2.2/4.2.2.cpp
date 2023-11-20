#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ROWS 100
#define COLS 100

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
void negateMatrix(int arr[][COLS], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            arr[i][j] = -arr[i][j];
        }
    }
}
int hasPositiveElements(int arr[][COLS], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        int hasPositive = 0; 
        for (j = 0; j < cols; j++) {
            if (arr[i][j] > 0) {
                hasPositive = 1;
                break;
            }
        }
        if (!hasPositive) {
            return 0; 
        }
    }

    return 1; 
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
    if (hasPositiveElements(arr, rows, cols)) {
        printf("Все строки матрицы содержат хотя бы один положительный элемент.\n");
        negateMatrix(arr, rows, cols);
        printf("Матрица после изменения знаков всех элементов на обратные:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Не все строки матрицы содержат хотя бы один положительный элемент.\n");
    }

    return 0;
}