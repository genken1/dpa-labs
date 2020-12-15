#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;
#define V 4
 
// симплекс-метод для решения задачи о коммивояжере
int travllingSalesmanProblem(int graph[][V], int s)
{
    // храним все вершины кроме исходной
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    // храним гамильтонов цикл минимального веса
    int min_path = INT_MAX;
    do {
 
        // сохранить текущий вес пути
        int current_pathweight = 0;
 
        // вычисляем текущий вес пути
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // обновляем минимум
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
 
int main()
{
    // матричное представление графа
    int graph[][V] = { { 0, 11, 31, 3 },
                       { 11, 0, 48, 25 },
                       { 31, 48, 0, 54 },
                       { 3, 25, 54, 0 } };
    int s = 0;
    // ответ: 107
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}
