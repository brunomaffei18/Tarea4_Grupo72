#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/Usuario.h"
#include <map>
#include <string>

class ManejadorUsuario {
    private:
        std::map<std::string, DTUsuario*> usuarios;

    public:
        void altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string apellido, std::string documento);
        void altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion,std::string url, std::string telefono);
        void altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria,std::string telefono);
        void liberarCliente(Cliente cliente);
        void eliminarUsuario(std::string nickname);
       
        ~ManejadorUsuario();
};

#endif