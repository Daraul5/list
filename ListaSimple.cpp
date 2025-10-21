#include "ListaSimple.h"
#include <iostream>

// ---------------------------------------------
// 1. Constructor y Destructor (Gestión de Memoria)
// ---------------------------------------------

// Constructor: Inicializa la lista vacía
ListaSimple::ListaSimple() : cabeza(nullptr), longitud(0) {}

// Destructor: ¡CRÍTICO! Recorre todos los nodos y los elimina.
ListaSimple::~ListaSimple() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        
        // 'delete actual' llama al destructor del Nodo, que a su vez llama a 
        // 'delete libro', liberando la memoria del Libro y luego del Nodo.
        delete actual; 
        
        actual = siguiente;
    }
    cabeza = nullptr; 
    longitud = 0;
}

// ---------------------------------------------
// 2. Métodos de Inserción
// ---------------------------------------------

void ListaSimple::insertarPrincipal(Libro* libro) {
    // 1. Crea un nuevo nodo en el heap (memoria dinámica)
    Nodo* nuevo_nodo = new Nodo(libro); 
    
    // 2. El nuevo nodo apunta a la cabeza actual
    nuevo_nodo->siguiente = cabeza;
    
    // 3. El nuevo nodo se convierte en la nueva cabeza
    cabeza = nuevo_nodo;
    longitud++;
}

void ListaSimple::insertarFinal(Libro* libro) {
    Nodo* nuevo_nodo = new Nodo(libro);
    
    if (cabeza == nullptr) {
        cabeza = nuevo_nodo;
    } else {
        Nodo* puntero = cabeza;
        // Recorre hasta encontrar el último nodo (aquel cuyo 'siguiente' es nullptr)
        while (puntero->siguiente != nullptr) {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nuevo_nodo;
    }
    longitud++;
}

void ListaSimple::insertarDespues(int n, Libro* libro) {
    if (n < 0 || n >= longitud) {
        // Opción: Si el índice es inválido (excepto si n=longitud-1, que es insertarFinal)
        if (n == longitud) {
             insertarFinal(libro);
             return;
        }
        return; 
    }

    Nodo* puntero = cabeza;
    // Puntero se detiene en el nodo en la posición 'n' (después del cual se insertará)
    for (int i = 0; i < n; ++i) {
        puntero = puntero->siguiente;
    }
    
    Nodo* nuevo_nodo = new Nodo(libro);
    
    // Enganche el nuevo nodo entre 'puntero' y 'puntero->siguiente'
    nuevo_nodo->siguiente = puntero->siguiente;
    puntero->siguiente = nuevo_nodo;
    longitud++;
}

// ---------------------------------------------
// 3. Métodos de Consulta
// ---------------------------------------------

bool ListaSimple::estaVacia() const {
    return cabeza == nullptr;
}

int ListaSimple::contar() const {
    return longitud;
}

Libro* ListaSimple::obtener(int n) const {
    if (n < 0 || n >= longitud || cabeza == nullptr) {
        return nullptr;
    }
    
    Nodo* puntero = cabeza;
    for (int i = 0; i < n; ++i) {
        puntero = puntero->siguiente;
    }
    // Devuelve el puntero al objeto Libro
    return puntero->libro;
}

// ---------------------------------------------
// 4. Métodos de Eliminación
// ---------------------------------------------

void ListaSimple::eliminarPrincipal() {
    if (cabeza != nullptr) {
        Nodo* a_eliminar = cabeza;
        cabeza = cabeza->siguiente;
        delete a_eliminar; // Libera el nodo y el libro
        longitud--;
    }
}

void ListaSimple::eliminarUltimo() {
    if (cabeza == nullptr) return;

    if (cabeza->siguiente == nullptr) {
        // Solo hay un nodo
        delete cabeza;
        cabeza = nullptr;
        longitud = 0;
        return;
    }

    Nodo* puntero = cabeza;
    // Recorre hasta el nodo *penúltimo*
    while (puntero->siguiente->siguiente != nullptr) {
        puntero = puntero->siguiente;
    }
    
    delete puntero->siguiente; // Libera el último nodo y su libro
    puntero->siguiente = nullptr;
    longitud--;
}

void ListaSimple::eliminarLibro(int n) {
    if (cabeza == nullptr || n < 0 || n >= longitud) return;

    if (n == 0) {
        eliminarPrincipal();
        return;
    }

    // Puntero se mueve hasta el nodo (n-1)
    Nodo* puntero = cabeza;
    for (int i = 0; i < n - 1; ++i) {
        puntero = puntero->siguiente;
    }

    Nodo* a_eliminar = puntero->siguiente;
    puntero->siguiente = a_eliminar->siguiente;
    
    delete a_eliminar; // Libera el nodo y el libro
    longitud--;
}