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
        for (int j = 0; j < columnas; j++)
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

Matriz2D::Matriz2D(int filas,int columnas,float** ptr){
    // Constructor por elementos
    this->filas = filas;
    this->columnas = columnas;
    this->ptr = ptr;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    float** ptr = matriz(m.columnas,m.filas);
    for (int i = 0; i < m.columnas; i++) {
        for (int j = 0; j < m.filas; j++)
            ptr[i][j] = m.ptr[i][j];
    }
    Matriz2D mt(m.columnas,m.filas,ptr);
    return mt;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++)
            os << m.ptr[i][j] << ' ';
        os << endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    float** ptr = matriz(m1.filas,m1.columnas);
    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m1.columnas; j++)
            ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
    }
    Matriz2D ms(m1.filas,m2.columnas,ptr);
    return ms;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    float** ptr = matriz(m1.filas,m1.columnas);
    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m1.columnas; j++)
            ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
    }
    Matriz2D mr(m2.filas,m1.columnas,ptr);
    return mr;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    float** ptr = matriz(m1.filas,m2.columnas);
    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m2.columnas; j++) { 
            ptr[i][j] = 0;
            for (int k = 0; k < m1.columnas; k++)
                ptr[i][j] += m1.ptr[i][k] * m2.ptr[k][j]; 
        }
    }
    Matriz2D mm(m1.filas,m2.columnas,ptr);
    return mm;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    float** ptr = matriz(m.filas,m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++)
            ptr[i][j] = m.ptr[i][j] + n;
    }
    Matriz2D mse(m.filas,m.columnas,ptr);
    return mse;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    float** ptr = matriz(m.filas,m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++)
            ptr[i][j] = m.ptr[i][j] - n;
    }
    Matriz2D mre(m.filas,m.columnas,ptr);
    return mre;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    float** ptr = matriz(m.filas,m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++)
            ptr[i][j] = m.ptr[i][j] * n;
    }
    Matriz2D mme(m.filas,m.columnas,ptr);
    return mme;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    float** ptr = matriz(m.filas,m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++)
            ptr[i][j] = m.ptr[i][j] / n;
    }
    Matriz2D mde(m.filas,m.columnas,ptr);
    return mde;
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
