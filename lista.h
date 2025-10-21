#ifndef LISTA_H
#define LISTA_H

class Libro;

class Lista {
public:
    virtual ~Lista() = default;

    // Nombres ajustados para coincidir con ListaSimple.h
    virtual void insertarPrincipal(Libro* libro) = 0;
    virtual void insertarFinal(Libro* libro) = 0;
    virtual void insertarDespues(int n, Libro* libro) = 0;

    virtual bool estaVacia() const = 0;
    virtual Libro* obtener(int n) const = 0;
    virtual int contar() const = 0;

    virtual void eliminarPrincipal() = 0;
    virtual void eliminarUltimo() = 0;
    virtual void eliminarLibro(int n) = 0;
};

#endif //LISTA_H