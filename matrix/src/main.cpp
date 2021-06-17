#include <iostream>
#include "Matrix.cpp"

using namespace std;

int main()
{
    int n, m, value;
    
    cout << "Введите размер системы:\n";
    cin >> n >> m;
    Matrix<int> matr(n, m);
    
    // Заполнение значениями matr
    for(int i = 0; i < matr.getColumns(); i++)
    {
        for (int j = 0; j < matr.getRows(); j++) {
            cin >> value;
            matr.insert(value, i, j);
        }
    }
    
    for (int i = 0; i < matr.getRows(); i++) {
        cin >> value;
        matr.insertB(value, i);
    }
    
    int *result = matr.KramerMethod();
    
    for (int i = 0; i < matr.getRows(); i++) {
        cout << result[i] << " ";
    }

    
    return 0;
}
