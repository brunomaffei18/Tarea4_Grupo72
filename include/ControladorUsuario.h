#ifndef CONTROLADORUSUARIO_H 
#define CONTROLADORUSUARIO_H

#include <string>
#include <set>
#include "../include/DTUsuario.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/Inmobiliaria.h"
#include "../include/IControladorUsuario.h"



class ControladorUsuario : public IControladorUsuario
{
private:
    static ControladorUsuario* Intancia;
    ControladorUsuario();
public:
   static ControladorUsuario* getInstancia();
     bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string apellido, std::string documento);
        bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion,std::string url, std::string telefono);
        bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria,std::string telefono);
        void altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo);
        void altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);
        std::set<DTUsuario*> ListarInmobiliarias();
        std::set<DTUsuario*> ListarPropietarios();
        std::set<DTUsuario*> ListarClientes();
        void representarPropietario(std::string nicknamePropietario);
        void finalizarAltaUsuario();
        DTUsuario getUsuario(std::string nickname);
        
    ~ControladorUsuario();
};


#endif