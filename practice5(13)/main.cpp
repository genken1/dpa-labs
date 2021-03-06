#include <iostream>
#define SIZE 8

// Тестовые данные для ввода:
// 23 12 0 0 0 0 0 25 0 22 0 0 35 18 0 0 0 0 0 20 0 0 23 14 0 24 0 16
int main() {
    int a[SIZE][SIZE]; // матрица связей
    int d[SIZE]; // минимальное расстояние
    int v[SIZE]; // посещенные вершины
    int temp, minIndex, min;
    int begin_index = 0;
    system("chcp 65001");
    system("cls");
    // Инициализация матрицы связей
    for (int i = 0; i < SIZE; i++) {
        a[i][i] = 0;
        for (int j = i + 1; j < SIZE; j++) {
            printf("Введите расстояние %d - %d: ", i + 1, j + 1);
            scanf("%d", &temp);
            a[i][j] = temp;
            a[j][i] = temp;
        }
    }
    // Вывод матрицы связей
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
    //Инициализация вершин и расстояний
    for (int i = 0; i < SIZE; i++) {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
    // Шаг алгоритма
    do {
        minIndex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++) { // Если вершину ещё не обошли и вес меньше min
            if ((v[i] == 1) && (d[i] < min)) { // Переприсваиваем значения
                min = d[i];
                minIndex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minIndex != 10000) {
            for (int i = 0; i < SIZE; i++) {
                if (a[minIndex][i] > 0) {
                    temp = min + a[minIndex][i];
                    if (temp < d[i]) {
                        d[i] = temp;
                    }
                }
            }
            v[minIndex] = 0;
        }
    } while (minIndex < 10000);
    // Вывод кратчайших расстояний до вершин
    printf("\nКратчайшие расстояния до вершин: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%5d ", d[i]);

    // Восстановление пути
    int ver[SIZE]; // массив посещенных вершин
    int end = 6; // индекс конечной вершины = 7 - 1
    ver[0] = end + 1; // начальный элемент - конечная вершина
    int k = 1; // индекс предыдущей вершины
    int weight = d[end]; // вес конечной вершины

    while (end != begin_index) // пока не дошли до начальной вершины
    {
        for (int i = 0; i < SIZE; i++) // просматриваем все вершины
            if (a[i][end] != 0)   // если связь есть
            {
                int temp = weight - a[i][end]; // определяем вес пути из предыдущей вершины
                if (temp == d[i]) // если вес совпал с рассчитанным
                {                 // значит из этой вершины и был переход
                    weight = temp; // сохраняем новый вес
                    end = i;       // сохраняем предыдущую вершину
                    ver[k] = i + 1; // и записываем ее в массив
                    k++;
                }
            }
    }
    // Вывод пути (начальная вершина оказалась в конце массива из k элементов)
    printf("\nВывод кратчайшего пути\n");
    for (int i = k - 1; i >= 0; i--)
        printf("%3d ", ver[i]);
    getchar();
    getchar();
    return 0;
}

