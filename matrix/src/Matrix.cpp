//
//  Matrix.cpp
//  matrix
//
//  Created by Khrastiik on 17.06.2021.
//

#include "Matrix.hpp"

// Конструктор
template <class T>
Matrix<T>::Matrix()
{
    n = 0;
    m = 0;
    ptr = nullptr;
    
    B = new T[m];
}

// Конструктор с двумя параметрами
template <class T>
Matrix<T>::Matrix(const unsigned int n, const unsigned int m)
{
    this->n = n;
    this->m = m;

    ptr = new T*[m];

    for (int i = 0; i < m; i++)
        ptr[i] = new T[n];

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        ptr[i][j] = 0;
    
    B = new T[m];
}

// Конструктор копирование
template <class T>
Matrix<T>::Matrix(const Matrix<T>& matrix)
{
    n = matrix.n;
    m = matrix.m;
    
    B = new T[matrix.m];

    ptr = new T * [n];
    for (unsigned int i = 0; i < n; i++)
        ptr[i] = new T[m];

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++)
            ptr[i][j] = matrix.ptr[i][j];
    }
    
    for (unsigned int i = 0; i < m; i++)
        B[i] = matrix.B[i];
    
}

// Деструктор
template <class T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < n; i++)
        delete[] ptr[i];
    delete[] ptr;
    
    delete[] B;
}

// Вставка значений
template <class T>
void Matrix<T>::insert(T value, const unsigned int n, const unsigned int m) const
{
    ptr[n][m] = value;
}

// Вставка значений "B"
template <class T>
void Matrix<T>::insertB(T value, const unsigned int n) const
{
    B[n] = value;
}

// Количество столбцов матрицы
template <class T>
unsigned int Matrix<T>::getColumns() const
{
    return n;
}

// Количество строк матрицы
template <class T>
unsigned int Matrix<T>::getRows() const
{
    return m;
}

// Получить элемент
template <class T>
T Matrix<T>::getElem(const unsigned int n, const unsigned int m) const
{
    return ptr[n][m];
}

// Получить элемент
template <class T>
T Matrix<T>::getElemB(const unsigned int n) const
{
    return B[n];
}

template <class T>
T Matrix<T>::determinant() const
{
    return determinant(ptr, n);
}

// TODO: Есть утечка памяти. Написать освобождение динамического массива
template <class T>
T Matrix<T>::determinant(T** ptr, unsigned int n) const
{
    if (n == 1)
        return ptr[0][0];
    else if (n == 2)
        return ptr[0][0] * ptr[1][1] - ptr[0][1] * ptr[1][0];
    else {
        int deter = 0;
        for (int k = 0; k < n; k++) {
            T** m = new T*[n-1];
            
            for (int i = 0; i < n - 1; i++)
                m[i] = new T[n - 1];
            
            for (int i = 1; i < n; i++) {
                int t = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    
                    m[i-1][t] = ptr[i][j];
                    t++;
                }
            }
            
            deter += pow(-1, k + 2) * ptr[0][k] * determinant(m, n - 1);
        }
        
        return deter;
    }
}

// TODO: Есть утечка памяти. Написать освобождение динамического массива
template<class T>
T* Matrix<T>::KramerMethod() const {
    T delta = determinant();
    
    T* result = new T[m];
    
    Matrix<T> matrCopy(*this);
    
    T* tmpRow = new T[n];
    
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < m; j++) {
            tmpRow[j] = matrCopy.getElem(j, i);
            matrCopy.insert(B[j], j, i);
        }
        
        result[i] = matrCopy.determinant() / delta;
        
        for (int j = 0; j < m; j++)
            matrCopy.insert(tmpRow[j], j, i);
        
    }

    return result;
}
