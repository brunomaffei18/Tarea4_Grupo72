#ifndef CONTROLADORUSUARIO_H 
#define CONTROLADORUSUARIO_H

#include <string>
#include <set>
#include "../include/DTUsuario.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/Inmobiliaria.h"
#include "../include/IControladorUsuario.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/ManejadorUsuario.h"



class ControladorUsuario : public IControladorUsuario
{
private:
    static ControladorUsuario* instancia;
    ControladorUsuario();
    ManejadorUsuario* manejadorusu;
    Inmobiliaria* ultimaInmobiliaria;
public:
        static ControladorUsuario* getInstancia();
        bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string apellido, std::string documento);
        bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion,std::string url, std::string telefono);
        bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria,std::string telefono);
        std::set<DTInmuebleAdministrado> listarInmueblesAdministrados(std::string nicknameInmobiliaria);
        std::set<DTUsuario> ListarInmobiliarias();
        std::set<DTUsuario> ListarPropietarios();
        std::set<DTUsuario> ListarClientes();
        void representarPropietario(std::string nicknamePropietario);//fijarse contrato
        void finalizarAltaUsuario();
        DTUsuario getUsuario(std::string nickname);
        Inmobiliaria* getUltimaInmobiliaria();
        void finalizarAltaCliente(); //consulta profe
        
        std:: set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria);
        void altaAdministrarPropiedad(std::string nickNameInmobiliaria,int codigoInmueble);
        
    ~ControladorUsuario();
};


#endif