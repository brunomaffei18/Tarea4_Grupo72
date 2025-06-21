#ifndef DTINMUEBLELISTADO_H
#define DTINMUEBLELISTADO_H
#include <string>
#include <iostream>
#include <map>


class DTInmuebleListado {
    private:
        int codigo;
        std::string direccion;
        std::string propietario;

    public:
        DTInmuebleListado(int codigo, std::string direccion, std::string propietario);
        int getCodigo();
        std::string getDireccion();
        std::string getPropietario();
        
        bool operator<(const DTInmuebleListado& inmuebleB) const;
};
 std::ostream& operator<<(std::ostream& os,  DTInmuebleListado dt);
#endif