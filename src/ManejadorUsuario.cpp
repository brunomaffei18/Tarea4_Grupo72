#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"

ManejadorUsuario* ManejadorUsuario::instancia = nullptr;

ManejadorUsuario* ManejadorUsuario::getManejadorUsuario(){
    if(instancia==nullptr)
        instancia= new ManejadorUsuario();
    return instancia;
}

ManejadorUsuario::ManejadorUsuario(){};

bool ManejadorUsuario::existeUsuario(std::string nickname)
{ 
    return (usuarios.find(nickname) != usuarios.end());
}

Inmobiliaria* ManejadorUsuario::getInmobiliaria(std::string nickname)
{ 
    return Inmobiliarias.at(nickname);
};

Usuario* ManejadorUsuario::getUsuario(std::string nickname)
{ 
    return usuarios.at(nickname);
};

Cliente* ManejadorUsuario::getCliente(std::string nickname)
{ 
    return clientes.at(nickname);
};

Propietario* ManejadorUsuario::getPropietario(std::string nickname)
{ 
    return propietarios.at(nickname);
};

void ManejadorUsuario::liberarUsuario(Usuario* usuario)
{

};

void ManejadorUsuario::eliminarUsuario(std::string nickname)
{
    
};