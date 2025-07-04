#ifndef DTFECHA
#define DTFECHA

#include <string>
#include <iostream>

class DTFecha {
    private:
        int dia;
        int mes;
        int anio;
    public:
        DTFecha();
        DTFecha(int dia, int mes, int anio);
        DTFecha(DTFecha* fecha);
        bool operator>=(DTFecha* fecha);
        bool operator<(DTFecha* fecha);
        bool operator==(DTFecha* fecha);
        std::string toString();
        bool operator==(const DTFecha& other) const ;
};
std::ostream& operator<<(std::ostream& os, DTFecha* fecha);

#endif
