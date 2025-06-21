#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <string>
#include <iostream>

class DTUsuario {
    private:
        std::string nickname;
        std::string nombre;

    public:
        DTUsuario(std::string nickname, std::string nombre);
        std::string getNickname();
        std::string getNombre();
        bool operator<(const DTUsuario& other) const;
};

std::ostream& operator<<(std::ostream& os, DTUsuario& dt);

#endif