//
// Created by darau on 19/10/25.
//

#include "libro.h"
Libro::Libro(std::string titulo, std::string autor, std::string isbn)
    : titulo(std::move(titulo)), autor(std::move(autor)), isbn(std::move(isbn)) {}

std::string Libro::get_titulo() const {return titulo;}
std::string Libro::get_autor() const {return autor;}
std::string Libro::get_isbn() const {return isbn;}

void Libro::set_titulo(const std::string &titulo) {this->titulo = titulo;}
void Libro::set_autor(const std::string &autor) {this->autor = autor;}
void Libro::set_isbn(const std::string &isbn) {this->isbn = isbn;}

