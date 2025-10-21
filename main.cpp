#include "ListaSimple.h"
#include "libro.h"

#include <iostream>

int main() {
    // ------------------------------------------------------------------
    // 1. CREACIÓN DE OBJETOS
    // En C++, debes usar 'new' para crear objetos que serán manejados
    // por la lista. La ListaSimple es responsable de eliminarlos después.
    // ------------------------------------------------------------------
    Libro* libro1 = new Libro("mate", "Juan", "123B");
    Libro* libro2 = new Libro("comp", "Tere", "393A");
    Libro* libro3 = new Libro("hist", "Ana", "000C");

    // 2. CREACIÓN DE LA LISTA
    ListaSimple listaLibro;

    // 3. OPERACIONES DE INSERCIÓN
    std::cout << "--- INSERCIONES ---\n";
    listaLibro.insertarPrincipal(libro1); // Lista: [mate]
    std::cout << "Insertado 'mate'. Count: " << listaLibro.contar() << "\n";

    listaLibro.insertarPrincipal(libro2); // Lista: [comp, mate]
    std::cout << "Insertado 'comp'. Count: " << listaLibro.contar() << "\n";

    // Insertar libro3 (hist) despues de la posicion 0 (es decir, en la posicion 1)
    // Lista: [comp, hist, mate]
    listaLibro.insertarDespues(0, libro3);
    std::cout << "Insertado 'hist' despues de 0. Count: " << listaLibro.contar() << "\n";


    // 4. OPERACIONES DE CONSULTA
    std::cout << "\n--- CONSULTA ---\n";

    // Obtener y usar el libro en la posición 0 ("comp" o el que esté allí)
    Libro* libro_obtenido = listaLibro.obtener(0);
    if (libro_obtenido != nullptr) {
        // CORRECCIÓN: Usar get_titulo()
        std::cout << "Libro en posicion 0 (Título): " << libro_obtenido->get_titulo() << "\n";
        // CORRECCIÓN: Usar get_autor()
        std::cout << "Autor: " << libro_obtenido->get_autor() << "\n";
    }
    // ...

    // 5. OPERACIONES DE ELIMINACIÓN
    std::cout << "\n--- ELIMINACIÓN ---\n";

    // Eliminar el último ("mate")
    listaLibro.eliminarUltimo();
    std::cout << "Eliminado el último. Count: " << listaLibro.contar() << "\n"; // Lista: [comp, hist]

    // Eliminar el de la posición 0 ("comp")
    listaLibro.eliminarPrincipal();
    std::cout << "Eliminado el principal. Count: " << listaLibro.contar() << "\n"; // Lista: [hist]

    // Al final de 'main', el objeto 'listaLibro' se destruye,
    // y su destructor (~ListaSimple) libera automáticamente
    // la memoria del último nodo ("hist") y su objeto Libro.

    return 0;
}