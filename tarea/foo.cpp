#include "foo.h"

float** matriz(int filas,int columnas) {
    float** ptr = new float*[filas];
    for (int i = 0; i < filas; i++)
        ptr[i] = new float[columnas];
    return ptr;
}

Matriz2D::Matriz2D(){
    // Constructor por defecto
    filas = columnas = 3;
    ptr = matriz(filas,columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; i < columnas; i++)
            ptr[i][j] = (rand() % 100)/100;
    }
}

Matriz2D::Matriz2D(int n) {
    // Constructor con un parametro
    filas = columnas = n;
    ptr = matriz(filas,columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; i < columnas; i++)
            ptr[i][j] = (rand() % 100)/100;
    }
}

Matriz2D::Matriz2D(int n, int m) {
    // Constructor con dos parametros
    filas = n; columnas = m;
    ptr = matriz(filas,columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; i < columnas; i++)
            ptr[i][j] = (rand() % 100)/100;
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    this->filas = m.filas;
    this->columnas = m.columnas;
    ptr = matriz(filas,columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; i < columnas; i++)
            ptr[i][j] = m.ptr[i][j];
    }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    this->filas = m.filas;
    this->columnas = m.columnas;
    ptr = m.ptr;
    m.ptr = nullptr;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    float** ptr1 = m.ptr;
    m.ptr = nullptr;
    m.ptr = matriz(m.columnas,m.filas);
    for (int i = 0; i < m.columnas; i++) {
        for (int j = 0; i < m.filas; i++)
            m.ptr[i][j] = ptr1[i][j];
    }
    float cantidad = m.filas;
    m.filas = m.columnas;
    m.columnas = cantidad;
    Matriz2D m1 = move(m);
    m.ptr = ptr1;
    ptr1 = nullptr;
    cantidad = m.filas;
    m.filas = m.columnas;
    m.columnas = cantidad;
    return m1;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
