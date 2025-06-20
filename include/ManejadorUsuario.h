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
        static ManejadorUsuario* instancia;
        std::map<std::string, Usuario*> usuarios;
        std::map<std::string, Cliente*> clientes;
        std::map<std::string, Propietario*> propietarios;
        std::map<std::string, Inmobiliaria*> Inmobiliarias;   
        ManejadorUsuario();
    public:
        static ManejadorUsuario* getManejadorUsuario();
        std::map<std::string,Propietario*>& getPropietarios();
        //void altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string apellido, std::string documento);
        //void altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion,std::string url, std::string telefono);
        //void altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria,std::string telefono);
        void agregarUsuario(Usuario* usuario);
        void liberarUsuario(Usuario* usuario);
        void eliminarUsuario(std::string nickname);
        Propietario* getPropietario(std::string nickname);
        Cliente* getCliente(std::string nickname);
        Usuario* getUsuario(std::string nickname);
        Inmobiliaria* getInmobiliaria(std::string nickname);
        bool existeUsuario(std::string nickname);
        ~ManejadorUsuario();
};

#endif