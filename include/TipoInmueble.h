#ifndef TIPOINMUEBLE_H
#define TIPOINMUEBLE_H

#include <string>

namespace TipoInmuebleenum{
enum TipoInmueble {
    Todos,
    Casa,
    Apartamento
};
std::ostream& operator<<(std::ostream& os, TipoInmueble tipo);
}
#endif