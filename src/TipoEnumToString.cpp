#include <iostream>
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"

std::ostream& operator<<(std::ostream& os, TipoPublicacion tipo) {
    switch (tipo) {
        case TipoPublicacion::Venta: os << "Venta"; break;
        case TipoPublicacion::Alquiler: os << "Alquiler"; break;
        default: os << "Desconocido"; break;
    }
    return os;
}

namespace TipoInmuebleenum {
    std::ostream& operator<<(std::ostream& os, TipoInmueble tipo) {
        switch (tipo) {
            case TipoInmueble::Casa: os << "Casa"; break;
            case TipoInmueble::Apartamento: os << "Apartamento"; break;
            case TipoInmueble::Todos: os << "Todos"; break;
            default: os << "Desconocido"; break;
        }
        return os;
    }
}
