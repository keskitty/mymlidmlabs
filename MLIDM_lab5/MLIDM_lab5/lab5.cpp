#include <iostream>
#include <locale.h>
#include <vector>

#define endl "\n"
#define PAIR 2

using namespace std;

bool graph[1000][1000] = { false };

void InputMatrSM(vector<vector<bool>>& graph)
{
    cout << "Введите матрицу смежности: " << endl;
    
    for (int i = 0; i < graph.size(); i++)
    {
        int elem = 0;
        for (int j = 0; j < graph.size(); j++)
        {
            cin >> elem;
            graph[i][j] = (elem == 1 ? true : false);
        }
    }
    cout << endl;
}

void OutputMatrSM(vector<vector<bool>>& graph)
{
    cout << "Ваша матрица смежности: " << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            cout << (graph[i][j] == true ? '1' : '0') << " ";
        }
        cout << endl;
    }
}

void FindMatrRelease(vector<vector<bool>>& matrixrel)
{
    for (int k = 0; k < matrixrel.size(); k++)
    {
        for (int i = 0; i < matrixrel.size(); i++)
        {
            for (int j = 0; j < matrixrel.size(); j++)
            {
                matrixrel[i][j] = matrixrel[i][j] || (matrixrel[i][k] && matrixrel[k][j]);
            }
        }
    }

}

void OutputMatrRL(vector<vector<bool>>& matrixrel)
{
    cout << "Ваша матрица достижимости: " << endl;
    for (int i = 0; i < matrixrel.size(); i++)
    {
        for (int j = 0; j < matrixrel.size(); j++)
        {
            cout << (matrixrel[i][j] == true ? '1' : '0') << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int cnttop;
    cout << "Введите количество вершин: ";
    cin >> cnttop;
    cout << endl;
    vector<vector<bool>> graph(cnttop, vector<bool>(cnttop));

    InputMatrSM(graph);

    vector<vector<bool>> matrixrel(cnttop, vector<bool>(cnttop));
    matrixrel = graph;
    FindMatrRelease(matrixrel);
    OutputMatrSM(graph);
    OutputMatrRL(matrixrel);
    return 0;

}