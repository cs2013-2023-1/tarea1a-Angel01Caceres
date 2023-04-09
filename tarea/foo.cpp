#include "foo.h"

void matriz(float** ptr,filas,columnas) {
    ptr = new float*[filas]
    for (int i = 0; i < filas; i++)
        ptr[i] = new float[columnas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; i < columnas; i++)
            ptr[i][j] = (rand() % 100)/100;
    }
}

Matriz2D::Matriz2D(){
    // Constructor por defecto
    filas = columnas = 3;
    matriz(ptr,filas,columnas);
}

Matriz2D::Matriz2D(int n) {
    // Constructor con un parametro
    filas = columnas = n;
    matriz(ptr,filas,columnas);
}

Matriz2D::Matriz2D(int n, int m) {
    // Constructor con dos parametros
    filas = n; columnas = m;
    matriz(ptr,filas,columnas);
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    this->filas = m.filas;
    this->columnas = m.columnas;
    ptr = new float*[filas];
    for (int i = 0; i < filas; i++)
        ptr[i] = new float[columnas];
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
    this->filas = m.columnas;
    this->columnas = m.filas;
    ptr = new float*[filas];
    for (int i = 0; i < filas; i++)
        ptr[i] = new float[columnas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; i < columnas; i++)
            ptr[i][j] = m.ptr[j][i];
    }
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
