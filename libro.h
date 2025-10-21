//
// Created by darau on 19/10/25.
//

#ifndef LIBRO_H
#define LIBRO_H
#include <string>


class Libro
{
    private:
        std::string titulo;
        std::string autor;
        std::string isbn;

    public:
        Libro(std::string titulo, std::string autor, std::string isbn);

        [[nodiscard]]std::string get_titulo() const;
        [[nodiscard]]std::string get_autor() const;
        [[nodiscard]]std::string get_isbn() const;

        void set_titulo(const std::string &titulo);
        void set_autor(const std::string &autor);
        void set_isbn(const std::string &isbn);
};


#endif //LIBRO_H