#ifndef CONTROLADORUSUARIO_H 
#define CONTROLADORUSUARIO_H

#include <string>
#include <set>
#include "DTUsuario.h"
#include "Propietario.h"
#include "Cliente.h"
#include "Inmobiliaria.h"



class ControladorUsuario
{
private:
    static ControladorUsuario* Intancia;
    ControladorUsuario();
public:
   static ControladorUsuario* getInstancia();
     bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string apellido, std::string documento);
        bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion,std::string url, std::string telefono);
        bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria,std::string telefono);
        std::set<DTUsuario*> ListarInmobiliarias();
        std::set<DTUsuario*> ListarPropietarios();
        std::set<DTUsuario*> ListarClientes();
        void representarPropietario(std::string nicknamePropietario);
        void finalizarAltaUsuario();
        DTUsuario getUsuario(std::string nickname);
        
    ~ControladorUsuario();
};







#endif