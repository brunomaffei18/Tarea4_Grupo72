#ifndef TIPOPUBLICACION_H
#define TIPOPUBLICACION_H

#include <string>

enum TipoPublicacion {
    Venta,
    Alquiler
};
std::ostream& operator<<(std::ostream& os, TipoPublicacion tipo);
#endif