#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "libro.h"
#include "lista.h"


class ListaSimple : public Lista
{
private:
    class Nodo {
    public:
        Libro *libro;
        Nodo *siguiente;
        Nodo(Libro *l) : libro(l), siguiente(nullptr) {}

        ~Nodo() {
            delete libro;
        }

    };
    Nodo *cabeza;
    int longitud;
public:
    ListaSimple();
    ~ListaSimple() override;

    // Métodos de Inserción
    void insertarPrincipal(Libro* libro) override;
    void insertarFinal(Libro* libro) override;
    void insertarDespues(int n, Libro *libro) override;

    // Métodos de Consulta
    bool estaVacia() const override;
    Libro *obtener(int n) const override;
    int contar() const override;

    // Métodos de Eliminación
    void eliminarPrincipal() override;
    void eliminarUltimo() override;
    void eliminarLibro(int n) override;

};


#endif //LISTASIMPLE_H