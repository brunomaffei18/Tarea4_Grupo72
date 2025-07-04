#ifndef ICONTROLADORUSUARIO_H 
#define ICONTROLADORUSUARIO_H

#include <string>
#include <set>
#include "../include/DTUsuario.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/Inmobiliaria.h"
#include "TipoTecho.h"

#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include"../include/DTInmuebleListado.h"

class IControladorUsuario
{
    public:
    virtual DTUsuario getUsuario(std::string nickname)=0;
    virtual bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string apellido, std::string documento)=0;
    virtual bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion,std::string url, std::string telefono)=0;
    virtual bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria,std::string telefono)=0;
    virtual std::set<DTInmuebleAdministrado>listarInmueblesAdministrados(std::string nicknameInmobiliaria)=0;
    virtual std::set<DTUsuario> ListarInmobiliarias()=0;
    virtual std::set<DTUsuario> ListarPropietarios()=0;
    virtual std::set<DTUsuario> ListarClientes()=0;
    virtual void representarPropietario(std::string nicknamePropietario)=0;
    virtual void finalizarAltaUsuario()=0;
    //virtual bool existeUsuario(std::string nickname)=0;   no esta implementada en ControladorUsuario.h
    virtual ~IControladorUsuario()=default;

    virtual std:: set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria)=0;
    virtual void altaAdministrarPropiedad(std::string nickNameInmobiliaria,int codigoInmueble)=0;

};
#endif