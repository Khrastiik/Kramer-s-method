//
//  Matrix.hpp
//  matrix
//
//  Created by Khrastiik on 17.06.2021.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <cmath>
#include <iostream>

template <class T>
class Matrix
{
private:
    // Матрица коэффициентов системы
    T** ptr;
    // Матрица-столбец свободных членов
    T* B;
    // Количество столбцов(n) строк(m)
    unsigned int n, m;
    
    // Нахождение определителя
    T determinant(T** ptr, unsigned int n) const;
public:
    // Конструктор
    Matrix();
    // Конструктор с двумя параметрами
    Matrix(const unsigned int n, const unsigned int m);
    // Конструктор копирование
    Matrix(const Matrix<T>& matrix);
    // Деструктор
    ~Matrix();
    
    // Вставка значений
    void insert(T value, const unsigned int n, const unsigned int m) const;
    
    // Вставка значений "B"
    void insertB(T value, const unsigned int n) const;
    
    // Количество столбцов матрицы (n)
    unsigned int getColumns() const;
    // Количество строк матрица (m)
    unsigned int getRows() const;
    // Получить элемент
    T getElem(const unsigned int n, const unsigned int m) const;
    
    // Получить элемент
    T getElemB(const unsigned int n) const;

    // Нахождение определителя
    T determinant() const;
    
    // Метод крамера
    T* KramerMethod() const;

};

#endif /* Matrix_hpp */
