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

int main() {
    setlocale(LC_ALL, "Rus");
    int arr[ROWS][COLS];
    int rows;
    int cols;
    int sum = 0;

    printf("Введите значение N:");
    scanf_s("%d", &rows);
    cols = rows;
    
    fillArray(arr, rows, cols);

    printf("\nМассив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    if (rows % 2 == 0)
    {
        for (int i = 0; i < rows/2; i++) {
            for (int j = cols/2; j < cols; j++) 
            {
                sum += arr[i][j];
            }
            
        }
    }
    else
    {
        for (int i = 0; i < rows-1; i++) {
            for (int j = 1; j < cols; j++)
            {
                sum += arr[i][j];
            }

        }
    }
    printf("Cумма второй области:\n");
    printf("%d", sum);
}